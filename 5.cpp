#include <iostream>
#include <string>
#define MAX 100

using namespace std;
void HeapAdjust(int A[], int s, int size);
void Build_Max_Heap(int A[], int size);
void HeapSort(int A[], int size);

int main()
{
int array[11]={10,13,15,14,18,20,60,25,46,11,50};
HeapSort(array, 11);
return 0;
}



void HeapAdjust(int A[], int s, int size)
{
int largest, temp;
int heap_size = size;
int l = 2 * s;
int r = 2 * s + 1;
if(l<heap_size && A[l]>A[s])//
largest = l;
else
largest = s;
if(r<heap_size && A[r]>A[largest])//
largest = r;
if(largest != s)
{
temp = A[largest];
A[largest] = A[s];
A[s] = temp;
HeapAdjust(A, largest, size);
}
}


void Build_Max_Heap(int A[], int size)
{
for(int i=size/2; i>=0; i--)//
HeapAdjust(A, i, size);

cout << "the building heap :" << endl;
for(int j=0; j<size; j++)
cout << A[j] << ' ';
cout << endl;
}


void HeapSort(int A[], int size)
{
Build_Max_Heap(A,size);
int temp,heap_size=size;
for(int i=size-1; i>=0; i--)
{
temp = A[0];
A[0] = A[i];
A[i] = temp;
heap_size--;
HeapAdjust(A, 0, heap_size);//
}
cout << "the heap after sorting :" << endl;
for(int j=0; j<size; j++)
cout << A[j] << " ";
cout<<endl;
}
