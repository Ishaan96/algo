#include<stdio.h>
void quicksort(int arr[],int first,int last);
int main()
{
	int arr[50];
	int n,i;
	printf("Enter number of elements in the array\n");
	scanf("%d",&n);
	printf("Enter %d elements\n",n);
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	quicksort(arr,0,n-1);
	printf("Sorted array is:\n");
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
	return 0;
}
void quicksort(int arr[],int first,int last)
{
	int i,j,pivot,temp;
	if(first<last)
	{
		pivot = first;
		i = first;
		j = last;
		while(i<j)
		{
			while(arr[i]<=arr[pivot] && i<last)
				i++;
			while(arr[j]>arr[pivot])
				j--;
			if(i<j)
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
		temp = arr[pivot];
		arr[pivot] = arr[j];
		arr[j] = temp;
		quicksort(arr,first,j-1);
		quicksort(arr,j+1,last);
	}
}
