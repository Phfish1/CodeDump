#include <stdio.h>
#include <stdlib.h>

struct bestPath {
    int cost;

    int **path;
    int pathRows;
    int pathColumns;

};

int getPath(struct bestPath *pShortest, int index) { // Allocate memory to array pointed to by pShortest.path[i]
    int *newPath = malloc(sizeof(int) * 2);
    newPath[0] = 1 + index;
    newPath[1] = 2 + index;

    pShortest->path[index] = newPath;
}

int printMatrix(struct bestPath *pShortest) {
    for (int i = 0; i < pShortest->pathRows; i++) {
        for (int j = 0; j < pShortest->pathColumns; j++) {
            printf("[%i][%i]: %i\n", i, j, pShortest->path[i][j]);
        }
    }
}

int freeMatrix(struct bestPath *pShortest) {
    for (int i = 0; i < pShortest->pathRows; i++) {
        free(pShortest->path[i]);
    }
    free(pShortest->path);
}

int main() {
    // Define structure variables
    struct bestPath shortest;
    shortest.cost = 0;
    shortest.pathRows = 0;
    shortest.pathColumns = 2;
    shortest.path = malloc(0 * sizeof(int *));

    // Allocate memory to +1 integer pointer AND keep track of array size, // Call getPath  
    for (int i = 0; 2 > i; i++) {
        shortest.path = realloc(shortest.path, (i+1) * sizeof(int *)); // I just asume it allocates memory correctly each time :)
        shortest.pathRows += 1;
        getPath(&shortest, i);        
    }

    printMatrix(&shortest);
    freeMatrix(&shortest);

}