#include <stdio.h>

void printArray(int *array, long rows, long collumns) {
    for (int i = 0; rows > i; i++)  {
        for (int j = 0; collumns > j; j++) {
            int current_entry = *( array + j + (i * collumns));
            printf("%d\n", current_entry);
        }
    }
    //printf("%d\n", *(array+1));
}

int main() {
    int matrix[2][3] = { 
        {10, 25, 39}, 
        {48, 53, 62} 
    };

    long matrix_rows = sizeof(matrix) / sizeof(matrix[0]);
    long matrix_collumns = sizeof(matrix[0]) / sizeof(matrix[0][0]);

    printf("%p\n", matrix);
    printf("%p\n\n", matrix + 1);
    //printf("%lu\n", matrix_rows);
    printArray(&matrix[0][0], matrix_rows, matrix_collumns);
}