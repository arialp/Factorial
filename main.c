#include <stdio.h>
#include "math.h"

double factorial(int num){
  int _num = num;
  double prod = 1;
  while(_num > 1){
    prod *= _num;
    _num--;
  }
  return prod;
}

double exponentialCalculator(int precision, int x){
  double euler = 0;
  int index = 0;
  while(precision > 0){
    euler += pow(x, index) / (factorial(index));
    index++;
    precision--;
  }
  return euler;
}

static inline double eulerEstimate(int precision){
  return exponentialCalculator(precision, 1);
}

int main(void){
  int precision;
  printf("%s","Precision:");
  scanf("%d", &precision);
  int x;
  printf("%s","Power (for exp):");
  scanf("%d", &x);
  double fact, euler, exp;
  
  fact = factorial(precision);
  printf("%d! equals %.0f\n", precision, fact);
  
  euler = eulerEstimate(precision);
  printf("Euler with precision %d is %.*f\n", precision, precision,
         euler);
  
  exp = exponentialCalculator(precision, x);
  printf("e^%d with precision %d equals %.*f\n", x, precision,
         precision, exp);
  
  return 0;
}
