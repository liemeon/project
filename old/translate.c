#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) // need argument!! Makefile fix need
{
  if(argc != 3)
  {
    printf("translate original_file_name newfile_name\n");
    exit(0);
  }
  if() //origin txt file exist check
  {
    printf("origin file is not exist\n");
    exit(0);
  }
  /*  translate version  1
    system("");
  */

  /* translate version 2 */
  fd1 = open(argv[1],O_RDONLY);
  fd2 = open(argv[2],O_WRONLY|O_CREAT,0666);

  while( nb = read(fd1,buffer,1024))
  {
    write(fd2,buffer,nb);
  }
  close(fd1);
  close(fd2);
  return 0;
}
