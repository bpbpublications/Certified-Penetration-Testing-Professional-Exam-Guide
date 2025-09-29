#include <stdio.h>
#include <limits.h>
int main() {
    int max = INT_MAX;  // INT_MAX is 2147483647 on a 32-bit system
    printf("Before Overflow: %d\n", max);
    max = max + 1;  // This causes overflow
    printf("After Overflow: %d\n", max);  // Will wrap around to negative number
    return 0;
}