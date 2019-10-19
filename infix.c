#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#define MAX 30
char s[MAX];
int top=-1;
int is_operator(char symbol)
{
	if(symbol=='*' || symbol=='/' || symbol=='+' || symbol=='-' || symbol=='^')
		return 1;
	else
		return 0;
}
int precedence(char symbol)
{
	if(symbol=='^')
		return 3;
	else if(symbol=='*' || symbol=='/')
		return 2;
	else if(symbol=='+' || symbol=='-')
		return 1;
	else
		return 0;
}
void push(char symbol)
{
	if(top>=MAX-1)
		printf("Stack is full\n");
	else
		s[++top]=symbol;
}
char pop()
{
	char x;
	if(top<0)
		printf("Stack Underflow\n");
	else 
		return s[top--];
}
void conversion(char infix[],char postfix[])
{
	int i=0,j=0;
	push('(');
	strcat(infix,")");
	char item=infix[i];
	char x;
	while(item!='\0')
	{
		if(item=='(')
			push(item);
		else if(isalnum(item))
			postfix[j++]=item;
		else if(is_operator(item)==1)
		{
			x=pop();
			while(is_operator(x)==1 && precedence(x)>=precedence(item))
			{
				postfix[j++] = x;
				x=pop();
			}
		push(x);
		push(item);
		}
		else if(item==')')
		{
			x=pop();
			while(x!='(')
			{
				postfix[j++]=x;
				x=pop();
			}
		}
		else 
		{
			printf("Invalid infix expression\n");
			exit(1);
		}
		i++;
	item=infix[i];
	}
	if(top>0)
	{
		printf("Invalid input expression\n");
		exit(1);
	}
	postfix[j]='\0';
}
		
int main()
{
	char inf[MAX],psf[MAX];
	printf("Enter infix expression\n");
	gets(inf);
	conversion(inf,psf);
	puts(psf);
	return 0;
}
