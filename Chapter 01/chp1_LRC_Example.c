#include <stdio.h>
typedef unsigned char BYTE;
typedef unsigned short WORD;
BYTE LRC(BYTE *nData, WORD wLength) {
    BYTE nLRC = 0;
    for (int i = 0; i < wLength; i++)
        nLRC += *nData++;
    return (BYTE)(-nLRC);
}

int main() {
    BYTE data[] = {0x01, 0x02, 0x03, 0x04}; // Sample data
    WORD length = sizeof(data)/sizeof(data[0]);
    BYTE lrc = LRC(data, length);
    printf("LRC: 0x%02X\n", lrc);
    return 0;
} // End: LRC