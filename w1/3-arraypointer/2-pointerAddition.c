#include <stdio.h>
#define ALL (0)
int main(int argc,char *argv[])
{
	char charArray[] = {'C','S','C','I'};
	int numArray[] = {3,1,5,0};
	int *nPtr = numArray;
	char *cPtr = charArray;
	// What is the current value of *nPtr?
	printf("Now CPtr(%p) : [%c]\n",cPtr,*cPtr);
	printf("Now nPtr(%p) : [%d]\n",nPtr,*nPtr);
#if (0 || ALL)
	// Let's increment and look inside..
	printf("1 step forward..\n");
	nPtr++;cPtr++;	
	printf("Now CPtr(%p) : [%c]\n",cPtr,*cPtr);
	printf("Now nPtr(%p) : [%d]\n",nPtr,*nPtr);
#endif
	return 0;
}
