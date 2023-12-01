#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <arpa/inet.h>


// Function to determine the endianness of the machine
int isLittleEndian() {
    long num = 1;
    uint8_t *bytePtr = (uint8_t *)&num;
    if (*bytePtr == 1) {
        return 1;
    } else {
        return 0;
    }
}


// Function to swap byte order to Network Byte Order (big-endian)
long swapByteOrder(int value) {
    if (isLittleEndian()) {
        return htonl(value);
    } else {
        return value;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <number>\n", argv[0]);
        return 1;
    }

    long inputNumber = atoi("50");

    long networkByteOrder = swapByteOrder(inputNumber);

    printf("Original Value: %ld\n", inputNumber);
    printf("Network Byte Order: %ld\n", networkByteOrder);

    return 0;
}
