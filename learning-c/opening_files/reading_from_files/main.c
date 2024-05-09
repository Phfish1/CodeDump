#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fpointer = fopen("example.txt", "r"); // fopen() now has an ARGUMENT of ( "r" )
    
    //fprintf(fpointer, "Hello world\nThis is line 2\n and 3 :)");

    char line[255]; // string Variable to store first line
    fgets(line, 255, fpointer); // Line = Variable to store line, 255 = max line size, fpointer = pointer to file (starts at first line of file)
    // What fgets also does, is to increment the fpointer to point to the next line of the file, so when calling the function again you will get the NEXT line :)
    printf("%s", line);

    fgets(line, 255, fpointer);
    printf("%s", line);


    fclose(fpointer);
}