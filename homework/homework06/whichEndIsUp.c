/*

TO COMPILE: gcc whichEndIsUp.c -o whichEndIsUp      (Compiles with a warning, however it still runs and produces the deisred output)

*/

#include <stdio.h>

int main() {
    int num = 1;  // 4-byte integer with a value of 1 (00000000 00000000 00000000 00000001)

    // Use a pointer to examine the first byte
    int *bytePtr = (unsigned char *) &num;

    if (*bytePtr == 1) {
        printf("Your computer is Little-Endian.\n");
    } else {
        printf("Your computer is Big-Endian.\n");
    }
    return 0;
}
