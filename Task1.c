#include <stdio.h>
#include <math.h>

int main(void) {
double a = 0, b = 0, c = 0;
double x1 = 0, x2 = 0;
double m;
printf("Please, enter coefficients a, b and c for quadratic equation");
scanf("%lg %lg %lg", &a, &b, &c);
m = solve(a, b, c, &x1, &x2);
if (m == 2)
    printf("Solutions: %lg and %lg.", x1, x2);
else if (m == 1)
    printf("One solution: %lg.", x1);
else if (m == 0)
    printf("X - any real number");
else (m == -1)
    printf("No solution"); 
return 0;
}

double solve(double a, double b, double c, double *x1, double *x2) { 
if(b==0 && a==0) {
    if(c==0)
        return 0;
    else
        return -1;
}
else if (a==0) {
    *x1 = -c / b;
    return 1;
}
else if (b==0) {
    if (c<0) {
        *x1 = sqtr(-c / a);
        *x2 = -sqrt(-c / a);
        return 2;
    }
    else if (c==0) {
        *x1 = 0;
        return 1;
    }
    else
        return -1;
}
else if(c==0) {
    *x1 = -b / a;
    *x2 = 0;
    return 2;
}
else{
    double d = b*b - 4*a*c;
    if (d > 0) {
        *x1 = (-b + sqrt(d)) / (2 * a);
        *x2 = (-b - sqrt(d)) / (2 * a);
        return 2;
    }
    else if(d==0) {
        *x1 = -b / (2 * a);
        return 1;
    }
    else
        return -1;
}
}
