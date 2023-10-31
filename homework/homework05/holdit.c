#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <time.h>



int main(int argc, char* argv[]){
    char start[10];
    printf("This program will see how long you can hold your breath! Type START to start the timer!\n");
    scanf("%s", start);

    if(!(strcmp(start, "start") == 0)){
        printf("Well YOU'RE no fun!");
    } else{
        time_t start_time = time(NULL);
        char stop[10];
        while(1){
            printf("Type STOP when you cannot hold your breath anymore!\n");
            scanf("%s", stop);
            if(!(strcmp(stop, "stop") == 0)){
                continue;
            } else {
                break;
            }
        }

        time_t end_time = time(NULL);
        float elapsed_time = difftime(end_time, start_time);
        printf("%.2f", elapsed_time);
        
    }
        return 0;
    }

