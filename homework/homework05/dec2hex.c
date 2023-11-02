#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void convertToHex(int decimal, int numbits) {

    if (numbits != 32 && numbits != 64) {
        printf("Number of bits must be either 32 or 64.");
    }

    int binEquivalent[numbits];
    int bytesum;
    char* hexEquivalent[numbits / 4];
    int hexindex = 0;

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
    // convert four bits at a time into HEX.
    for (int bit = 0; bit < numbits; bit = bit + 4) {

        bytesum = 8*binEquivalent[bit] + 4*binEquivalent[bit+1] + 2*binEquivalent[bit+2] + binEquivalent[bit+3];
        if (bytesum > 9) {
            switch (bytesum)
            {
            case 10:
                hexEquivalent[hexindex] = "A";
                break;
            case 11:
                hexEquivalent[hexindex] = "B";
                break;
            case 12:
                hexEquivalent[hexindex] = "C";
                break;
            case 13:
                hexEquivalent[hexindex] = "D";
                break;
            case 14:
                hexEquivalent[hexindex] = "E";
                break;  
            case 15:
                hexEquivalent[hexindex] = "F"; 
            
            default:
                printf("... How did this happen???");
                break;
            }
        }
        else {
            hexEquivalent[hexindex] = bytesum;
        }
        hexindex++;
    }

    for (int i = 0; i < numbits / 4; i++) {
        printf("Digit: %c\n", hexEquivalent[i]);
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

