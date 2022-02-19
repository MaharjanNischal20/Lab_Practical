#include <stdio.h>
#include <conio.h>
#include <math.h>

float f(float x)
{
    return 1/(1+pow(x,2));
}

int main()
{
    int i,n;
    float a,b,h,S2=0,I,S1,k;
    printf("Enter the no. of strips:");
    scanf("%d",&n);
    printf("\nEnter the lower bound:");
    scanf("%f",&a);
    printf("\nEnter the Higher bound:");
    scanf("%f",&b);
    h=(b-a)/n;
    S1=f(a)+f(b);
    for(i=1;i<=n-1;i++)
    {
        k=a+i*h;
        S2=S2+f(k);
    }
    I=(h/2)*(S1+2*S2);
    printf("The Required value of Integration is:%f",I);
    getch();
}