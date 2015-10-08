#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <signal.h>
pid_t launchCat(int id);
void waitchildren();
void wakechildren();

int pipeFd[2];
pid_t children[2];
int slept = 0;
int main(int argc,char *argv[])
{
  signal(SIGQUIT,SIG_IGN);
  signal(SIGTERM,SIG_IGN);
  signal(SIGTSTP,SIG_IGN);

  pipe(pipeFd);
  children[0] = launchCat(1);
  children[1] = launchCat(2);
  close(pipeFd[0]);close(pipeFd[1]);
  while(!slept)
  {
    waitchildren();
    printf("Waking them up?");
    while(getchar() != 'Y');
    wakechildren();
  }

  return 0;
}
void wakechildren()
{
  int i;
  printf("Waking Up catss..\n");
  for(i = 0; i < 2;i++)
  {
    kill(children[i],SIGCONT);
  }
  slept = 0;
}
void waitchildren()
{
  int i;
  int status;
  for(i = 0;i < 2;i++)
  {
    waitpid(children[i],&status,WUNTRACED);

    if(WIFSTOPPED(status))
    {
      slept = 1;
      printf("\nThey are sleeping..\n");
      break;
    }
  }
}
pid_t launchCat(int id)
{
  char *argList[] = {"cat",NULL};
  pid_t child;

  if(!(child = fork()))
  {
    signal(SIGQUIT,SIG_DFL);
    signal(SIGTERM,SIG_DFL);
    signal(SIGTSTP,SIG_DFL);
    if(id == 1)
    {
      close(pipeFd[0]);
      dup2(pipeFd[1],1);
      close(pipeFd[1]);
    }
    else
    {
      close(pipeFd[1]);
      dup2(pipeFd[0],0);
      close(pipeFd[0]);
    }
    execvp(*argList,argList);
  }
  else
  {
    return child;
  }
}
