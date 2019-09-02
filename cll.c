#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
}*head=NULL;
struct node *t,*new;
int main()
{
	int ch,ins,del,n=1;
	while(1)
	{
		printf("\n\nSingle Linked List Operations.\n1.Create List\n2.Insert\n3.Delete\n4.Display\n5.Exit\n");
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
void createList(int *p)
{
	int n,i;
	printf("Enter number of elements in the list\n");
	scanf("%d",&n);
	*p = n;
	for(i=1;i<=n;i++)
	{
		new = (struct node*)malloc(sizeof(struct node));
		printf("Enter element: ");
		scanf("%d",&new->data);
		if(head == NULL)
		{
			head = new;
			t = new;
		}
		else
		{
			t->next = new;
			t = new;
		}
	}
	t->next = head;
}
	
void display(int n)
{
	if(n==0)
		head=NULL;
	if(head == NULL)
		printf("List is empty\n");
	else
	{
		t = head;
		while(t->next != head)
		{
			printf("%d  ",t->data);
			t = t->next;
		}
		printf("%d",t->data);
	}
}

void insert(int n,int *m)
{
	int pos,i;
	printf("Enter position to insert\n");
	scanf("%d",&pos);
	new = (struct node*)malloc(sizeof(struct node));
	if(pos<1)
		printf("UNDERFLOW\n");
	else if(pos>n)
		printf("OVERFLOW\n");
	else if(pos==1 && head==NULL)
	{
		printf("Enter element to insert in empty list\n");
		scanf("%d",&new->data);
		head = new;
		new->next=head;		
	}
	else if(pos==1)
	{
		printf("Enter element to insert at position %d\n",pos);
		scanf("%d",&new->data);
		t=head;
		while(t->next!=head)
			t=t->next;
		new->next = head;
		head=new;
		t->next=head;
		n++;
		*m=n;
	}
	else if(pos>1 && pos<n)
	{
		printf("Enter element to insert at position %d\n",pos);
		scanf("%d",&new->data);
		t=head;
		for(i=1;i<pos-1;i++)
			t=t->next;
		new->next = t->next;
		t->next = new;
		n++;
		*m=n;
	}
	else if(pos==n)
	{
		printf("Enter element to insert at position %d\n",pos);
		scanf("%d",&new->data);
		t=head;
		while(t->next != head)
			t=t->next;
		t->next=new;
		new->next=head;
		n++;
		*m=n;
	}
}
void delete(int n,int *m)
{
	int pos,i;
	printf("Enter position to delete: ");
	scanf("%d",&pos);
	if(pos<1)
		printf("UNDERFLOW\n");
	else if(pos>n)
		printf("OVERFLOW\n");
	else if(head==NULL)
		printf("List is empty\n");
	else if(pos==1)
	{
		new=head;
		t=head;
		while(t->next != head)
			t=t->next;
		head=new->next;
		t->next=head;
		printf("Deleted element is: %d\n",new->data);
		free(new);
		n--;
		*m=n;
	}
	else if(pos>1 && pos<n)
	{
		t=head;
		for(i=1;i<pos-1;i++)
			t=t->next;
		new=t->next;
		t->next=new->next;
		printf("Deleted element is: %d\n",new->data);
		free(new);
		n--;
		*m=n;
	}
	else if(pos==n)
	{
		t=head;
		while(t->next->next != head)
			t=t->next;
		new=t->next;
		t->next=head;
		printf("Deleted element is: %d\n",new->data);
		free(new);
		n--;
		*m=n;
	}
}
