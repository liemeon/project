#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <curses.h>
#include <stdlib.h>
#include <sys/time.h>
#include "Init.h"

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


void Init()
{
   initscr(); //Start curses mode
   cbreak(); //When CBREAK is on, input from reading is immediately available in the program.
   noecho(); //Suppress echo
   curs_set(0);
   srand(time(0));

   dir_x = 1;
   dir_y = 0;

   head = (Snake)malloc(sizeof(SNAKE));
   head->x = rand() % 80;
   head->y = rand() % 24;
   head->next = (Snake)malloc(sizeof(SNAKE));
   tail = head->next;
   tail->prev = head;
   tail->x = head->x - dir_x;
   tail->y = head->y - dir_y;

   do
   {
      food.x = rand() % 80;
      food.y = rand() % 24;
      move(food.y, food.x);
   }

   while((char)inch() == '*');
//Once again, how about making it a function and managing it?\
//used sanke_move
   move(head->y, head->x);
   addch('*');
   move(food.y, food.x);
   addch('o');
/*   move(10, 40);
   addch('s');
   move(10, 41);
   addch('t');
   move(10, 42);
   addch('a');
   move(10, 43);
   addch('r');
   move(10, 44);
   addch('t');*/

   refresh(); //print it on real screen
}

