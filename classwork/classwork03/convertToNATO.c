#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char * argv[] ) {

    char outputString[25] = "\0";
    int index = 0;

    char letters[30] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"};
    char nato[30] = {"Alpha", "Bravo", "Charlie", "Delta", "Echo", "Foxtrot", "Golf", "Hotel", "India", "Juliett", "Kilo", "Lima", "Mike", "November", "Oscar", "Papa", "Quebec", "Romeo", "Sierra", "Tango", "Uniform", "Victor", "Whiskey", "Xray", "Yankee", "Zulu"};

    char entry[25] = "";
    printf("Enter a word! Just one, please. ");
    scanf("%s", entry);

    printf("ENTRY: %s \n", entry);

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

    for (int i = 0; i < sizeof(entry); i++) {
        // printf("Checking i: %d", i);

        for (int k = 0; k < sizeof(letters); k++) {
            // printf("Checking k: %d", k);

            if (entry[i] == letters[k]) {
                    printf("Success! Letter found.");
                    strcat(nato[k], outputString);
                    strcat("\n", outputString);
            }
        }
    }

    printf("%s", outputString);

}