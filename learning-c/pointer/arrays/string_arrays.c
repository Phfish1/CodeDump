#include <stdio.h>

// A pointer is a VARIABLE
// An Array-Name is NOT

int my_strlen(char *string) {
    int string_len;

    while (*string != '\0') {
        string++;
        string_len++;
    }
    return string_len;
}

char* space_string(char *string) {
    char new_string[256];
    char *pNew_string = &new_string[0];
    char *pString = string;


    int i;
    for (i = 0; *pString != '\0'; pString++) {
        
        *(new_string + i) = *pString;
        i++;
        *(new_string + i) = ' ';
        i++;
    }
    new_string[i+1] = '\0';


    for (int i = 0; *pNew_string != '\0'; i++) {
        pNew_string++;
        *(string +i) = *(new_string + i);
    }

    return string;
};

int main() {
    char my_string[256] = "Hello world";

    int string_length = my_strlen(&my_string[0]);
    printf("\nString length of: ( %s )\nis: %d\n", space_string(my_string), string_length);
}