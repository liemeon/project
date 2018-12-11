#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <curses.h>
#include <stdlib.h>
#include <sys/time.h>
#include "Game_Over.h"
#include "Init.h"

typedef struct snake {   //double Linked List

   int x, y;
   struct snake *next, *prev;

}SNAKE, *Snake;


typedef struct food {
   int x, y;
}FOOD, *Food;
int speed = 100;
int a;
int dir_x, dir_y; //variables for setting the x-axis,y-axis direction
Snake head, tail;
FOOD food;

int set_ticker(int n_msec)
{
   struct itimerval timeset;
   long n_sec, n_usec;

   n_sec = n_msec / 1000;
   n_usec = (n_msec % 1000) * 1000L;

   timeset.it_interval.tv_sec = n_sec;
   timeset.it_interval.tv_usec = n_usec;

   timeset.it_value.tv_sec = n_sec;
   timeset.it_value.tv_usec = n_usec;

   return setitimer(ITIMER_REAL, &timeset, NULL);
}

void Snake_Move()
{
   Snake p, tmp;

   for(p = tail; p != head; p = p->prev)
   {
     p->x = p->prev->x;
     p->y = p->prev->y;
   }
   p->x += dir_x;
   p->y += dir_y;

  if(head->x >= 80) //size of x
     Game_Over();

  if(head->x <= 0)
     Game_Over();

  if(head->y >= 80) //size of y
     Game_Over();

  if(head->y <= 0)
     Game_Over();
  // maybe don't have to add {} cause for readability.

  move(head->y, head->x); //The current head contains the current position plus the directional value

  if((char)inch() == '*') //eat it's self
    Game_Over();

  if((char)inch() == 'o') //eat foods
  {
    move(head->y, head->x);
    addch('*');
    refresh();
    tmp = (Snake)malloc(sizeof(SNAKE));
    tmp->x = head->x + dir_x;
    tmp->y = head->y + dir_y;
    tmp->next = head;
    head->prev = tmp;
    head = tmp; //The snake's size is increased by adding it to the head using tmp, since it has been eaten.
    do //food regeneration
    {
      food.x = rand() % 80; //size of x
      food.y = rand() % 24; //size of y
      move(food.y, food.x);
    }
    while(((char)inch()) == '*'); //Check for conflicts between regenerated food and snakes
    move(food.y, food.x);
    addch('o');
    refresh();
  }
  move(head->y, head->x); //Snake position change
  addch('*');
  refresh();
  move(tail->y, tail->x);
  addch(' ');
  refresh();
}

void key_ctl()
{
  int ch = getch(); //read user press key
  switch(ch)
  {
    case 'W':
    case 'w':  // The snake is ready to go up.
      if(dir_x == 0)
        break;
      dir_x = 0;
      dir_y = -1; //The snake is ready to go up.
      break;

    case 'S':
    case 's':
      if(dir_x == 0)
        break;
      dir_x = 0;
      dir_y = 1; //The snake is ready to go up.
      break;

    case 'A':
    case 'a':
      if(dir_y == 0)
        break;
      dir_x = -1;  //The snake is ready to go left.
      dir_y = 0;
      break;

    case 'D':
    case 'd':
      if(dir_y == 0)
        break;
      dir_x = 1;  //The snake is ready to go right.
      dir_y = 0;
      break;

    case 't':
      speed = speed + 200;
      if(speed > 2100) speed = 2100;
      set_ticker(speed);
      break;

    case 'g':
      speed = speed - 200;
      if(speed < 100) speed = 100;
      set_ticker(speed);
      break;


    case ' ': // if user press space key
      set_ticker(0); // pause
      do {
         ch = getch();
      }while(ch != ' '); // if user press next space key
      set_ticker(speed); // restart
      break;

    case 'Q': // it will be more specific
    case 'q':
      Game_Over();
      break;

    default:break;
  }
}

void sig_alrm(int singo)
{
   set_ticker(speed);
   Snake_Move();
}


int main()
{
   char ch;
   signal(SIGALRM, sig_alrm);
   refresh();
   Init();

   set_ticker(0);
      do {
         ch = getch();
      }while(ch != ' ');
      set_ticker(speed);

   set_ticker(speed);

   while(1) {
     key_ctl();
   }
   endwin();
   return 0;
}
