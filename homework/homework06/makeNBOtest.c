/*

TO LINK: gcc makeNBOC.c makeNBOtest.c -o makeNBOtest        (Links with a warning, but produces desired output)
TO RUN: ./makeNBOtest

*/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>   
#include <arpa/inet.h>

extern void makeNBO(int num);

int main(int argc, char* argv[]){
    makeNBO(5);
    return 0;
}    




