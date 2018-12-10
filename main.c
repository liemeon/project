#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <curses.h>
#include <stdlib.h>
#include <sys/time.h>

// we need lib

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

  if(head->x > 79) //size of x
     head->x = 0;

  if(head->x < 0)
     head->x = 79; //size of x

  if(head->y > 23) //size of y
     head->y = 0;

  if(head->y < 0)
     head->y = 23; //size of y
  // maybe don't have to add {} cause for readability.

  move(head->y, head->x);

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
    head = tmp;
    do
    {
      food.x = rand() % 80; //size of x
      food.y = rand() % 24; //size of y
      move(food.y, food.x);
    }
    while(((char)inch()) == '*');
    move(food.y, food.x);
    addch('o');
    refresh();
  }
  move(head->y, head->x);
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

    case ' ': // if user press space key
      set_ticker(0); // pause
      do {
         ch = getch();
      }while(ch != ' '); // if user press next space key
      set_ticker(500); // restart
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
   set_ticker(500);
   Snake_Move();
}


int main()
{
   char ch;

   Init();

   signal(SIGALRM, sig_alrm);

   set_ticker(500);

   while(1) {
     key_ctl();
   }
   endwin();
   return 0;
}
