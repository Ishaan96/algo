#include<stdio.h>
struct node
{
    int data;
    struct node *next;
}*head=NULL,*t,*new,*rear=NULL;
int main()
{
    int ch;
    while(1)
    {
        printf("1.Push\n2.Pop\n3.Display\n4.Exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: push();
                break;
            case 2: pop();
                break;
            case 3: show();
                break;
            case 4: exit(0);
        }
    }
    return 0;
}
void push()
{
    new=(struct node*)malloc(sizeof(struct node));
    printf("Enter element to push: ");
    scanf("%d",&new->data);
    if(head==NULL)
    {
        head=new;
        rear=new;
    }
    else
    {
        rear->next=new;
        rear=new;    
    }
    rear->next=NULL;
}
void pop()
{
    if(head==NULL)
        printf("Queue is empty\n");
    else if(head==rear)
    {    
    new=head;
    head=NULL;
    printf("Popped element: %d",new->data);
    free(new);
    }
    else
    {
        new=head;
        head=head->next;
        printf("Popped element: %d",new->data);
         free(new);
    }  
}
void show()
{
    if(head==NULL)
        printf("Queue is empty\n");
    else if(head==rear)
        printf("%d ",head->data);
    else
    {
        t=head;
        while(t->next != NULL)
        {
            printf("%d ",t->data);
            t=t->next;
        }
    }
}