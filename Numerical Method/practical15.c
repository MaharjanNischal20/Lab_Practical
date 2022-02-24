//Simultaneous 1st Order ODE using Rk 4 method 

#include<stdio.h>
#include<conio.h>

double f1( double X , double Y , double Z)
{
    return(3*X + Y - Z);
}

double f2(double X , double Y , double Z)
{
    return(2*X - Y + Z);
}
int main()
{
 float x0, y0, xn, h, yn, k,k1,k2,k3,k4,l1,l2,l3,l4,z0,l;
 int i, n;
 printf("Enter Initial Condition\n");
 printf("x0 = ");
 scanf("%f", &x0);
 printf("y0 = ");
 scanf("%f", &y0);
 printf("z0 = ");
 scanf("%f", &z0);
 printf("Enter calculation point xn = ");
 scanf("%f", &xn);
 printf("Enter number of steps: ");
 scanf("%d", &n);

 /* Calculating step size (h) */
 h = (xn-x0)/n;

 /* Rk 4 Method */
 printf("\nx0\ty0\tz0\tyn\n");
 printf("------------------------------\n");
 for(i=0; i < n; i++)
 {
        k1 = h*f1(x0,y0,z0);
        l1 = h * f2(x0,y0,z0);

        k2= h * f1(x0+(h/2),y0+(k1/2),z0+(l1/2));
        l2= h * f2(x0+(h/2),y0+(k1/2),z0+(l1/2));

        k3= h * f1(x0+(h/2),y0+(k2/2),z0+(l2/2));
        l3= h * f2(x0+(h/2),y0+(k2/2),z0+(l2/2));

        k4 = h * f1(x0+h,y0+k3,z0+l3);
        l4 = h * f2(x0+h,y0+k3,z0+l3);

        k=(k1+(2*k2) + (2*k3) + (k4))/6;
        l=(l1+(2*l2) + (2*l3) + (l4))/6;
  yn = y0 + k;
  printf("%.4f\t%.4f\t%0.4f\t%.4f\n",x0,y0,z0,yn);
  y0 = yn;
  x0 = x0+h;
  z0 = z0+l;
 }

 /* Displaying result */
 printf("\nValue of y and z  at x = %0.2f is y=%0.3f,z=%0.3f",xn, yn,z0);

 getch();
 return 0;
}