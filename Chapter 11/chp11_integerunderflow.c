#include <stdio.h>
#include <limits.h>
int main() {
    int min = INT_MIN;  // INT_MIN is -2147483648 on a 32-bit system
    printf("Before Underflow: %d\n", min);
    min = min - 1;  // This causes underflow
    printf("After Underflow: %d\n", min);  // Will wrap around to positive number
    return 0;
}