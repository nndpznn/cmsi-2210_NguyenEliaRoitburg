#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]){
    if(argc != 2){
        printf("Stop being funny, because you're not.");
    } 

    int N = atoi(argv[1]);
    printf("\t");

    for(int o = 2; o <= N; o++){
        printf("%d\t", o);
    }

    for(int i = 2; i <= N; i++){
        printf("\n");
        for(int j = 1; j <= N; j++){
            int num = i * j;
            printf("%d\t", num);
        }
    }
    return 0;
}