#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <time.h>

typedef struct stat* sp;

//puts the digits of n in buffer, but in reverse order
//returns location of highest digit in binary number
int* toBinary(int n, int* buffer)
{
	int* loc = buffer;
	while(n)
	{
		*(loc) = n%2;
		n/=2;
		loc++;
	}
	return loc;
}

int main(){

  sp filestat = (sp)malloc(sizeof(sp));
  stat("file.txt", filestat);
  printf("size: %lld B\n", filestat->st_size);
  printf("mode: %o\n", filestat->st_mode);
  printf("last access: %s\n", ctime(&(filestat->st_atim.tv_sec)));

  int* buffer = malloc(20 * sizeof(int));
  int* lastPointer = toBinary(filestat->st_mode, buffer);

  while(lastPointer >= buffer)
  {
  	printf("%d", *(lastPointer));
  	lastPointer--;
  }
  printf("\n");


  return 0;
}
