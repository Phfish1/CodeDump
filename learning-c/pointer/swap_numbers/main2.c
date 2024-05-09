#include <stdio.h>

void *swap_numbers(int *first, int *second) { // ( int *first ) just initialises first to a variable able to contain a pointer
    int *temp; // Temp pointerVariable to store memory addresses
    temp = first;
    printf("Parameter values:\n first: %p\n second: %p\n\n", first, second);
    printf("Parameters addresses:\n &First: %p\n &Second: %p\n", &first, &second); // The parameters first and second are not directly passed from main() to swap_numbers() but exists in their own SEPERATE MEMORY ADDRESSES inside the swap_number() memory block

    first = second; // This just changes the value of first to the value of second
    first = temp; // this moves the value at temp into the variable first

    //To change the variable at which first is pointing to use the derefrence operator ( * ) This is confusing because the same operator is used to initialize a pointer variable. 
    // the Dereference operator ( * ), is not used after the initalization process, only the varaible name ( "first" )

    printf("%d\n", *first); // Prints the value at ( "first" )

    *first = 25; // Changes the variable the memory address value of ( "first" ) is pointing to.

    // VARIABLE = VALUE
    // *first = 25          // derefrence memory address to change the variable 
    // number = *first      // derefrence memory address to extract variable

    *first = *second; 
    // first is dereferences using ( * ), its on the VARIABLE side of the equal ( = ) sign, so it refers to the VARIABLE stored at first's memory address. 
    // second is also dereferenced but its on the VALUE side (right side) of the equal sign ( = ) so it refers to the VALUE at the memory address stored in the "second" Variable
    


    *second = *temp; // This does not work BECAUSE the value of temp is the memory address stored in first, BUT first is now equal to ( 100 )!!! WE MUST STORE the VALUE of first inside temp NOT its memory address ((( SEE main3.c )))
    printf("\n%p\n", temp);

}

int main() {
    int num1 = 25;
    int num2 = 100;

    printf("Main variable addresses:\n Num1: %p\n Num2: %p\n\n", &num1, &num2);
    swap_numbers(&num1, &num2);
    
    //printf("a\n");
    printf("\nNum1: %d\nNum2: %d\n", num1, num2);


}
 