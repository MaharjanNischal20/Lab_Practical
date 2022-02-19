#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>

float maxm(float M[],int n) // changed int to float
{
    int i;
    float max; // changed int to float
    max=M[0];
        for(i=1;i<n;i++) // need not start from 0
        {
            if(fabs(M[i])>fabs(max))
            {
                max=fabs(M[i]);
            }
        }
return max;
}
int main()
{
    int n,i,j,count=0;
    float A[10][10]; // changed to float from int
    float lamda,MAXERROR,X[10],Z[10],Y[10],diff[10];
    printf("Enter the size of an array:");
    scanf("%d",&n);
    for(i=0;i<n;i++) // started from 0
    {
        for(j=0;j<n;j++)// started from 0
        {
            printf("A[%d][%d]:",i,j);
            scanf("%f",&A[i][j]); // changed to float
        }
    }
    for(i=0;i<n;i++)
    {
        printf("X[%d]:",i);
        scanf("%f",&X[i]);
    }

    do
    {
        for(i=0;i<n;i++)
        {
            Z[i]=0;
            for(j=0;j<n;j++)
            {
                Z[i]+=A[i][j]*X[j];
            }
        }
        lamda=maxm(Z,n);
        for(i=0;i<n;i++)
        {
            Y[i]=Z[i]/lamda;
            diff[i]=fabs(Y[i]-X[i]);
        }
        for(i=0;i<n;i++)
        {
            X[i]=Y[i];
        }
        MAXERROR=maxm(diff,n);
        count++;
        if(count>100)
        {
            exit(0);
        }

        } while (fabs(MAXERROR)>0.0005);  //MAXERROR may be negative so taking absolute value
printf("\nThe greatest Eigen Value is: %f\n",lamda);
for(i=0;i<n;i++)
{
    printf("%f",Y[i]);
    printf("\n");
}
}
