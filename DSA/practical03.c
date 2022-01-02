//Linear queue

#include <stdio.h>
#include <conio.h>
#define MAX 10
int rear=-1,front=0,item;
int queue[MAX];
void enqueue()
{
    if(rear>=MAX-1)
    {
        printf("Queue overflow");
    }
    else
    {
        printf("Enter the value to be inserted:");
        scanf("%d",&item);
        rear+=1;
        queue[rear]=item;
    }
}
void dequeue()
{
    if(rear<front)
    {
        printf("Queue underrflow");
    }
    else
    {
        front+=1;
    }
}
void display()
{
    int i;
    if(rear<front)
    {
        printf("queue is empty");
    }
    else
    {
        for(i=front;i<=rear;i++)
        {
            printf("%d\t",queue[i]);
        }
    }
}
int main()
{
    int n;
    do
    {
    printf("Select choice /n 1.Enqueue /n 2.Dequeue /n 3.Display");
    scanf("%d",&n);
    switch(n)
    {
        case 1:
        enqueue();
        break;
        case 2:
        dequeue();
        break;
        case 3:
        display();
        break;
        default:
        {
            printf("Please Enter appropriate number 1,2,3....Thank You");
        }
        break;
    }
    }while(n!=0 && n<4);
    return 0;
}