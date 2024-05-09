#include <stdio.h>

void swap_numbers(int *num1, int *num2) {

    int temp;

    temp = *num1; // Stores the value of the memory address which num2 points to 
    *num1 = *num2; // Inside the VARIABLE which num1 points to store the VALUE of which num2 points to
    *num2 = temp; // inside the VARAIBLE which num2 points to store temp, AKA the VALUE which num1 pointed to BEFORE it got rewriten to 100 / value which num2 points to

    printf("Numbers are now swapped ( %p / %d -> %d ) & ( %p / %d -> %d )\n", num1, *num2, *num1, num2, *num1, *num2);

};

int main() {
    int number1 = 25;
    int number2 = 100;

    printf("Number1: %d\nNumber2:%d\n\n", number1, number2);

    swap_numbers(&number1, &number2);

    printf("\nNumber1: %d\nNumber2:%d\n", number1, number2);

};