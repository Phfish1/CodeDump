#include <stdio.h>


// ( & ) Refers to a a memmory address
// ( int* ) is used to create a pointer { holding a memory address }
// ( *pointer ) is also used as a derefrence operator, refering to the VALUE at the memory address which the pointer points to 


void swap_numbers(int *pNum1, int *pNum2) {
    int temp;

    temp = *pNum1; // Stores the value pointet to by pNum1 in temp
    *pNum1 = *pNum2; // Stores in the memory address which pNum1 is pointing to the value which pNum2 is pointing to
    *pNum2 = temp;


    printf("Temp: %i\n",temp);


    printf("Num1 Pointer (inside function): %p\n", pNum1);


    /* // Only changes the value of the numbers within this function scope
    temp = number1;
    number1 = number2;
    number2 = temp;

    printf("%i", number1);
    */
}

int main() {

    int num1 = 10;
    int num2 = 20;

    //printf("Type number (1): "); scanf("%i", &num1);
    //printf("Type number (2): "); scanf("%i", &num2);

    printf("Numbers typed are: (num1: %i), (num2: %i)\n", num1, num2);

    // The memory address of num1 and num2 are different depending on the function scope, num1 as the parameter number1 are stored in different locations in memmory.
    // But if we pass in the MEMORY ADDRESS (a pointer) to num1, we can edit num1 directly even from another function scope.

    printf("Num1 Pointer (outside function) %p\n", &num1);
    swap_numbers(&num1, &num2);

    printf("Numbers typed are: (num1: %i), (num2: %i)\n", num1, num2);
}

