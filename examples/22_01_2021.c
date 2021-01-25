#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void main(){
    const int N = 10000;
    const int M = 20000;

    clock_t begin, end;
    double time_spent;

    begin = clock();
    // ===============================
    int** pp1;
    pp1 = (int**)malloc(N * sizeof(int*));
    for(int i = 0; i < N; i++){
        pp1[i] = (int*)malloc(M * sizeof(int));
    }// pp1[i][j]

    for(int i = 0; i < N; i++){
        free(pp1[i]);
    }
    free(pp1);
    // ===============================
    // N+1 раз
    // ===============================
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("N+1: %.8f\n", time_spent);



    begin = clock();
    // ===============================
    int* p2;
    p2 = (int*)malloc(N * M * sizeof(int));// p2[i*N + j]

    free(p2);
    // ===============================
    // 1 раз
    // ===============================
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("1: %.8f\n", time_spent);



    begin = clock();
    // ===============================
    int** pp3;
    int* p3;
    pp3 = (int**)malloc(N * sizeof(int*));
    p3 = (int*)malloc(N * M * sizeof(int));

    for(int i = 0; i < N; i++){
        pp3[i] = p3 + i * M;
    }// pp3[i][j]

    free(pp3);
    free(p3);
    // ===============================
    // 2 раза
    // ===============================
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("2: %.8f\n", time_spent);



    begin = clock();
    // ===============================
    int** pp4;
    pp4 = (int**)malloc(N * sizeof(int*) + N * M * sizeof(int));
    pp4[0] = (int*)(pp4 + N);

    for(int i = 0; i < N; i++){
        pp4[i] = pp4[0] + i * M;
    }// pp4[i][j]

    free(pp4);
    // ===============================
    // 1 раз
    // ===============================
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("1: %.8f\n", time_spent);

}