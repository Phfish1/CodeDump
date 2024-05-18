#include <stdio.h>

void printArray(int *array, long length) {

}

int main() {
    int array[] = {2, 4, 6, 8, 16};
    long array_length = sizeof(array) / sizeof(array[0]);


    for (long i=0; i < array_length; i++) {
        printf("Address: %p\n", array + i); // Use this when getting the address (the-same-as): { &array[i] || &(array[0] + i) || &(array + (1 * i)) }
        printf("Value: %d\n\n", array[i]); // Use this when accessing the value (the-same-as): { *(array + i) || *(array + (1 *i)) || *(array[0] + i)}
    }

    // Use this when reading the value of an array
}