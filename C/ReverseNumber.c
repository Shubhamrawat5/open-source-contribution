#include <stdio.h>
int main() {

    int num, reversenum = 0, remainder;
    printf("Enter integer number : ");
    scanf("%d", &num);

    while (num != 0) {
        remainder = num % 10;
        reversenum = reversenum * 10 + remainder;
        num /= 10;
    }

    printf("Reversed number : %d", reversenum);

    return 0;
}