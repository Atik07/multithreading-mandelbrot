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
    int t_count[EXP_THREADS] = {1, 2, 3, 4, 5, 10, 50};
    int t_count_size = EXP_THREADS;

    int reps = REPETITIONS;

    char *exec_path = (char *)"../src/mandel";

    struct coordinates e2_c;
    e2_c.x = "0.2869325";
    e2_c.y = "0.0142905";
    char *e2_scale = ".000001";
    char *e2_W = "1024";
    char *e2_H = "1024";
    char *e2_max_iter = "1000";
    char e2_out_path[100];

    // char e2_arg_str[200];
    sprintf(e2_out_path,"../output/e2/%d.bmp",1);

    char *e2_args[] = {exec_path, "-x",e2_c.x,"-y",e2_c.y,"-s",e2_scale,"-W",e2_W,"-H",e2_H,"-m",e2_max_iter,"-o",e2_out_path,(char *)NULL};
    // printf("%s\n",e2_args[0]);
    // printf("%s\n",e2_args[1]);
    // execl(exec_path, e2_arg_str, (char*)NULL);
    execvp(exec_path, e2_args);

    return 0;

}
