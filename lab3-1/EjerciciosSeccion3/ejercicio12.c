
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
int main(int argc, char **argv)
{
  pid_t pid;
  if ((pid = fork()) == 0) {
        execl(argv[1], 0);
  }
  else if(pid==-1){
      printf("error al crear proceso hijo");

  }
  else {
    wait(&pid);
    printf("programa finalizado\n");
  }
  return 0;
}
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
int main(int argc, char **argv)
{
  pid_t pid;
  if ((pid = fork()) == 0) {
        execl(argv[1], 0);
  }
  else if(pid==-1){
      printf("error al crear proceso hijo");

  }
  else {
    wait(&pid);
    printf("programa finalizado\n");
  }
  return 0;
}