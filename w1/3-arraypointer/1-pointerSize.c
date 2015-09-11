#include <stdio.h>
#include <stdlib.h>
int main(int argc,char *argv[])
{
	int *iPtr;
	char *cPtr;
	printf("sizeof iPtr[%p]: %d\n",iPtr,sizeof(iPtr));
	printf("sizeof char[%p]: %d\n",cPtr,sizeof(cPtr));
return 0;
}
