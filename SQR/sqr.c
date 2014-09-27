#include <stdio.h>
#include <math.h>
#include "sqr.h"

int main() {
    double a = 0, b = 0, c = 0;
    double x1 = 0, x2 = 0;
    printf("Please, enter coefficients a, b and c for quadratic equation.");
    scanf("%lg %lg %lg", &a, &b, &c);
    solOut(x1, x2, solve(a, b, c, &x1, &x2));
    return 0;
}
