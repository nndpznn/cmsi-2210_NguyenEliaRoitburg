#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char * argv[] ) {

    char outputString[25] = "\0";

    // Arrays of letters and NATO alphabet.
    char letters[26] = {"abcdefghijklmnopqrstuvwxyz"};
    char nato[26][10] = {"Alpha", "Bravo", "Charlie", "Delta", "Echo", "Foxtrot", "Golf", "Hotel", "India", "Juliett", "Kilo", "Lima", "Mike", "November", "Oscar", "Papa", "Quebec", "Romeo", "Sierra", "Tango", "Uniform", "Victor", "Whiskey", "Xray", "Yankee", "Zulu"};

    // User input.
    char entry[25] = "";
    printf("Enter a word! Just one, please. ");
    scanf("%s", entry);

    // Debugging. Confirming that scanf properly receives the user input.
    printf("ENTRY: %s \n", entry);

    // Nested loops: loops through the user input letter by letter, and loops through letters[]
    // and compares them. If they're the same, it concatenates it to an output string 
    // and goes to the next line.
    for (int i = 0; i < sizeof(entry); i++) {
        // printf("Checking i: %c \n", entry[i]);

        for (int k = 0; k < sizeof(letters); k++) {
            // printf("Checking k: %c \n", letters[k]);

            if (entry[i] == letters[k]) {
                    // printf("Success! Letter found.\n");
                    // strcat(nato[k], outputString);
                    // strcat("\n", outputString);
                    printf("%s \n", nato[k]);
            }
        }
    }

    // printf("%s", outputString);

}