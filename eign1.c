#include<stdio.h>
#include<conio.h>
#include<math.h>
void main()
{
    int i,j,n;
    float A[40][40],x[40],z[40],e[40],zmax,emax;
    printf("Input Order of Square Matrix : ");
    scanf("%d",&n);
    printf("Enter Matrix Elements:-\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%f",&A[i][j]);
        }
    }
    printf("\nEnter The Initial Non-Zero Approximations:-\n");
    for(i=0;i<n;i++){
        printf("x[%d]=",(i+1));
        scanf("%f",&x[i]);
    }
    do{
        for(i=1;i<=n;i++){
            z[i]=0;
            for(j=1;j<=n;j++){
                z[i]=z[i]+A[i][j]*x[j];
            }
        }
        zmax=fabs(z[1]);
        for(i=2;i<=n;i++){
            if((fabs(z[i]))>zmax)
                zmax=fabs(z[i]);
        }
        for(i=1;i<=n;i++){
            z[i]=z[i]/zmax;
        }
        for(i=1;i<=n;i++){
            e[i]=0;
            e[i]=fabs((fabs(z[i]))-(fabs(x[i])));
        }
        emax=e[1];
        for(i=2; i<=n; i++){
            if(e[i]>emax)
                emax=e[i];
        }
        for(i=1; i<=n; i++){
            x[i]=z[i];
        }
    }
    while(emax>0.001);
    printf("\n The required eigen value is %f",zmax);
    printf("\n\nThe required eigen vector is :\n");
    for(i=1; i<=n; i++)
    {
        printf("%f\t",z[i]);
    }
    getch();
}