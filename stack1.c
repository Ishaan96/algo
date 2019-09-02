#include<stdio.h>
int s[20];
int top=-1;
int main()
{
	int ch,p;

while(1)
{
	printf("Stack Operations\n1.Push\n2.Pop\n3.Peek\n4.Exit\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1: printf("Enter element to push: ");
				scanf("%d",&p);
				push(p);
				break;
		case 2: pop();
				break;
		case 3: peek();
				break;
		case 4: exit(0);
		default: printf("Wrong choice\n");
	}
}
return 0;
}
void push(int n)
{
	s[++top] = n;	
}

int isEmpty()
{
	if(top==-1)
		return 1;
	else
		return 0;
}
void pop()
{
	if(!isEmpty())
		printf("Popped element: %d\n",s[top--]);
	else 
		printf("Stack is empty\n");
}
void peek()
{
	if(!isEmpty())
		printf("Top element: %d\n",s[top]);
	else 
		printf("Stack is empty\n");
}
