#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
  if(argc != 3)
  {
    printf("translate original_file_name newfile_name\n");
    exit(0);
  }
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
