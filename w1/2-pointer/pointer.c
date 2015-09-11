#include <stdio.h>
#define ALL (0)

int main(int argc,char *argv[])
{
	int i = 0;
	int *p = &i;
	printf("Initializing i as 0\n");
	printf("Address of *p is : %p\n",p);
	printf("Peek..The value is %d\n",*p);
	// Changing i, What will happen?
#if (0 || ALL)
	i = 20;
	printf("Peek Again, Value of *p: %d\n",*p);
#endif
#if (0 || ALL)
	*p = 3150;
	printf("value of i: %d\n",i);
#endif
	return 0;
}
