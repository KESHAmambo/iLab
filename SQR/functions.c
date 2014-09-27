#include "sqr.h"

void solOut(double x1, double x2, int m) {
if (m == 2)
    printf("Solutions: %lg and %lg.", x1, x2);
else if (m == 1)
    printf("One solution: %lg.", x1);
else if (m == -1)
    printf("X - any real number");
else (m == 0)
    printf("No solution"); 
}

double solve(double a, double b, double c, double *x1, double *x2) { 
if(b==0 && a==0) {
    if(c==0)
        return -1; // x- any real number
    else
        return 0; // no solutions
}
else if (a==0) {
    *x1 = -c/b;
    return 1; // one solution
}
else if (b==0) {
    if (c<0) {
        *x1 = sqtr(-c / a);
        *x2 = -sqrt(-c / a);
        return 2; // two solutions
    }
    else if (c==0) {
        *x1 = 0;
        return 1; // one solution
    }
    else
        return 0; // no solutions
}
else if(c==0) {
    *x1 = -b/a;
    *x2 = 0;
    return 2; // two solutions
}
else{
    double d = b*b - 4*a*c;
    if (d > 0) {
        *x1 = (-b + sqrt(d)) / (2 * a);
        *x2 = (-b - sqrt(d)) / (2 * a);
        return 2; // two solutions
    }
    else if(d==0) {
        *x1 = -b / (2 * a);
        return 1; // one solution
    }
    else
        return 0; // no solutions
}
