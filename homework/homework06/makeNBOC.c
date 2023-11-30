#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>   // Include this for atoi
#include <arpa/inet.h>

// Function to determine the endianness of the machine
int isLittleEndian() {
    uint32_t num = 1;
    uint8_t *bytePtr = (uint8_t *)&num;
    return (*bytePtr == 1);
}

// Function to swap byte order to Network Byte Order (big-endian)
uint32_t swapByteOrder(uint32_t value) {
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

    uint32_t inputNumber = atoi(argv[1]);

    uint32_t networkByteOrder = swapByteOrder(inputNumber);

    printf("Original Value: %u\n", inputNumber);
    printf("Network Byte Order: %u\n", networkByteOrder);

    return 0;
}
