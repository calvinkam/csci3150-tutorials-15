#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <errno.h>
#include <string.h>
int main(int argc,char *argv[])
{
	char buf[PATH_MAX+1];
	char input[255];
	if(getcwd(buf,PATH_MAX+1) != NULL)
	{
		printf("Now it is %s\n",buf);

		if(chdir("/tmpp") != -1)
		{
			getcwd(buf,PATH_MAX+1);
			printf("Now it is %s\n",buf);
		}
		else
		{
			printf("Cannot Change Directory\n");
			// For Debug purpose, no need in assignment
			printf("Error is %d [%s]\n",errno,strerror(errno));
		}
	}
	return 0;
}

