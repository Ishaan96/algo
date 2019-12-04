#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
 {
	srand(time(NULL));
	int r1,c1,r2,c2,i,j,k;
	int **m1,**m2,**m3;
     do
      {	
	printf("Enter number of rows of the first matrix \n");
	scanf("%d",&r1);
	printf("Enter number of columns of the first matrix \n");
	scanf("%d",&c1);
	printf("Enter number of rows of the second matrix \n");
	scanf("%d",&r2);
	printf("Enter number of columns of the second matrix \n");
	scanf("%d",&c2);
      }
    while(c1!=r2);
	
	m1=(int **)malloc(sizeof(int *)*r1);
		for(i=0;i<r1;i++)
		   m1[i]=(int *)malloc(sizeof(int)*c1);
	
	m2=(int **)malloc(sizeof(int *)*r2);
	 	for(i=0;i<r2;i++)
		  m2[i]=(int *)malloc(sizeof(int)*c2);

	for(i=0;i<r1;i++)
	 {
	   for(j=0;j<c1;j++)
	     {
		m1[i][j]=rand()%10;
	    }
	}

	
	for(i=0;i<r2;i++)
	 {
	   for(j=0;j<c2;j++)
	     {
		m2[i][j]=rand()%10;
	    }
	}
	m3=(int **)calloc(sizeof(int *),r1);
	for(i=0;i<r1;i++)
	  m3[i]=(int *)calloc(sizeof(int),c2);

	for(i=0;i<r1;i++)
	 {
		for(j=0;j<c2;j++)
		 {
		    for(k=0;k<c1;k++)
		     {
			m3[i][j]+=m1[i][k]*m2[k][j];
		}
	}
	}

	printf("First Matrix \n");
	for(i=0;i<r1;i++)
	 {
	   for(j=0;j<c1;j++)
	     {
		printf("%d  ",m1[i][j]);
	    }
		printf("\n");
	}
	printf("Second Matrix \n");
	for(i=0;i<r2;i++)
	 {
	   for(j=0;j<c2;j++)
	     {
		printf("%d  ",m2[i][j]);
	    }
	printf("\n");
	}
	printf("Multiplied Matrix \n");
	for(i=0;i<r1;i++)
	 {
	   for(j=0;j<c2;j++)
	     {
		printf("%d  ",m3[i][j]);
	    }
	printf("\n");
	}
return 0;
}
	
