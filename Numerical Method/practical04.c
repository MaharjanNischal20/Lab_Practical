#include <stdio.h>
#include <conio.h>
#include <math.h>
# include <stdlib.h>
#define E 0.0000005

float f(float x)
{
    return x*x-4*x-9;
}
float g(float y)
{
    return 2*y-4;
}

void main()
{
    float x,x0,diff;
    int count=0;
    printf("Enter the value of x0:\n");
    scanf("%f",&x0);
    do
    {
        count++;
        if(fabs(g(x0))<E)
        {
            printf("Error due to function");
            exit(0);
        }
        else if(count>100)
        {
            printf("Error due to count");
            exit(0);
        }
        else
        {
            x=x0-f(x0)/g(x0);
            diff=fabs(x-x0);
            x0=x;
        }
    }while(diff>E);
    printf("The value of x is :%f",x);
}
