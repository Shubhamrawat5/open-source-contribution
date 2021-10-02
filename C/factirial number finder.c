#include <stdio.h>
int main() {
    int n, i;
    unsigned long long factorial = 1;
    printf("Enter integer: ");
    scanf("%d", &n);

    if (n < 0)
        printf("Negative number factorials do not exist !!! Try with positive Number");
    else {
        for (i = 1; i <= n; ++i) {
            fact *= i;
        }
        printf("Factorial of %d : %llu", n, fact);
    }

    return 0;
}