#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void convertToHex(int decimal, int numbits) {

    if (numbits != 32 && numbits != 64) {
        printf("Number of bits must be either 32 or 64.");
    }

    int binEquivalent[numbits];

    for (int i=0; i<numbits; i++) {
        binEquivalent[i] = 0;
    }
    
    double two_divisor = pow(2,numbits-1);

    for (int power_index = 0; power_index < numbits; power_index++) {
        if (decimal >= two_divisor) {
            binEquivalent[power_index] = 1;
            decimal = decimal - two_divisor;

        }
        two_divisor = two_divisor / 2;
    }
    // Now we have a binary number stored in binEquivalent, and we just need to
    // four bits at a time into HEX.


    for (int i = 0; i < numbits; i++) {
        printf("%d", binEquivalent[i]);
    }
    
}

int main(int argc, char * argv[]) {

    int decimalVersion;
    int bitcount = atoi(argv[1]);

    printf("Enter the decimal number you'd like to convert to hex: ");
    scanf("%d", &decimalVersion);
    printf("This is your decimal number: %d\n", decimalVersion);
    printf("... And this is your hex number!\n");
    convertToHex(decimalVersion, bitcount);
    return 0;
}