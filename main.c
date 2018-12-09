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
