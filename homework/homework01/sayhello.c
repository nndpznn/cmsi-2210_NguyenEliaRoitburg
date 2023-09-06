/**
 * file: sayhello.c
 * author: Nolan Nguyen, Adi Roitburg, JD Elia
 * description: asks user for name input and then says hello!
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[] ) {

    char username[30] = "NoneForNow";

    printf("Please enter your name: \n");
    fgets(username, sizeof(username), stdin);

    printf("\n\nHello, %s\n\n", username);

    exit(0);
}
