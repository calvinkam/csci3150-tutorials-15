#include <stdio.h>
#include <unistd.h> // Needed By execvp

int main(int argc,char *argv[])
{
	printf("Calling ls...\n");
	char *arglist[] = {"ls",NULL};
	execvp(*arglist,arglist);

	printf("Will the girl 'ls' reply my message?\n");
	return 0;
}