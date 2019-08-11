#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
} *head=NULL;
void create_list(void);
void insert_big(void);
void insert_end(void);
void insert_bet(void);
void display(void);
//main function
int main()
{
    int a,b,c;
    char ch;
    while(1)
    {
        printf("enter your choice:\n 1.create \n 2.insert \n 3.delete \n 4.display \n5.Exit\n");
        scanf("%d",&a);
        switch (a)
        {
            case 1: create_list();
		    break;
                
            case 2:printf("enter your choice \n 1.insert in beginning \n 2.insert at end \n 3.insert in a position \n");
                scanf("%d",&b);
                switch(b)
                {
                    case 1: insert_big();
                        break;
                    case 2: insert_end();
                        break;
                    case 3: insert_bet();
                        break;
                    default:printf("wrong choice");
                }
                break;
            case 3:printf("enter your choice \n 1.delete from beginning \n 2.delete from end \n 3.delete from a position \n");
                scanf("%d",&c);
                switch(c)
                {
                    case 1:printf("delete_big()");
                        break;
                    case 2:printf("delete_end()");
                        break;
                    case 3:printf("delete_bet()");
                        break;
                    default:printf("wrong choice\n");
                }
                break;
            case 4:display();
                break;
	    case 5: exit(0);
            default:printf("wrong choice\n");
        }     
    }
    return 0;
}

//creating the list
void create_list()
{
    int n,i;
    struct node  *current, *new;
    printf("enter the number of inputs");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        new=(struct node *)malloc(sizeof(struct node));
        printf("enter element");
        scanf("%d",&new->data);
        if (head==NULL)
        {
            head=new;
            current=head;
        }
        else{
                current->next=new;
                current=new;
        }
    }
    current->next=NULL;
}

//inserting at the beginning
void insert_big()
{
    struct node  *new;
    new=(struct node *)malloc(sizeof(struct node));
    printf("enter value");
    scanf("%d",&new->data);
    if (head==NULL)
    {
        new->next=NULL;
        head=new;
    }
    else
    {
        new->next=head;
        head=new;
    }
}

//inserting at the end
void insert_end()
{
    struct node  *new,*current=NULL;
    new=(struct node *)malloc(sizeof(struct node));
    printf("enter value");
    scanf("%d",&new->data);
    if(head==NULL)
    {
        new->next=NULL;
        head=new;
    }
    else{
        current=head;
        while(current->next !=NULL)
        {
            current=current->next;
        }
        current->next=new;
        new->next=NULL;
    }
}

//inserting at a position
void insert_bet()
{
    int a=1,i,pos;
    struct node  *new,*current;
	
    
    current = head;
    while(current->next!=NULL)
    {
        current=current->next;
        a++;
    }
	printf("%d",a);
	printf("enter the position");
       scanf("%d",&pos);
        if(pos>=2 && pos<a)
        {
		new = (struct node*)malloc(sizeof(struct node));
		printf("Enter value\n");
   		 scanf("%d",&new->data);
            current=head;
            for(i=1;i<(pos-1);i++)
                current=current->next;

            new->next=current->next;
            current->next=new;
        }
    
}

//to display the result
void display()
{
    struct node  *current=head;
    while(current !=NULL)
    {
        printf("%d ",current->data);
        current=current->next;
    }
	printf("\n");
}
