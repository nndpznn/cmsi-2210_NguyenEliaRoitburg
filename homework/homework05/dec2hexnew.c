#include <stdio.h>
#include <stdlib.h>

void convertToHex(int, int);
char convertDigit(int);

void convertToHex(int decimal, int bitcount) {

    char hexEquivalent[bitcount];
    int hexIndex = bitcount-1;

    for (int i=0; i<bitcount; i++) {
        hexEquivalent[i] = '0';
    }

    while (decimal != 0 && hexIndex >= 0) {
        int dividend = decimal % 16;
        hexEquivalent[hexIndex] = convertDigit(dividend);
        hexIndex = hexIndex - 1;
        decimal = decimal / 16;
    }

    for (int i = 0; i < bitcount; i++) {
        printf("%c", hexEquivalent[i]);
    }
    
}

int main(int argc, char * argv[]) {

    int decimalVersion;
    int bitcount;
    if (argc == 1) {
        bitcount = 32;
    } else {
        int userinput = atoi(argv[1]); 
        bitcount = userinput;
    }

    printf("Enter the decimal number you'd like to convert to hex: ");
    scanf("%d", &decimalVersion);
    printf("This is your decimal number: %d\n", decimalVersion);
    printf("... And this is your hex number!\n");
    convertToHex(decimalVersion, bitcount);
    return 0;
}

char convertDigit(int digit) {
    switch (digit) 
        {
        case 0:
            return '0';
        case 1:
            return '1';
        case 2:
            return '2';
        case 3:
            return '3';
        case 4:
            return '4';
        case 5:
            return '5';
        case 6:
            return '6';
        case 7:
            return '7';
        case 8:
            return '8';
        case 9:
            return '9';
        case 10:
            return 'A';
        case 11:
            return 'B';
        case 12:
            return 'C';
        case 13:
            return 'D';
        case 14:
            return 'E';
        case 15:
            return 'F';
        default:
            return '\n';
        }
}