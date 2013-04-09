#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
int main()
{
	printf("%s\n",strerror(EPROTO));
	return 0;
}
