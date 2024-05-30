#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows = 20;
    int columns = 2;
    int *array = malloc((rows * columns) * sizeof(int));

    for (int i = 0; i < (rows * columns); i++) {
        array[i] = i +1;
    }

    printf("%d\n", array[19]);


    free(array);
}