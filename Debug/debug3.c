#include"debug3.h"
void sort(item* a,int n)
{
	int i=0,j=0;
	int s=1;
	for(;i<n&&s!=0;i++)
	{
		s=0;
		for(j=0;j<n;j++)
		{
			if(a[j].key>a[j+1].key)
			{
				item t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
				s++;
			}
		}
		n--;
	}
}

