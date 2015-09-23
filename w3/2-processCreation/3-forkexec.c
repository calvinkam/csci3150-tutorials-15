#include <stdio.h>
#include <unistd.h> // Needed By fork(),sleep()

int main(int argc,char *argv[])
{
	while(1)
	{
		printf("\nPress Enter to execute ls...");
		while(getchar() != '\n');
		if(!fork())
		{
			char *arglist[] = {"ls",NULL};
			execvp(*arglist,arglist);
		}
		else
		{
			sleep(1);
		}
	}
	return 0;
}
