#include <iostream>

using namespace std;
#define MAX 100 //数据元素的最大个数

typedef struct
{
        int r[MAX];
        int length;
}SqList; //定义一个线性表用于存放数据元素

void HeapAdjust(SqList &L,int s,int m)
{
	//已知L.r[s...m]中记录除L.r[s]外均满足堆的定义，本函数用于使L.r[s...m]成为一个大顶堆
        int j;
        int e=L.r[s];
        for(j=2*s;j<=m;j*=2)
        {
                if(j<m && L.r[j]<L.r[j+1]) ++j;
                if(e>=L.r[j]) break;
                L.r[s]=L.r[j];
                s=j;
        }
        L.r[s]=e;
}

void HeapSort(SqList &L)
{
	//对顺序表L进行堆排序
        int i,e;
        for(i=L.length/2;i>=0;i--)
        HeapAdjust(L,i,L.length-1);
        for(i=L.length-1;i>=0;i--)
	{
		//将大顶堆的顶记录和最后一个记录相互交换
                e=L.r[0];
                L.r[0]=L.r[i];
                L.r[i]=e;
                HeapAdjust(L,0,i-1);
        }
}
		
int main()
{
        SqList Heap={{85,13,15,24,20,18,60,25,46,11,20},11};
	HeapSort(Heap);
        for(int i=0;i<11;i++)
            cout << Heap.r[i]<<" ";
        cout<<Heap.r.length<<endl;
	return 0;
}
