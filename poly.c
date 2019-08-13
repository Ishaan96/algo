#include<stdio.h>
typedef struct
 {
	float coeff;
	int exp;
 }poly;
poly term[100];
int main()
 {
	int numofpoly,numofterms,k,i=0,j=0,m;
	printf("\nEnter number of polynomials to add\n");
	scanf("%d",&numofpoly);
	printf("\n");
	while(numofpoly)
	 {
		printf("How many terms?\n");
		scanf("%d",&numofterms);
		printf("Enter co-effs and exponents\n");
		k=0;
		while(numofterms)
		 {
			scanf("%f",&term[i].coeff);
			scanf("%d",&term[i].exp);
			i++;
			k++;
			numofterms--;
		 }
		
		j++;
		k--;
		printf("\n%d th term is: ",j);
		for(m=i-1;m>=(i-k-1);m--)
		 {
			printf("%.2fx^%d",term[m].coeff,term[m].exp);
			if(m>i-k-1)
			 {
				printf(" + ");
			 }
		 }
		printf("\n");
		numofpoly--;
	 }
	i--;
	for(j=0;j<i;j++)
	 {
		for(k=j+1;k<=i;k++)
		 {
			if((term[j].coeff!=0)&&(term[k].coeff!=0)&&(term[j].exp==term[k].exp))
			 {
				term[j].coeff += term[k].coeff;
				term[k].coeff = 0;
			 }
		 }
	 }
	printf("\nThe added polynomial is: ");
	for(j=0;j<=i;j++)
	 {
		if(j==0)
		 {
			if(term[j].coeff>0)
			{
			 printf("%.2fx^%d",term[j].coeff,term[j].exp);
			}
			else if(term[j].coeff<0)
			{
			 printf("-%.2fx^%d",term[j].coeff,term[j].exp);
			}
		 }
		else
		 {
			if(term[j].coeff>0)
			{
			 printf("+%.2fx^%d",term[j].coeff,term[j].exp);
			}
			else if(term[j].coeff<0)
			{
			 printf("%.2fx^%d",term[j].coeff,term[j].exp);
			}
		 }
	 }
	return 0;
 }
