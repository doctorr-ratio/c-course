#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ERROR_FILE_OPEN -3
#define FILE_PATH "folder/test"
#define LENGTH_1 12
#define LENGTH_2 8
#define DIMENSIONS 2


void main() {
    FILE* file;
    int number[LENGTH_1][LENGTH_2], buffer[LENGTH_1][LENGTH_2] = {0};
    srand(time(NULL));
    size_t shape_out_1 = LENGTH_1, shape_out_2 = LENGTH_2, shape_in_1, shape_in_2, dim_out = DIMENSIONS, dim_in;
 
    file = fopen(FILE_PATH, "wb");
    if (file == NULL) {
        printf("File didn't open!\n");
        exit(ERROR_FILE_OPEN);
    }
    for(int i = 0; i < shape_out_1; i++) {
        for(int j = 0; j < shape_out_2; j++) {
            number[i][j] = j + i*shape_out_2;
        }
    }
    fwrite(&dim_out, sizeof(size_t), 1, file);
    fwrite(&shape_out_1, sizeof(size_t), 1, file);
    fwrite(&shape_out_2, sizeof(size_t), 1, file);
    for(int i = 0; i < shape_out_1; i++) {
        for(int j = 0; j < shape_out_2; j++) {
            fwrite(&number[i][j], sizeof(int), 1, file);
        }
    }
    fclose(file);

    file = fopen(FILE_PATH, "rb");
    if (file == NULL) {
        printf("File didn't open!\n");
        exit(ERROR_FILE_OPEN);
    }

    fread(&dim_in, sizeof(size_t), 1, file);
    fread(&shape_in_1, sizeof(size_t), 1, file);
    fread(&shape_in_2, sizeof(size_t), 1, file);
    for(int i = 0; i < shape_out_1; i++) {
        fread(&buffer[i], sizeof(int), shape_in_1 * shape_in_2, file);
    }
    fclose(file);
    for(int i = 0; i < shape_in_1; i++) {
        for(int j = 0; j < shape_in_2; j++) {
            printf("%d\t", buffer[i][j]);
        }
        printf("\n");
    }
    for(int i = 0; i < shape_in_1; i++) {
        for(int j = 0; j < shape_in_2; j++) {
            printf("%d\t", number[i][j]);
        }
        printf("\n");
    }
}