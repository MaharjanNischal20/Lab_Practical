#include <stdio.h>
#include <conio.h>
#include <math.h>
#define  E 0.0000005

int main()
{
    float A[20][20],x[20],ratio;
    int i,j,k,n;
    printf("Enter the size of matrix:");
    scanf("%d",&n);
    printf("Enter the matrix:");
    for(i=0;i<n;i++)
    {
        for(j=0;j<=n;j++)
        {
            scanf("%f",&A[i][j]);
        }
    }
    for(j=0;j<n;j++)
    {
        if(fabs(A[j][j])<E)
        {
            printf("Error");
            return 1;
        }
        else
        {
            for(i=0;i<n;i++)
            {
                if( i != j)
                {
                    ratio=A[i][j]/A[j][j];
                    for(k=0;k<=n;k++)
                    {
                        A[i][k]=A[i][k]-ratio*A[j][k];
                    }
                }
            }
        }
    }
    printf("The value of matrix by Gauss Jordan Method is :");
    {
        for(i=0;i<n;i++)
        {
            x[i]=A[i][n]/A[i][i];
            printf("\n%f",x[i]);
        }
    }
}