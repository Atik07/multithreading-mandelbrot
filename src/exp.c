#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>
#include <string.h>

#define REPETITIONS 10
#define EXP_THREADS 7

struct coordinates
{
    char *x;
    char *y;
};

int main()
{
    char *t_count[EXP_THREADS] = {"1", "2", "3", "4", "5", "10", "4"};
    int t_count_size = EXP_THREADS;

    int reps = REPETITIONS;

    char *exec_path = "./sln/mandel";

    struct coordinates e1_c;
    e1_c.x = "-0.5";
    e1_c.y = "-0.5";
    char *e1_scale = "1";
    char *e1_max_iter = "2000";
    char e1_out_path[100];

    struct coordinates e2_c;
    e2_c.x = "0.2869325";
    e2_c.y = "0.0142905";
    char *e2_scale = ".000001";
    char *e2_W = "1024";
    char *e2_H = "1024";
    char *e2_max_iter = "1000";
    char e2_out_path[100];

    pid_t pid[REPETITIONS];
    int i;

    for (int t = 0; t < t_count_size; t++)
    {

        for (i = 0; i < reps; i++)
        {
            if ((pid[i] = fork()) == 0)
            {
                sprintf(e1_out_path,"./output/e1/%d.bmp",i);
                char *e1_args[] = {exec_path, "-x", e1_c.x, "-y", e1_c.y, "-s", e1_scale, "-m", e1_max_iter, "-o", e1_out_path, "-n" ,t_count[t],(char *)NULL};
                execvp(exec_path, e1_args);

                perror("execvp error");
                _exit(1);
            }
            if (pid[i] < 0)
            {
                perror("fork error");
            }
        }

        for (i = 0; i < reps; i++)
        {
            if (pid[i] > 0)
            {
                int status;

                waitpid(pid[i], &status, 0);
                if (status > 0)
                {
                    // handle a process sent exit status error
                    perror("e1: process sent exit status error");
                }
            }
            else
            {
                // handle a process was not started
                perror("e1: process was not started");
            }
        }

        for (i = 0; i < reps; i++)
        {
            if ((pid[i] = fork()) == 0)
            {
                sprintf(e2_out_path,"./output/e2/%d.bmp",i);
                char *e2_args[] = {exec_path, "-x", e2_c.x, "-y", e2_c.y, "-s", e2_scale, "-W", e2_W, "-H", e2_H, "-m", e2_max_iter, "-o", e2_out_path, "-n" ,t_count[t], (char *)NULL};
                execvp(exec_path, e2_args);

                perror("execvp error");
                _exit(1);
            }
            if (pid[i] < 0)
            {
                perror("fork error");
            }
        }

        for (i = 0; i < reps; i++)
        {
            if (pid[i] > 0)
            {
                int status;

                waitpid(pid[i], &status, 0);
                if (status > 0)
                {
                    // handle a process sent exit status error
                    perror("e2: process sent exit status error");
                }
            }
            else
            {
                // handle a proccess was not started
                perror("e2: process was not started");
            }
        }
    }

    return 0;
}
