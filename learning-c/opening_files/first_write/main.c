#include <stdio.h>


int main() {
  FILE *filePointer = fopen("example.txt", "w");

  fprintf(filePointer, "Hello world\nHi Jim :)");
  
  fclose(filePointer);
}