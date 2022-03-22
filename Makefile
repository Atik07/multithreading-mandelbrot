
all: sln/mandel sln/exp

sln/mandel: sln/mandel.o sln/bitmap.o
	gcc sln/mandel.o sln/bitmap.o -o sln/mandel -lpthread

sln/exp: sln/exp.o
	gcc sln/exp.o -o sln/exp -lpthread

sln/mandel.o: src/mandel.c
	gcc -Wall -g -c src/mandel.c -o sln/mandel.o

sln/bitmap.o: src/bitmap.c
	gcc -Wall -g -c src/bitmap.c -o sln/bitmap.o

sln/exp.o: src/exp.c
	gcc -Wall -g -c src/exp.c -o sln/exp.o

clean:
	rm -f sln/mandel.o sln/bitmap.o sln/mandel sln/exp.o sln/exp
