#include<stdio.h>

int main()
{	srand(time(NULL));
	int ch,i,c;
	while(1)
	{
		int b[10],w[10],r[10];
		for(i=0;i<10;i++)
			b[i] = i;

		for(i=9;i>=0;i--)
			w[i] = 9-i;
		
		for(i=0;i<10;i++)
			r[i] = rand()%10;
		printf("Enter your choice(1-5):\n1.Bubble sort\n2.Advanced bubble sort\n3.Cocktail Shaker sort\n4.Quick sort\n5.Exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("Best case:\n");
				for(i=0;i<10;i++)
					printf("%d ",b[i]);				
				bubble(b,10); 
				printf("Worst case:\n");
				for(i=0;i<10;i++)
					printf("%d ",w[i]);				
				bubble(w,10);
				 printf("Random case:\n");
				for(i=0;i<10;i++)
					printf("%d ",r[i]);				
				bubble(r,10);
				break;
			case 2: printf("Best case:\n");
				for(i=0;i<10;i++)
					printf("%d ",b[i]);				
				adv_bubble(b,10); 
				printf("Worst case:\n");
				for(i=0;i<10;i++)
					printf("%d ",w[i]);				
				adv_bubble(w,10);
				 printf("Random case:\n");
				for(i=0;i<10;i++)
					printf("%d ",r[i]);				
				adv_bubble(r,10);
				break;
			case 3: printf("Best case:\n");
				for(i=0;i<10;i++)
					printf("%d ",b[i]);				
				cocktail(b,10); 
				printf("Worst case:\n");
				for(i=0;i<10;i++)
					printf("%d ",w[i]);				
				cocktail(w,10);
				 printf("Random case:\n");
				for(i=0;i<10;i++)
					printf("%d ",r[i]);				
				cocktail(r,10);
				break;
			case 4:	printf("Best case:\n");
				for(i=0;i<10;i++)
					printf("%d ",b[i]);
				c = count(b);			
				quicksort(b,0,9); 
				printf("\nSorted array\n");
				for(i=0;i<10;i++)
					printf("%d ",b[i]);
				printf("\nNumber of operations: %d\n\n",c);
				
				printf("Worst case:\n");
				for(i=0;i<10;i++)
					printf("%d ",w[i]);
				c = count(w);				
				quicksort(w,0,9);
				printf("\nSorted array:\n");
				for(i=0;i<10;i++)
					printf("%d ",w[i]);
				printf("\nNumber of operations: %d\n\n",c);
				
				 printf("Random case:\n");
				for(i=0;i<10;i++)
					printf("%d ",r[i]);
				c = count(r);				
				quicksort(r,0,9);
				printf("\nSorted array:\n");
				for(i=0;i<10;i++)
					printf("%d ",r[i]);
				printf("\nNumber of operations: %d\n\n",c);
				break;
			case 5: exit(0);
			default: printf("Wrong Choice\n");
		}
	}
return 0;
}
void bubble(int a[],int n)
{
	int i,j,temp,k=0;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		 k++;
		}
	}
	printf("\nThe sorted array is:\n");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);

	printf("\nNumber of operations: %d\n\n",k);
}
void adv_bubble(int a[],int n)
{
	int j,bound,t,temp,k=0;
	bound = n-1;
	do
	{
		t=0;
		for(j=0;j<bound;j++)
		{
			if(a[j]>a[j+1])
			{
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
				t=j;
			}
			k++;
		}
		bound = t;
	}while(t>0);

	printf("\nThe sorted array is:\n");
	for(j=0;j<n;j++)
		printf("%d ",a[j]);

	printf("\nNumber of operations: %d\n\n",k);
}

void cocktail(int a[],int n)
{
	int i,temp,start=0,end,k=0;
	end = n;
  do
  {
	for(i=0;i<end-1;i++) 		//Rightward pass
	{
		if(a[i]>a[i+1])
		{
			temp = a[i];
			a[i] = a[i+1];
			a[i+1] = temp;
			k++;
		}		
	} 
	end--;

	for(i=n-1;i>start;i--) 	//Leftward pass
	{
		if(a[i]<a[i-1])
		{
			temp = a[i];
			a[i] = a[i-1];
			a[i-1] = temp;
			k++;
		}		
	}
	start++;
  }while(end!=0 && start!=0);

  printf("\nThe sorted array is:\n");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);

	printf("\nNumber of operations: %d\n\n",k);
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

int count(int a[])
{
	int i,flag=0;
	for(i=0;i<9;i++)
	{
		if(a[i]>a[i+1])
		flag++;
	}
	return flag;
}
