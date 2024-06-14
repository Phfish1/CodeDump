#include <stdio.h>
#include <stdlib.h>

// ARRAY LIST are faster than LinkedList in our case!

// An array list is a list that dynamically allocates memory (For Eduard) "Resizable Array" 
// It stores the DATA and its SIZE

// We will make it 2D, so we are going to make an Array of pointers to arrays

// Create structure that stores pointer to Data and the size/lengths
// This represents our colomns, 
struct ArrListStruct {
    int *data;
    int size;
};

// Define arrlist datatype
typedef struct ArrListStruct *arrlist;

// Create structure to store pointer to arrays, specifically our newly created "arrlist" datatype
// Size / length means how many arrlist are in the matrixStruct
struct MatrixStruct {
    arrlist *data;
    int size;
};

// Define datatype of matrixList
typedef struct MatrixStruct *matrixList;

// Takes in array, and its size.
arrlist createArrlist(int *array, int size) {
    // Initializes arrlist called temp
    arrlist temp;
    // Allocates memory to temp

    // Returs arraylist pointer, size to allocate = size of ArrListStructure ONLY
    temp = (arrlist)malloc( (sizeof(struct ArrListStruct)));
    
    // Allocates each element inside the array,
    // Returns int pointer, representing the first address to start from
    temp->data = (int *)malloc(sizeof(int) * size);
    
    // Stores the size
    temp->size = size;

    // Loops trough the size of our array and add it to the array which temp stores
    for (int i = 0; i < size; i++) {
        // Assigns to "temp Array [i]" what is at our array[i]
        temp->data[i] = array[i];
    }

    return temp;
}

matrixList createMatrix(arrlist *matrix, int size) {
    // Does the same as createArraylist but changes the DATATYPE stored in temp to "arrlist"

    matrixList temp;
    // Allocate matrix struct
    temp = (matrixList)malloc(sizeof(struct MatrixStruct));

    // Allocate the entire size of matrix with arrlist pointer as the data it stores
    temp->data = (arrlist *)malloc(sizeof(arrlist) * size);
    temp->size = size;

    // Loop trough array of pointers given and add it to our matrix
    for (int i = 0; i < size; i++) {
        temp->data[i] = matrix[i];
    }

    return temp;
}

// Free the hog and all subhoggers
void freeMatrix(matrixList matrix) {
    for (int i = 0; matrix->size > i; i++) {
        free(matrix->data[i]); // Subhogger
    }
    
    free(matrix);
}

matrixList spawnMatrix() {
    // Create new array for each row
    int tmp0[1] = {0};
    int tmp1[2] = {2, 4};
    int tmp2[3] = {0, 5, 6};
    int tmp3[4] = {7, 2, 9, 10};
    int tmp4[5] = {25, 11, 1, 0, 5};
    int tmp5[6] = {1, 88, 51, 88, 61, 4};
    int tmp6[7] = {93, 12, 73, 36, 71, 65, 34};
    int tmp7[8] = {233, 5, 2, 1, 6, 7, 55, 1};
    int tmp8[9] = {16, 111, 213, 9, 23, 433, 1, 34, 13};
    int tmp9[10] = {5, 23, 453, 789, 123, 200, 212, 345, 556, 99};
    int tmp10[11] = {100, 322, 44, 51, 123, 44, 55, 661, 999, 102, 123};

    // Make each row tmpArray into an ArrayList
    arrlist row0 = createArrlist(tmp0, sizeof(tmp0) / sizeof(tmp0[0]));
    arrlist row1 = createArrlist(tmp1, sizeof(tmp1) / sizeof(tmp1[0]));
    arrlist row2 = createArrlist(tmp2, sizeof(tmp2) / sizeof(tmp2[0]));
    arrlist row3 = createArrlist(tmp3, sizeof(tmp3) / sizeof(tmp3[0]));
    arrlist row4 = createArrlist(tmp4, sizeof(tmp4) / sizeof(tmp4[0]));
    arrlist row5 = createArrlist(tmp5, sizeof(tmp5) / sizeof(tmp5[0]));
    arrlist row6 = createArrlist(tmp6, sizeof(tmp6) / sizeof(tmp6[0]));
    arrlist row7 = createArrlist(tmp7, sizeof(tmp7) / sizeof(tmp7[0]));
    arrlist row8 = createArrlist(tmp8, sizeof(tmp8) / sizeof(tmp8[0]));
    arrlist row9 = createArrlist(tmp9, sizeof(tmp9) / sizeof(tmp9[0]));
    arrlist row10 = createArrlist(tmp10, sizeof(tmp10) / sizeof(tmp10[0]));


    // Combine each arrayList into an ArrayList
    arrlist tmp_matrix[11] = {row0, row1, row2, row3, row4, row5, row6, row7, row8, row9, row10};
    
    // Make arrayList into a 2D matrix 
    // This is needed because of typedef in structure arrList can only store an integer pointer
    matrixList matrix = createMatrix(tmp_matrix, 11);

    return matrix;
}
