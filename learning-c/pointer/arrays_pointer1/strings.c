#include <stdio.h>
#include <string.h>


int main() {
    int age = 18;
    int *pAge = &age;

    char initial = 'P';
    char name[] = "Philip";

    for (int i = 0; i < strlen(name); i++) {
        printf("%p\n", &name[i]);
    }
}