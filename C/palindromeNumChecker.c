#include <stdio.h>
int main() {
  int n, reversenum = 0, originalnum , remainnum;
    printf("Enter integer number to check : ");
    scanf("%d", &n);
    inputnum = n;

    while (n != 0) {
        remainnum = n % 10;
        reversenum = reversenum * 10 + remainnum;
        n /= 10;
    }

    if (inputnum == reversenum)
        printf("Palindrome Number");
    else
        printf("Not a Palindrome Number");

    return 0;
}