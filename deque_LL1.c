/* INPUT RESTRICTED DOUBLE ENDED QUEUE USING LINKED LIST*/
#include<stdio.h>
#include<stdlib.h>

struct dequeue
{
    int data;
    struct dequeue* next;
    struct dequeue* prev;
}*new,*first=NULL,*last=NULL,*temp=NULL;

void create()
{
    new=(struct dequeue*)malloc(sizeof(struct dequeue));
    printf("Enter the element: ");
    scanf("%d",&new->data);
}


void push_end()
{
    create();
    if(first==NULL)
    {
        first=last=new;
        first->prev=NULL;
        last->next=NULL;
    }
    else
    {
        new->prev=last;
        last->next=new;
        new->next=NULL;
        last=new;
    }
    printf("A new element has been added at the end of the list...\n");
}

void pop_beg()
{
    if(first==NULL)
    {
        printf("List is empty!! Data underflow. \n");
        return;
    }

    else if(first->next==NULL) 
    {
        free(first);
        first=NULL;
        
        printf("\n node deleted at the beginning of the list...\n");
    }

    else
    {
        temp=first;
        first=first->next;
        first->prev=NULL;
        free(temp);
        printf("\n node deleted at the beginning of the list...\n");
    }
}

void pop_end()
{
    if(first==NULL)
    {
        printf("List is empty!! Data underflow.\n");
        return;
    }
    else if(first->next==NULL)
    {
        free(first);
        first=NULL;
        printf("\nNode deleted at the end of the list...\n");
    }
    else
    {
        temp=last;
        last=last->prev;
        last->next=NULL;
        free(temp);
        printf("\nNode deleted at the end of the list...\n");
    }
}

void display()
{
    if(first==NULL)
    {
        printf("List is empty!! Cannot display data.\n");
    }
    else
    {
        temp=first;
        while(temp!=NULL)
        {
            printf("%d\t",temp->data);
            temp=temp->next;
        }
    }
}



void input_restricted()
{
    char ch='y';
    int ichoice;
    while(ch=='Y'||ch=='y')
    {
        printf("INPUT RESTRICTED DEQUE\n");
        printf("1.Insert at the end\n2.Delete at the beginning\n3.Delete at the end\n4.Display\n");
        printf("Enter Your Choice: ");
        scanf("%d", &ichoice);
        switch (ichoice)
        {
        case 1:
        push_end();
        printf("\n");
            break;
        case 2:
        pop_beg();
        printf("\n");
            break;
        case 3:
        pop_end();
        printf("\n");
            break;
        case 4:
        display();
        printf("\n");
            break;
        default:
        printf("\n");
            break;
        }
    printf("Do you want to do more operations?...y/n: ");
    scanf("%s",&ch);
    }
}



int main()
{
   input_restricted();
    return 0;
}