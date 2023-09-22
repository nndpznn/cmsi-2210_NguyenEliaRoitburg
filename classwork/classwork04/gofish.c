/*
Program: Go Fish!
Authors: Nolan Nguyen, Adi Roitburg, JD Elia
Description: This program should take user input until its limit, add 
up the numbers, display that, average the numbers, display that, 
then count through all of the entries and return how many sevens there are.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USER_INPUT 25
#define MAX_INPUT_SIZE 10

int main( int argc, char * argv[] ) {

    char input[MAX_INPUT_SIZE];
    int total = 0;
    char bigstring[50] = "";
    double avg;
    int count = 0;
    int num_of_sevens = 0;

    printf( "   hello, world!\n" );

    for( int i = 0; i < MAX_USER_INPUT; i++ ) {
        printf( "\n  enter an integer: " );
        fgets( input, 10, stdin);
        printf( "\n     got: %s", input );

        if (atoi(input) == -9999 ) {         // Exit clause. Enter -9999 to conclude user input.
            break;
        }
        count++;

        total += atoi(input); 

        strncat(bigstring, input, MAX_USER_INPUT);
        
    }

    for (int i = 0; i < strlen(bigstring); i++) {
        if (bigstring[i] == '7') {
            num_of_sevens++;
        }
    }

    printf("TOTAL: %d", total);

    avg = (double) total / count;
    printf("\nAVERAGE: %f", avg);

    printf("\nTOTAL INPUT: %s", bigstring);                 // For some reason, they print out all on different lines... but it works!
    printf("\nYAHOO! I FOUND %d SEVENS!", num_of_sevens);

    exit(0);
}