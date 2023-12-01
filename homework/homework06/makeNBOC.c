#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <arpa/inet.h>

void makeNBO(int num) { 
    int test_byte = 1;
    char *bytePtr = (unsigned char *) & test_byte;

    if (* bytePtr == test_byte) {
        printf("Your computer is Little-Endian.\n");
        int placeholder = htonl(num);
        printf("%i\n", placeholder);
    } else {
        printf("Your computer is Big-Endian.\n");
    }
}





