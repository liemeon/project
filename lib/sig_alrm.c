#include <unistd.h>
#include <signal.h>
#include <sys/time.h>
#include "sig_alrm.h"

void sig_alrm(int singo)
{
   set_ticker(500);
   Snake_Move();
}
