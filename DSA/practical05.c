//Singly linked list

#include <stdio.h>
#include <conio.h>
#include<malloc.h>

int item;
struct Node
{
    int info;
    struct Node *next;
};
typedef struct Node NodeType;
NodeType *head;
struct Node *head=NULL;

void InsertAtBeg()
{
printf("Enter item to be inserted:");
scanf("%d",&item);
NodeType *nNode;
nNode=(NodeType*)malloc(sizeof(NodeType));
nNode->info=item; 
nNode->next=head; 
head=nNode;
}

void insert_at_gvnpos()
{
    printf("Enter item to be inserted:");
    scanf("%d",&item);
    NodeType *nNode;
    NodeType *temp;
    temp=head;
    int p,i;
    nNode=(NodeType*)malloc(sizeof(NodeType));
    nNode->info=item;
    if(head==NULL)
    {
        nNode->next=NULL;
        head=nNode;
    }
    else
    {
        printf("Enter Position of a node at which you want to insert an new node:\n");
        scanf("%d",&p);
        for(i=1;i<p-1;i++)
        {
            temp=temp->next;
        }
        nNode->next=temp->next;
        temp->next=nNode;
    }
}
void insert_atend()
{
    printf("Enter item to be inserted:");
    scanf("%d",&item);
    NodeType *nNode;
    NodeType *temp;
    temp=head;
    nNode=(NodeType*)malloc(sizeof(NodeType));
    nNode->info=item;
    if(head==NULL)
    {
        nNode->next=NULL;
        head=nNode;
    }
    else{
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        nNode->next=NULL;
        temp->next=nNode;
    }
}

void delet_at_beg()
{
    NodeType *temp; 
    if(head==NULL)
    {
        printf("Void deletion \n"); 
        return;
    }
    else 
    { 
        temp=head; 
        head=head->next; 
        free(temp);
    }
}
void delete_atend()
{
    NodeType *hold,*temp;
    if(head==NULL)
    {
        printf("Void Deletion \n");
        return;
    }
    else if(head->next==NULL)
    {
        hold=head;
        head=NULL;
        free(hold);
    }
    else{
        temp=head;
        while(temp->next->next!=NULL)
        {
            temp=temp->next;
        }
        hold=temp->next;
        temp->next=NULL;
        free(hold);
    }
}
void delet_at_nthnode()
{
    NodeType *hold,*temp;
    int pos,i;
    if(head==NULL)
    {
        printf("Void Deletion \n");
        return;
    }
    else
    {
        temp=head;
        printf("Enter position of node which node is to be deleted:\n");
        scanf("%d",&pos); 
        for(i=1;i<pos-1;i++)
        {
            temp=temp->next;
        }
        hold=temp->next; 
        temp->next=hold->next;
        free(hold); 
    }
}
void display()
{
    if (head == NULL)
    {
        printf("The list is empty:");
    }
    else
    {
        NodeType *temp = head;
        printf("\nThe list is :\n");
        while (temp != NULL)
        {
            printf("%d\t",temp->info);
            temp = temp->next;
        }
        printf("\n");
    }
}
int main()
{
    int n;
    do
    {
        printf("\n1.Insert first \n2.Insert at given position \n3.Insert at last \n4.Delete first node \n5.delete last node \n6.delete nth node \n7.Display\n");
        scanf("%d",&n);
        switch(n)
        {
            case 1:
            InsertAtBeg();
            break;
            case 2:
            insert_at_gvnpos();
            break;
            case 3:
            insert_atend();
            break;
            case 4:
            delet_at_beg();
            break;
            case 5:
            delete_atend();
            break;
            case 6:
            delet_at_nthnode();
            break;
            case 7:
            display();
            break;
            default:
            printf("Enter appropriate number please:");
            break;
        }
    } while (n!=0 && n<8);
}