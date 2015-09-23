#include <stdio.h>
#include <string.h>

int main(int argc,char *argv[])
{
	char buf[255];
	printf("[I am Shell]$:");
	fgets(buf,255,stdin);
	printf("%s\n",buf);
	return 0;
}
