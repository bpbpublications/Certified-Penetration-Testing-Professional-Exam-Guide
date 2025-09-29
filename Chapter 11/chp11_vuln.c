#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
int main() {
    const char* filename = "/tmp/vulnfile";
    // Check if file is writable
    if (access(filename, W_OK) != 0) {
        perror("Access denied");
        exit(1);
    }

    // Open the file and write to it
    int fd = open(filename, O_WRONLY);
    if (fd < 0) {
        perror("Failed to open file");
        exit(1);
    }

    write(fd, "Exploited!\n", 11);
    close(fd);

    printf("Done.\n");
    return 0;
}