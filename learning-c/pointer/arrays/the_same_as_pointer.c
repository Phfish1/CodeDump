#include <stdio.h>

int main() {
    int array[] = {1, 2, 3};
    int *pArray = &array[0]; // &array[0] IS THE SAME AS array

    //pArray[0] = 5;
    *(pArray + (1*0)) = 5;

    //printf("%d\n", pArray[0]);
    printf("%d\n", *(pArray + (1 * 2)) ); // The (1 * 2) is not technically needed here but 1 is meant to represent the sizeof(int)
 
    printf("Aray-Index: %p\nPointer-Variable: %p\n", &array[0] + 1, pArray + 1);
}