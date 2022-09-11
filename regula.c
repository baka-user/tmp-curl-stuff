#include <stdio.h>
#include <math.h>
#define f(x) pow(x,3)-3*x
#define accuracy (1/pow(10,6))
double regula_falsi(double a, double b,int max_itr){
    double x=0,fa=0,fb=0;
    int n=0;
    printf("\nSL.NO.\t\ta\t\t\tb\t\t\tx\t\t\tf(x)");
    do{
        n++;
        fa=f(a),fb=f(b);
        x=(b*fa-a*fb)/(fa-fb);
        printf("\n%2d\t%.15lf\t%.15lf\t%.15lf\t%.15lf",n,a,b,x,f(x));
        if (fabs(f(x))<accuracy){
            break;
        }
        if(fa*f(x)<0){
            a=x;
        }else{
            b=x;
        }
    }while (max_itr==0?fabs(f(x))>=accuracy:n<max_itr);
    return x;
}
void main(){
    double a=0,b=0;
    int max_itr=0;
    printf("[a, b] is the range of the funtion f(x)=0, which has at least one root in it.\nEnter The Value of a & b : ");
    scanf("%lf %lf",&a,&b);
    printf("Enter Maximum Number of Iteration (0=no limit) : ");
    scanf("%d",&max_itr);
    double ans = regula_falsi(a,b,max_itr);
    printf("\nRoot = %lf",ans);
}