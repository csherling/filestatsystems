#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>

typedef struct stat* sp;

int main(){

  sp filestat = (sp)malloc(sizeof(sp));
  stat("file.txt", filestat);
  printf("size: %lu\n", filestat->st_size);
  printf("mode: %u\n", filestat->st_mode);
  
  return 0;
}
