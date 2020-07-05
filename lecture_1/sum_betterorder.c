#include <stdio.h>
#include <stdint.h>

// = sum of integers from 1 to max
int32_t sumTo(int32_t max) {
  int32_t i, sum = 0;
  
  for (i=1; i<=max; i++) {
    sum += i;
  }
  return sum;
}

int main(int argc, char **argv) {
  printf("sumTo(5) is: %d\n", sumTo(5));
  return 0;
}
