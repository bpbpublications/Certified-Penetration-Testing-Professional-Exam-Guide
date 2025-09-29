#include <stdio.h>
#include <string.h>
void vulnerable() {
    char buffer[64];
    gets(buffer);  // no bounds checking = dangerous!
}
int main() {
    vulnerable();
    return 0;
}