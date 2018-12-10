#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <curses.h>
#include <stdlib.h>
#include <sys/time.h>
#include "key_ctl.h"

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
