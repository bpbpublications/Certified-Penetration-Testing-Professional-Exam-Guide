#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *name;
void vulnerable_function() {
    char *buffer = (char *)malloc(64);
    printf("Enter your name: ");
    fgets(buffer, 64, stdin);

    // Freeing memory that will be used later
    free(name);
    name = buffer;
}

void print_name() {
    printf("Hello, %s\n", name);
}

int main() {
    vulnerable_function();
    print_name();  // This will eventually use the freed 'name' pointer
    return 0;
}