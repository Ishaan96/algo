#include<stdio.h>

int main()
 {
	int a,b,i,j,k=1,zero=0,non_zero=0;
	printf("Enter number of rows and columns of the matrix\n");
	scanf("%d%d",&a,&b);
	int A[a][b];
	
	printf("Enter matrix elements\n");
	for(i=0;i<a;i++)
	 {
	    for(j=0;j<b;j++)
	      {
			scanf("%d",&A[i][j]);
	      }
	 }
	
	for(i=0;i<a;i++)
	 {
	    for(j=0;j<b;j++)
	      {
			if(A[i][j] != 0)
			  non_zero++;
			else
			  zero++;
	      }
	 }
	float limit;
	limit = 0.66*a*b;
  if(zero >= (int)limit)
   {
	printf("It is a Sparse Matrix\n");
	int Triple[non_zero+1][3];
	Triple[0][0] = a;
	Triple[0][1] = b;
	Triple[0][2] = non_zero;
	for(i=0;i<a;i++)
	 {
	    for(j=0;j<b;j++)
	      {
		  if(A[i][j] != 0)
		   {	
			Triple[k][0] = i;
			Triple[k][1] = j;
			Triple[k][2] = A[i][j];
			k++;
		   }
	       }
	 }
	printf("Triple Format:\n");
	for(i=0;i<=non_zero;i++)
	 {
	    for(j=0;j<3;j++)
	      {
			printf(" %d",Triple[i][j]);
	      }
		printf("\n");
	 }
	printf("\n\n");
	int Transpose[b][a];
	k = 1;
	printf("Transpose:\n");
	for(i=0;i<b;i++)
	 {
	   for(j=0;j<a;j++)
	    {	
		if((i == Triple[k][1]) && (j == Triple[k][0]))
		 {
		 	Transpose[i][j] = Triple[k][2];
			k++;
		 }
		else
		    Transpose[i][j] = 0;

		printf(" %d",Transpose[i][j]);
	    }
	printf("\n");
	}
   }
	else
		printf("Not a Sparse Matrix");
return 0;
}
