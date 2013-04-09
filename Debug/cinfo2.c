#include<stdio.h>
#include<stdlib.h>
int debug=0;

int main()
{
#ifdef DEBUG
	printf("Compiled: " __DATE__ " at " __TIME__ "\n");
	printf("This is line %d of file %s\n", __LINE__, __FILE__);
#endif
	if(debug)
		printf("Debuging\n");
	printf("Hello World\n");
	exit(0);
}
