# Mandelbrot (multithreaded rendering)

## compile and run

```bash
# compile
make

# run-mandel
# Single-thread
./sln/mandel -x -1.436 -y 0 -W 2400 -H 2400 -s 1 -m 100 -o ./output/output.bmp

# Multi-thread
./sln/mandel -x -1.436 -y 0 -W 2400 -H 2400 -s 1 -m 100 -n 4 -o ./output/output_mt.bmp

# run-given-experiments
./sln/exp

# delete-solution-files
make clean
```

## mandel.c

mandel.c has been modified to implement multi-threading.

## exp.c

exp.c has been created to run the given experiments
