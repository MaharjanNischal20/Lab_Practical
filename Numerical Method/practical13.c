//Rk 2 method 

#include<stdio.h>
#include<conio.h>

#define f(x,y) x+y

int main()
{
 float x0, y0, xn, h, yn, k,k1,k2;
 int i, n;
 printf("Enter Initial Condition\n");
 printf("x0 = ");
 scanf("%f", &x0);
 printf("y0 = ");
 scanf("%f", &y0);
 printf("Enter calculation point xn = ");
 scanf("%f", &xn);
 printf("Enter number of steps: ");
 scanf("%d", &n);

 /* Calculating step size (h) */
 h = (xn-x0)/n;

 /* Rk 2 Method */
 printf("\nx0\ty0\tk\tyn\n");
 printf("------------------------------\n");
 for(i=0; i < n; i++)
 {
    k1 = h*f(x0, y0);
    k2=h*f((x0+h),(y0+k1));
    k=(k1+k2)/2;
  yn = y0 + k;
  printf("%.4f\t%.4f\t%0.4f\t%.4f\n",x0,y0,k,yn);
  y0 = yn;
  x0 = x0+h;
 }

 /* Displaying result */
 printf("\nValue of y at x = %0.2f is %0.3f",xn, yn);

 getch();
 return 0;
}