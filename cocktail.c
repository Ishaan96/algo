#include<stdio.h>
void cocktail(int arr[],int n);
int main()
{
	int arr[50];
	int n,i;
	printf("Enter number of elements in the array\n");
	scanf("%d",&n);
	printf("Enter %d elements\n",n);
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	cocktail(arr,n);
	printf("Sorted array is:\n");
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
	return 0;
}
void cocktail(int arr[],int n)
{
	int i,temp,start=0,end;
	end = n;
  do
  {
	for(i=0;i<end-1;i++) 		//Rightward pass
	{
		if(arr[i]>arr[i+1])
		{
			temp = arr[i];
			arr[i] = arr[i+1];
			arr[i+1] = temp;
		}
	} 
	end--;

	for(i=n-1;i>=start;i--) 	//Leftward pass
	{
		if(arr[i]<arr[i-1])
		{
			temp = arr[i];
			arr[i] = arr[i-1];
			arr[i-1] = temp;
		}
	}
	start++;
  }while(end!=0 && start!=0);
}
