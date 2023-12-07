#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void convertToHex(int decimal, int numbits) {

    if (numbits != 32 && numbits != 64) {
        printf("Number of bits must be either 32 or 64.");
    }

    printf("Your decimal number: %d\n", decimal);
    printf("Number of bits: %d\n", numbits);

    int binEquivalent[numbits];
    char hexEquivalent[numbits/4];
    int bytesum;

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

    printf("Here's the binary intermediate number: \n");
    for (int i = 0; i < numbits; i++) {
        printf("%d", binEquivalent[i]);
    }

    for (int i = 0; i < sizeof(hexEquivalent); i++) {
        hexEquivalent[i] = "0";
    }

    printf("\n");
    printf("Here's the hex array before filling: \n");
    printf("%s", hexEquivalent);
    printf("\n");

    // Now we have a binary number stored in binEquivalent, and we just need to
    // convert four bits at a time into HEX.
    int bit;
    // int hexindex = 0;
    char* temp;
    for (bit = 0; bit < numbits; bit = bit + 4) {

        printf("Current bit: %d\n", bit);

        bytesum = 8*binEquivalent[bit] + 4*binEquivalent[bit+1] + 2*binEquivalent[bit+2] + binEquivalent[bit+3];
        printf("Bytesum: %d\n",bytesum);
        switch (bytesum)
        {
        case 10:
            temp = "A";
            strcat(hexEquivalent, temp);
            printf("A");
            break;
        case 11:
            temp = "B";
            strcat(hexEquivalent, temp);
            printf("B");
            break;
        case 12:
            temp = "C";
            strcat(hexEquivalent, temp);
            printf("C");
            break;
        case 13:
            temp = "D";
            strcat(hexEquivalent, temp);
            printf("D");
            break;
        case 14:
            temp = "E";
            strcat(hexEquivalent, temp);
            printf("E");
            break;  
        case 15:
            temp = "F";
            strcat(hexEquivalent, temp);;
            printf("F");
            break; 
        
        default:
            temp = (char)bytesum;
            strcat(hexEquivalent, temp);
            break;
        }
        // hexindex++;
    }

    for (int i = 0; i < (numbits/4); i++) {
        printf("%s\n", hexEquivalent);
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

