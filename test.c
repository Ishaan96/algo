#include<stdio.h>
int main()
{
    int a[10];
    int i,n;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    printf("Enter elements: ");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    heapsort(a,n);
    printf("Sorted\n");
    for(i=0;i<10;i++)
        scanf("%d ",a[i]);
    return 0;
}
void swap(int a,int b)
{
    int t;
    t=a;
    a=b;
    b=t;
}
void heapify(int a[],int i,int n)
{
    int l = i;
    int left = 2*i+1;
    int right = 2*i+2;
    if(a[left]>a[l] && left<n)
        l = left;
    if(a[right]>a[l] && right<n)
        l = right;
    if(l != i)
    {
        swap(a[i],a[l]);
        heapify(a,l,n);
    }
}
void heapsort(int a[],int n)
{
    int i;
    for(i=n/2 - 1; i>=0;i--)
        heapify(a,i,n);
    for(i=n-1;i>=0;i--)
    {
        swap(a[0],a[i]);
        heapify(a,0,i);
    }
}
