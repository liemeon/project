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
   head->next = (Snake)malloc(sizeof(SNAKE));
   tail = head->next;
   tail->prev = head;
   tail->x = head->x - dir_x;
   tail->y = head->y - dir_y;
   head->x = rand() % 80;
   head->y = rand() % 24;

 do //food regeneration
    {
      head->x = rand() % 80;
      head->y = rand() % 24;
    }
    while(((char)inch()) == '#');

   do
   {
      food.x = rand() % 80;
      food.y = rand() % 24;
      move(food.y, food.x);
   }

   while(((char)inch() == '@') || ((char)inch() == '#'));
//Once again, how about making it a function and managing it?\
//used sanke_move
   move(head->y, head->x);
   addch('@');
   move(food.y, food.x);
   addch('o');


   refresh(); //print it on real screen
}

