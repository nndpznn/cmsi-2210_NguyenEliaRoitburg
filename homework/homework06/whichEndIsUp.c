#include <stdio.h>

int main() {
    int num = 1;  // 4-byte integer with a value of 1

    // Use a pointer to examine the first byte
    char *bytePtr = (unsigned char *) & num;

    if (* bytePtr == 1) {
        printf("Your computer is Little-Endian.\n");
    } else {
        printf("Your computer is Big-Endian.\n");
    }

    return 0;
}
