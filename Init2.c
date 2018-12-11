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


void Init2()
{
   initscr(); //Start curses mode
   cbreak(); //When CBREAK is on, input from reading is immediately available in the program.
   noecho(); //Suppress echo
   curs_set(0);
   srand(time(0));

/*
   for(i = 5 ; i <= 13 ; i++)
   {
     move(9,i);
     addch('#');
   }
   for(i = 14 ; i <= 24 ; i++)
   {
     move(14,i);
     addch('#');
   }
   for(i = 28 ; i <= 32; i++)
   {
     move(i,21);
     addch('#');
   }
   for(i = 10 ; i<= 13; i++)
   {
     move(i,37);
     addch('#');
   }*/

   int i,xa,ya;
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

   for(i = 0 ; i < 30; i++)
   {
     do
     {
       xa = rand() % 80;
       ya = rand() % 24;
       move(ya,xa);
       addch('#');
     }
     while(((char)inch()) == '#');
   }



 do
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

