#include <stdio.h>


// An array is just bits of information right beside each other in memory, the variable name of the array refers to the memory address of the first element in the array
// An array in C are POINTERS, 


int main() {
    int array[] = {10, 25, 99, 140};

    printf("Array[0] Value: %i\n", array[0]); // Array[index] gives you the value of the memory address in the specified index
    printf("Array start (0): %p\n", array); // The variable name "array" is pointer to the first memory address of the first element in the array

    
    for (int i=1; i < 4; i++) {
        printf("Array item (%i): %p\n", i, &array[i]); // This
        printf("Array item (%i): %p\n", i, array + i); // Is the same as this (array + 1, means increment the array index by 1),
        // Bassically you take the array memory address and increment it with ( 1*SizeOfArray_Datatype ) which == 4.
    };



    // This is the best way to iterate throug an array
    for (int i=0; i < 4; i++) {
        printf("%i\n", *(array + i) );
    };

}