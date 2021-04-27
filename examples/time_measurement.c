#include <stdio.h>
#include <time.h>


void main(){

    clock_t begin, end;
    double time_spent;

    begin = clock();
    // ===============================
    //
    // Какой-то код, время исполнения которого ы измеряем
    //
    // ===============================
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Some text: %.8f\n", time_spent);

}