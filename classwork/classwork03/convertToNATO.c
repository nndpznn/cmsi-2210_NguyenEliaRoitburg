#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char * argv[] ) {

    char outputString[25] = "\0";

    // Arrays of letters and NATO alphabet.
    char *letters[] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"};
    char *nato[] = {"Alpha", "Bravo", "Charlie", "Delta", "Echo", "Foxtrot", "Golf", "Hotel", "India", "Juliett", "Kilo", "Lima", "Mike", "November", "Oscar", "Papa", "Quebec", "Romeo", "Sierra", "Tango", "Uniform", "Victor", "Whiskey", "Xray", "Yankee", "Zulu"};

    // User input.
    char entry[25] = "";
    printf("Enter a word! Just one, please. ");
    scanf("%s", entry);

    // Debugging. Confirming that scanf properly receives the user input.
    printf("ENTRY: %s \n", entry);

    // WIP: using argv to take arguments when executing the program.
    // for (int i = 0; i < sizeof(entry); i++) {
    //     printf("%c \n", entry[i]);
    // }

    // for (int i = 0; i < sizeof(argv[0]); i++) {
        
    //     for (int k = 0; k < sizeof(letters); k++) {
    //         if (argv[0][i] == letters[k]) {
    //             strcat(outputString, nato[k]);
    //         }
    //     }
    // }

    // Nested loops: loops through the user input letter by letter, and loops through letters[]
    // and compares them. If they're the same, it concatenates it to an output string 
    // and goes to the next line.
    for (int i = 0; i < 26; i++) {
        printf("Checking i: %c \n", entry[i]);

        for (int k = 0; k < 26; k++) {
            printf("Checking k: %c \n", letters[k]);

            if (entry[i] == letters[k]) {
                    printf("Success! Letter found.");
                    strcat(nato[k], outputString);
                    strcat("\n", outputString);
            }
        }
    }

    printf("%s", outputString);

}