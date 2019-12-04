#include<stdio.h>
struct node
{
	int data;
	struct node *prev,*next;
}head=NULL;
struct node *t,*new;
int main()
{
	int ch,ins,del,n=1;
	while(1)
	{
		printf("\n\nDoubly Linked List Operations.\n1.Create List\n2.Insert\n3.Delete\n4.Display\n5.Exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: createList(&n);
				break;
			case 2: insert(n,&n);
				  break;
			case 3: delete(n,&n);
				break;
			case 4: display(n);
				break;
			case 5: exit(0);
			default: printf("Wrong choice\n");
		}
	}
return 0;
}
void create()
{
	int n;
	printf("Enter number of elements is the list\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		new = (struct node*)malloc(sizeof(struct node));
		printf("Enter element: ");
		scanf("%d",&new->data);
		if(head==NULL)
		{
			head=new;
			head->prev=NULL;
			t=head;
		}
		else
		{
			t->next=new;
			t=new;
		}
		t->next=NULL;
	}
} 
void display()
{
	if(head==NULL)
		printf("List is empty\n");
	else
	{
		t=head;
		while(t->next!=NULL)
		{
			printf("%d ",t->data);
			t=t->next;
		}
	}
}
void insert(int n)
{
	int pos;
	printf("Enter position to insert: ");
	scanf("%d",&pos);
	new = (struct node*)malloc(sizeof(struct node));
	if(pos<1)
		printf("UNDERFLOW\n");
	else if(pos>n)
		printf("OVERFLOW\n");
	else if(pos==1 && head==NULL)
	{
		printf("Enter element to insert in empty list: ");
		scanf("%d",&new->data);
			head=new;
			head->prev=NULL;
			head->next=NULL;
	}
	else if(pos==1)
	{
		printf("Enter element to insert: ");
		scanf("%d",&new->data);
		new->prev=NULL;
		new->next=head;
		head=new;
	}
	else if(pos>1 && pos<n)
	{
		printf("Enter element to insert: ");
		scanf("%d",&new->data);
		t=head;
		for(i=1;i<pos-1;i++)
			t=t->next;	
		new->next=t->next;
		t->next=new;
	}
	else if(pos==n)
	{
		printf("Enter element to insert: ");
		scanf("%d",&new->data);
		t
		
