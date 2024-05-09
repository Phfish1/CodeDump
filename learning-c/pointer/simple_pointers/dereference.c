#include <stdio.h>
#include <string.h>

int main() {
    int age = 18;
    int *pAge = &age;

    int **ppAge = &pAge;

    printf("| age   |  (addr): %p  (value): %i\n", &age, age);
    printf("| pAge  |  (addr): %p  (value): %p\n", &pAge, pAge);
    printf("| ppAge |  (addr): %p  (value): %p\n", &ppAge, ppAge);

    // To get the memory address of ppAge use a pointer ( &ppAge ) = 0x7fff41374590
    // To get the value of ppAge reference its normal variable name ( ppAge ) = 0x7fff41374588
    
    // ppAge points to pAge, to get the VALUE of the MEMORY ADDRESS which ppAge is
    // pointing to use ( *ppAge )

    printf("\nMemory address which ppAge points to / value of ppAge: %p\n", ppAge);
    printf("Value at Memory address pointet to by ppAge: %p\n", *ppAge);
    printf("The variable which ppAge is pointing to, find out what memory address it has: %p --> The same as ppAge\n", &*ppAge);

    printf("The value thats pointet to by pointer which ppAge is pointing to: %d\n", **ppAge);
    printf("And its memory address, (gathered from the variable ^): %p --> Same as pAge\n", &**ppAge);
}