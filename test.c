#include <except.h>
#include <stdio.h>

extern Exception DivideByZero;

float divide(int a, int b) {
  if(0 == b) {
    raise(DivideByZero);
  } 
  return (float) a / (float)b;
}

int main() {
  
  int a,b;

  puts("Enter numerator and denominator...?");
  scanf("%d %d", &a, &b);

  try {
    printf("Ratio is: %f...\n",divide(a,b));
  } catch {
    match(DivideByZero) {
       printf("Caught divide by zero...\n");
    }
  }
  return 0;
}


