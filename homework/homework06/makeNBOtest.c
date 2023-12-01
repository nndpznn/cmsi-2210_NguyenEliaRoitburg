#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>   
#include <arpa/inet.h>

int isLittleEndian() {
    long num = 1;
    uint8_t *bytePtr = (uint8_t *)&num;
    if (*bytePtr == 1) {
        return 1;
    } else {
        return 0;
    }
}

test(int num){
    if (isLittleEndian() == 1){
        printf("LITTLE ENDIAN");
        long var = 5;
        printf("Result: %ld", var);
    } else {
        printf("IS BIG EDNDIAN\n");
        printf("Result: %i", num);

    }

    




}