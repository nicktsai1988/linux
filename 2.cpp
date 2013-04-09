#include<iostream>
using namespace std;

//#define length(X) (sizeof(X)/sizeof(X[0]))
int length(int X[])
{
	return (sizeof(X)/sizeof(X[0]));
}

int main()
{
	int A[]={2,0,1,0,0,0,0,4};
	cout<< length(A)<<endl;
	return 0;
}
