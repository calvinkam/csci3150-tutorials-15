#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc,char *argv[])
{	
	if(argc == 2 && atoi(argv[1]) == 1)
	{
		signal(SIGINT,SIG_IGN);
		signal(SIGQUIT,SIG_IGN);
		signal(SIGTERM,SIG_IGN);
		signal(SIGTSTP,SIG_IGN);
	}
	

	while(1)
	{
		printf("I am [%d],Kill me if you can :P ",getpid());
		while(getchar()!='\n');
	}
	return 0;
}
