#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <curses.h>
#include <stdlib.h>
#include <sys/time.h>

typedef struct snake {

   int x, y;
   struct snake *next, *prev;

}SNAKE, *Snake;


typedef struct food {
   int x, y;
}FOOD, *Food;

int a;
int dir_x, dir_y;
Snake head, tail;
FOOD food;
