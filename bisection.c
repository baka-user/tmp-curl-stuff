#include <stdio.h>
#include <math.h>

#define f(x) x*cos(x)
#define accuracy (1/pow(10,10))
int z = 0;
double bisection(double c, double d, int max_itr){
    double a,b;
    if (f(c)>=f(d))
        a=d,b=c;
    else
        a=c,b=d;
    if(a==b)
        return 0;
    z++;
    double x = (a+b)/2,ans;
    if (z>max_itr && max_itr !=0){
        return x;
    }
    if (z==1){
        printf("\nSL.NO.\t\tA\t\t\tB\t\t\tx\t\t\tf(x)");
    }
    printf("\n%2d\t%.15lf\t%.15lf\t%.15lf\t%.15lf",z,a,b,x,f(x));
    if (fabs(f(x))<=accuracy){
        return x;
    }
    if (f(x)<0){
        ans=bisection(x,b,max_itr);
    }
    if (f(x)>0){
        ans=bisection(a,x,max_itr);
    }
    return ans;
}

void main(){
    double a=0,b=0;
    int max_itr=0;
    printf("[a, b] is the range of the funtion f(x)=0, which has at least one root in it.\nEnter The Value of a & b : ");
    scanf("%lf %lf",&a,&b);
    printf("Enter Maximum Number of Iteration (0=no limit) : ");
    scanf("%d",&max_itr);
    double ans = bisection(a,b,max_itr);
    printf("\nRoot = %lf",ans);
}