#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(){
    char buffer[256];
    int counter = 0, stop = 0;
    char** pp;
    float meanStrlen = 0;

    pp = (char**) malloc(sizeof(char*));

    while(stop == 0){
        scanf("%255s", buffer);
        pp[counter] = (char*)malloc(strlen(buffer) + 1);
        strcpy(pp[counter], buffer);
        counter++;
        pp = (char**)realloc(pp, (counter + 1) * sizeof(char*));
        if(strcmp("STOP", buffer) == 0){
            stop = 1;
        }
    }

    for(int i=0; i < counter; i++){
        printf("%s\n", pp[i]);
        meanStrlen += strlen(pp[i]);
    }

    printf("%.2f\n", meanStrlen / counter);

    for(int i=0; i < counter; i++){
        free(pp[i]);
    }

    free(pp);
}