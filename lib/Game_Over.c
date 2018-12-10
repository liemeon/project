#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>
#include "Game_Over.h"

int Game_Over()
{
   sleep(1);
   endwin();
   exit(0);
}
