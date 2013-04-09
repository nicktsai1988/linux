
#include"debug3.h"
#include<stdio.h>
item array[]={
	{"bill",3},
	{"neil",4},
	{"john",2},
	{"rick",5},
	{"alex",1},
};

int main()
{
	int i;
	sort(array,5);
	for(i=0;i<5;i++)
		printf("array[%d]={%s,%d}\n",i,array[i].data,array[i].key);
	return 0;
}
