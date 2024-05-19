#include <stdio.h>
#include <stdlib.h>

struct bestPath {
    int cost;

    int **path;
    int pathRows;
    int pathColumns;

};

int getPath(struct bestPath *pShortest, int index) {
    //printf("shortest.cost: %i\n", pShortest->cost);
    //printf("shortest.path: %i", *pShortest->path);

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

int main() {
    struct bestPath shortest;
    shortest.cost = 0;
    shortest.pathRows = 0;
    shortest.pathColumns = 2;

    shortest.path = malloc(1 * sizeof(int *));
    shortest.pathRows += 1;
    getPath(&shortest, 0);

    shortest.path = realloc(shortest.path, 2 * sizeof(int *));
    shortest.pathRows += 1;
    getPath(&shortest, 1);

    //printf("%p\n", shortest.path[0]);
    printMatrix(&shortest);
    

    free(shortest.path);

}