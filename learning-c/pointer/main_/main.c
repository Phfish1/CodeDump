#include <stdio.h>

// A variable is a memory-address that holds a variable value, the memory-address is representet to us / linked to the variable name.
// When refering to a variable name in C, you access the value at that memory address,
// To access the memory address of a variable itself you use pointers.
// Pointers are data types just like integers.
// You need to specify the datatype of the variable when you are storing its memory-address inside a pointer-variable

int main() {

    // The integer data type specifies how many bytes the memory address should allocate, (integers are 4 bytes, shorts are 2)
    int age = 10; // is the same as: int 7ffdba1714c4 = 10 
    int *pAge = &age; // is the same as int 7ffea30d9820 = 7ffdba1714c4

    // ( & ) is used to point to the memory address of a given variable: { &age } = { 7ffdba1714c4 }
    // ( * ) us used to create pointer variables that store memory addresses of a given datatype { int* pAge } = { 7ffea30d9820 } / Stores a pointer that points to an integer datatype

    printf("%p : %p\n", &pAge, pAge);
}