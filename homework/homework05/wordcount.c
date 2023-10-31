#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Incorrect amount of files");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Could not open the file.\n");
        return 1;
    }

    int word_count = 0;
    int in_word = 0;  // Variable that keeps track of if we are in a word or not

    int c;
    while ((c = fgetc(file)) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n') {
            if (in_word) {
                in_word = 0;
            }
        } else {
            if (!in_word) {
                in_word = 1;
                word_count++;
            }
        }
    }

    fclose(file);
    printf("Word count in %s: %d\n", argv[1], word_count);

    return 0;
}