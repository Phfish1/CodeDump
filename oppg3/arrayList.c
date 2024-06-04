#include <stdio.h>
#include <stdlib.h>

struct ArrListStruct {
    int *data;
    int size;
};

typedef struct ArrListStruct *arrlist;

struct MatrixStruct {
    arrlist *data;
    int size;
};

typedef struct MatrixStruct *matrixList;


arrlist createArrlist(int *array, int size) {
    arrlist temp;
    temp = (arrlist)malloc( (sizeof(struct ArrListStruct)));
    temp->data = (int *)malloc(sizeof(int) * size);
    temp->size = size;

    for (int i = 0; i < size; i++) {
        temp->data[i] = array[i];
    }

    return temp;
}

matrixList createMatrix(arrlist *matrix, int size) {
    matrixList temp;
    temp = (matrixList)malloc(sizeof(struct MatrixStruct));
    temp->data = (arrlist *)malloc(sizeof(arrlist) * size);
    temp->size = size;

    for (int i = 0; i < size; i++) {
        temp->data[i] = matrix[i];
    }

    return temp;
}

void freeMatrix(matrixList matrix) {
    for (int i = 0; matrix->size > i; i++) {
        free(matrix->data[i]);
    }
}

matrixList spawnMatrix() {
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

    arrlist tmp_matrix[10] = {row0, row1, row2, row3, row4, row5, row6, row7, row8, row9};
    matrixList matrix = createMatrix(tmp_matrix, 10);

    return matrix;
}
