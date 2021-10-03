#include <stdio.h>
int main() {

  int i, num;

  int term1 = 0, term2 = 1;
  int nextTerm = term1 + term2;

  printf("Enter number of terms = ");
  scanf("%d", &num);

  printf("Fibonacci Series: %d, %d, ", term1, term2);

  for (i = 3; i <= num; ++i) {
    printf("%d, ", nextTerm);
    term1 = term2;
    term2 = nextTerm;
    nextTerm = term1 + term2;
  }

  return 0;
}