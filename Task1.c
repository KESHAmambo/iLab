#include <stdio.h>
#include <math.h>
int main(void) {
double a=0, b=0, c=0;
printf("Please, enter coefficients a, b and c for quadratic equation");
scanf("%lg %lg %lg",&a,&b,&c);
if(b==0 && a==0){
    if(c==0)
        printf("x- any real number");
    else
        printf("no solutions");
}
else if(a==0){
    double x=-c/b;
    printf("%lg",x);
}
else if(b==0){
    if(c<0){
        double x=sqtr(-c/a);
        double y=-x;
        printf("two solutions: %lg and %lg",x,y);
    }
    else if(c==0){
        double x=0;
        printf("one solution: %lg",x);
    }
    else
        printf"no solutions");
}
else if(c==0){
    double x=-b/a;
    double y=0;
    printf("two solutions: %lg and %lg",x,y);
else{
    double d=b*b-4*a*c;
    if(d>0){
        double x=(-b+sqrt(d))/(2*a);
        double y=(-b+sqrt(d))/(2*a);
        printf("two solutions: %lg and %lg",x,y);
    }
    else if(d==0){
        double x=-b/(2*a);
        printf("one solution: %lg",x);
    }
    else
    printf("no solutions");
}

  return 0;
}
