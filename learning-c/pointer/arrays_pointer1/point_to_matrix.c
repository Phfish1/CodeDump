#include <stdio.h>

int main() {
    int array[3] = { 10, 15, 35};
    int *pArray = array;

    for (int i = 0; i < 3; i++) {
        printf("%p\n", &array[i]);
    }
    
    printf("\nArray:   %p\nPointer: %p\n", array, pArray);
    //printf("%l>u\n", sizeof(array) / sizeof(array[0]));


}