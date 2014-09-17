#include <stdio.h>
#include <math.h>
int main(void) {
double a=0, b=0, c=0;//int, float ,unsigned int,char(один символ)
scanf("%lg %lg %lg",&a,&b,&c);
if(b==0 && a==0){
 if(c==0){
  printf("x-любое");
 else
  printf("корней нет");
}
else if(a==0){
 double x=-c/b;
 printf("%lg",x);
}
else if(b==0){
 if(c<0){
  double x=sqtr(-c/a);
  double y=-x;
  printf("корни: %lg и %lg",x,y);
 }
 else if(c==0){
  double x=0;
  printf("один корень: %lg",x);
 }
 else
 printf"корней нет");
else{
 double d=b*b-4*a*c;
 if(d>0){
  double x=(-b+sqrt(d))/(2*a);
  double y=(-b+sqrt(d))/(2*a);
  printf("корни: %ld и %lg",x,y);
 }
 else if(d==0){
  double x=-b/(2*a);
  printf("один корень: %lg",x);
  }
 else
  printf("корней нет");
}

  return 0;
}
