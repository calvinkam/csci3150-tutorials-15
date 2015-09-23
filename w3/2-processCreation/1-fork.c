#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>


int main(int argc,char* argv[])
{
	printf("Before fork, my pid is %d\n",getpid());
	if(fork())
	{
		printf("I am Parent,my pid is %d,ppid is %d\n",getpid());
	}
	else
	{
		printf("I am Child, my pid is %d\n",getpid());
	}
	return 0;
}
