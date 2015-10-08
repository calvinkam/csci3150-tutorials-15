#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <signal.h>

int main(int argc,char *argv[])
{
	// Ignore Term signals for Parent
  	signal(SIGINT,SIG_IGN);
	signal(SIGQUIT,SIG_IGN);
	signal(SIGTERM,SIG_IGN);
	signal(SIGTSTP,SIG_IGN);

  pid_t child;

  if(!(child=fork()))
  {
    signal(SIGINT,SIG_DFL);
  	signal(SIGQUIT,SIG_DFL);
  	signal(SIGTERM,SIG_DFL);
  	signal(SIGTSTP,SIG_DFL);
    char *argList[] = {"cat",NULL};
    printf("Running Cat Meow [%d]...It will repeat after you..\n",getpid());
    execvp(*argList,argList);
  }
  else
  {
    int status;
    waitpid(child,&status,WUNTRACED);

    if(WIFSTOPPED(status))
    {
      printf("\nCat is sleeping! You talk to yourself...\n");
      printf("\nWake it up?\n");
      while(getchar() != 'Y');
      printf("Waking up cat YEAH\n");
      kill(child,SIGCONT);
      waitpid(child,&status,WUNTRACED);
    }
  }

  return 0;
}
