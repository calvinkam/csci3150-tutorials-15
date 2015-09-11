#include <stdio.h>
#define SIZE 4
#define ALL (0)
int main(int argc,char *argv[]) {
	char charArray[] = {'C','S','C','I'};
	int numArray[] = {3,1,5,0};
	int *nPtr = numArray;
	char *cPtr = charArray;
	// What is the current value of *nPtr?
	printf("Now CPtr(%p) : [%c]\n",cPtr,*cPtr);
	printf("Now nPtr(%p) : [%d]\n",nPtr,*nPtr);
#if (0 || ALL)
	// Move it Move it
	nPtr += SIZE;
	cPtr += SIZE;
	printf("We move the pointers by %d\n\n",SIZE);
	// What is the meaning of subtraction?
	printf("nPtr-numArray: [%d]\n",nPtr-numArray);	
	printf("cPtr-charArray: [%d]\n",cPtr-charArray);	
#endif 
	return 0;
}
