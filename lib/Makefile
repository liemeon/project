myapp: libfuncs.a
	gcc ../main.c -L. -lfuncs -o myapp -lncurses

libfuncs.a: Game_Over.o Init.o
	ar rv libfuncs.a Game_Over.o Init.o

Game_Over.o: Game_Over.c
	gcc -c Game_Over.c -lncurses

Init.o: Init.c
	gcc -c Init.c -lncurses

clean:
	rm -f Init.o Game_Over.o libfuncs.a myapp
