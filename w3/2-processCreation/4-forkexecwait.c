#include <stdio.h>
#include <unistd.h>
#include <sys/types.h> // Needed By waitpid().
#include <stdlib.h>
#include <sys/wait.h> // Needed By waitpid().

int main(int argc,char *argv[])
{
	while(1)
	{
		printf("\nPress Enter to execute ls...");
		while(getchar() != '\n');
		pid_t child_pid;
		if(!(child_pid = fork()))
		{
			char *arglist[] = {"ls",NULL};
			execvp(*arglist,arglist);
		}
		else
		{
			waitpid(child_pid,NULL,WUNTRACED);
		}

	}
	return 0;
}