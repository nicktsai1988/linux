#include <iostream>
#define MAX 100
#define length(X) (sizeof(X)/sizeof(X[0]))
struct array
{
	int *ptr;
	int length;
};


using namespace std;

void HeapAdjust(array A,int s,int heap_size)
{
	int largest, temp;
	int l = 2 * s;
	int r = 2 * s + 1;
	if(l<heap_size && A.ptr[l]>A.ptr[s])
		largest = l;
	else
		largest = s;
	if(r<heap_size && A.ptr[r]>A.ptr[largest])
	largest = r;
	if(largest != s)
	{
		temp = A.ptr[largest];
		A.ptr[largest] = A.ptr[s];
		A.ptr[s] = temp;
		HeapAdjust(A, largest,heap_size);
   	}
}


void Build_Max_Heap(array A)
{
	for(int i=A.length/2; i>=0; i--)
	HeapAdjust(A, i,A.length);
}


void HeapSort(array A)
{
	Build_Max_Heap(A);
	int temp,heap_size=A.length;
	for(int i=A.length-1; i>=0; i--)
	{
	temp = A.ptr[0];
	A.ptr[0] = A.ptr[i];
	A.ptr[i] = temp;
	heap_size--;
	HeapAdjust(A,0,heap_size);
	}
}

int main()
{
	int myarray[]={10,13,15,14,18,20,60,25,46,11,50};
	array data;
	data.ptr=myarray;
	data.length=length(myarray);
	cout << data.length<< endl;
	HeapSort(data);
	cout << "the heap after sorting :" << endl;
	for(int j=0; j<data.length; j++)
	cout << data.ptr[j] <<" ";
	cout<<endl;
	return 0;
}
