#include <stdio.h>
#include <math.h>

void convertToDecimal(int decimal) {

    int binEquivalent[32];
    for (int i=0; i<32; i++) {
        binEquivalent[i] = 0;
    }
    
    double two_divisor = pow(2,31);

    for (int power_index = 0; power_index < 32; power_index++) {
        if (decimal >= two_divisor) {
            binEquivalent[power_index] = 1;
            decimal = decimal - two_divisor;

        }
        two_divisor = two_divisor / 2;
    }

    for (int i = 0; i < 32; i++) {
        printf("%d", binEquivalent[i]);
    }
    
}

int main(int argc, char * argv[]) {

    int decimalVersion;

    printf("Enter the decimal number you'd like to convert to binary: ");
    scanf("%d", &decimalVersion);
    printf("This is your decimal number: %d\n", decimalVersion);
    convertToDecimal(decimalVersion);
    return 0;
}