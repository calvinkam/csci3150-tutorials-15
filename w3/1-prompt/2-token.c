#include <stdio.h>
#include <string.h>

int main(int main,char *argv[])
{
	char buf[] = "Hello World tywong sosad";
	printf("Original buf: %s\n",buf);
	
	char *token = strtok(buf," ");
	while(token != NULL)
	{
		printf("%s\n",token);
		token = strtok(NULL," ");
	}
	return 0;
}
