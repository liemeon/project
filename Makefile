myapp: libfuncs.a
	gcc main.c -L. -lfuncs -o myapp -lncurses

libfuncs.a: Game_Over.o Init.o
	ar rv libfuncs.a Game_Over.o Init.o

%.o: %.c
	gcc -c -lncurses $^

clean:
	rm -f *.o libfuncs.a myapp
