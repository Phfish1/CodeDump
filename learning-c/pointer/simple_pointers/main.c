#include <stdio.h>

int change_number(int *num1) {
    *num1 = 100;
}

int main() {
    int num1;

    printf("%p\n", &num1);
    
    change_number(&num1);

    printf("%i\n", num1);
}