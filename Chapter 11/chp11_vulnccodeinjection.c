#include <stdio.h>
#include <string.h>
void vulnerable() {
    char buffer[100];
    printf("Enter some data:\n");
    gets(buffer);  // ❌ Unsafe function: no bounds checking
}
int main() {
    vulnerable();
    return 0;
}