#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
}*head=NULL,*t,*new;
int main()
{
	int ch;
	while(1)
	{
		printf("\n\nCircular queue Operations\n1.Push\n2.Pop\n3.Display\n4.Exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: push();
					break;
			case 2: pop();
					break;
			case 3: display();
					break;
			case 4: exit(0);
			default: printf("Wrong choice\n");
		}
	}
return 0;
}
void push()
{
	new = (struct node*)malloc(sizeof(struct node));
	printf("Enter element: ");
	scanf("%d",&new->data);
	if(head==NULL)
	{
		head=new;
		head->next=head;
	}
	else
	{
		t=head;
		while(t->next != head)
			t=t->next;
		t->next=new;
		t=new;
		t->next=head;
	}
}
void pop()
{
	if(head==NULL)
		printf("Queue is empty\n");
	else if(head->next == head)
	{
		new=head;
		head=NULL;
		printf("Popped element: %d\n",new->data);
		free(new);
	}
	else
	{
		new=head;
		t=head;
		while(t->next != head)
			t=t->next;
		t->next = head->next;
		head=head->next;
		printf("Popped element: %d\n",new->data);
		free(new);
	}
}
void display()
{
	if(head==NULL)
		printf("Queue is empty\n");
	else
	{
		t=head;
		printf("%d ",t->data);
		while(t->next != head)
		{
			t=t->next;
			printf("%d ",t->data);
		}
		printf("%d ",t->next->data);
	}
}

