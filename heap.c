#include<stdio.h>
int main()
{
    int a[]={9,5,7,4,3,0,1};
    heapsort(a,7);
    int i;
    for(i=0;i<7;i++)
        printf("%d ",a[i]);
    return 0;
}
void heapify(int a[],int n,int i)
{
    int largest=i;
    int l=2*i+1;
    int r=(2*i)+2;
    while(l<n && a[l]>a[largest])
        largest=l;
    while(r<n && a[r]>a[largest])
        largest =r;
    if(largest!=i)
    {
        swap(a[largest],a[i]);
        heapify(a,n,largest);
    }
}
void heapsort(int A[],int n)
{
    int i;
    for(i=(n-2)/2;i>=0;i--)
        heapify(A,n,i);
    for(i=n;i>=1;i--)
    {
        swap(A[0],A[i]);
        heapify(A,n,0);
    }
}
void swap(int a,int b)
{
    int c;
    c=a;
    a=b;
    b=c;
}