#include<stdio.h>
#include<math.h>
#include<stdlib.h>
void equation(int n,int k){
    if (n<=26){
        for(int i=0;i<n;i++){
            if (i!=n-1)
                printf("(%c%d)%c + ",(65+i),k,(122-i));
            if (i==n-1)
                printf("(%c%d)%c",(65+i),k,(122-i));
        }
        printf(" = OUT\n");
    }
}
void printf_2d(int l1,int l2, double a[l1][l2]){
    for(int i=0;i<l1;i++){
        for(int j=0;j<l2;j++){
            if (j!=l2-1){
                if (a[i][j]<0)
                    printf("%lf\t",a[i][j]);
                else
                    printf(" %lf\t",a[i][j]);
            }else{
                if (a[i][j]<0)
                    printf("%lf",a[i][j]);
                else
                    printf(" %lf",a[i][j]);
            }
        }
        if (i!=l1-1)
            printf("\n");
    }
}
void main(){
    int n=0,i=0,j=0,k=0;
    printf("Input Order of equations (n*n) : ");
    scanf("%d",&n);
    double arr[n][n+1], ans[n];
    for (i=0;i<n;i++){
        printf("\n%d> ",(i+1));
        equation(n,i+1);
        for(j=0;j<n+1;j++){
            if(j!=n)
                printf("Input Value of %c%d : ",(65+j),(i+1));
            else
                printf("Input Value of OUT : ");
            scanf("%lf",&arr[i][j]);
        }
    }
    printf("\nOriginal Matrix from Equation:-\n");
    printf_2d(n,n+1,arr);
    for (i=0;i<n;i++){
        for (j=i+1;j<n;j++){
            if (abs(arr[i][i])<abs(arr[j][i])){
                for (k=0;k<n+1;k++){
                    double tmp=arr[i][k];
                    arr[i][k]=arr[j][k];
                    arr[j][k]=tmp;
                }
            }
        }
    }
    printf("\nMatrix after Partial Pivoting:-\n");
    printf_2d(n,n+1,arr);
    for (i=0;i<n-1;i++){
        for (j=i+1;j<n;j++){
            double tmp=arr[j][i]/arr[i][i];
            for (k=0;k<=n;k++){
                arr[j][k]=arr[j][k]-tmp*arr[i][k];
            }
        }
    }
    printf("\nMatrix After Gauss-Elimination:-\n");
    printf_2d(n,n+1,arr);
    for (i=n-1;i>=0;i--){
        ans[i]=arr[i][n];
        for (j=i+1;j<n;j++){
            if (j!=i){
                ans[i]=ans[i]-arr[i][j]*ans[j];
            }
        }
        ans[i]=ans[i]/arr[i][i];
    }
    printf("\nSolution:-");
    for(i=0;i<n;i++){
        printf("\n%c = %lf",(122-i),ans[i]);
    }
}