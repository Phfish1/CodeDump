#include<stdio.h>
#include<stdlib.h>
#include "linkedList.c"

int matrix[10][10] = {
    { 272, 362, 965, 995, 603, 909, 758, 390, 709, 693 } ,
    { 665, 600, 806, 201, 905, 688, 294, 860, 6, 501 } ,
    { 362, 454, 902, 479, 632, 78, 469, 255, 650, 755 } ,
    { 337, 927, 535, 858, 839, 236, 813, 457, 360, 482 } ,
    { 153, 742, 367, 793, 749, 870, 413, 81, 961, 165 } ,
    { 937, 88, 291, 35, 325, 580, 912, 15, 777, 779 } ,
    { 813, 638, 641, 918, 140, 758, 755, 522, 745, 12 } ,
    { 902, 978, 273, 9, 80, 498, 850, 863, 651, 123 } ,
    { 262, 104, 32, 735, 780, 177, 327, 175, 667, 128 } ,
    { 45, 344, 622, 627, 349, 184, 802, 400, 701, 550 }
};
long matrix_rows = sizeof(matrix) / sizeof(matrix[0]);
long matrix_columns = sizeof(matrix[0]) / sizeof(matrix[0][0]);
node current_path = NULL;
int current_cost = 0;

node find_next_paths(int row, int column) {
    int row_vertecies[2] = {1, 0};
    int column_vertecies[2] = {0, 1};

    node valid_paths = NULL;

    for(int i = 0; i < 2; i++) {
        int next_row = row + row_vertecies[i];
        int next_column = column + column_vertecies[i];

        if ( (0 <= next_row && next_row < matrix_rows) && (0 <= next_column && next_column < matrix_columns) ) {
            int *subArray = createPathArray(next_row, next_column);
            valid_paths = addNode(valid_paths, subArray);
        }

    }
    
    return valid_paths;
}

int dijkstras(int row, int column) {
    if (row == matrix_rows-1 && column == matrix_columns-1) {
        //printf("Cost: %i\n", current_cost);
        return 1;
    }

    node next_paths = find_next_paths(row, column);

    node p = next_paths;
    while (p != NULL) {
        current_path = addNode(current_path, createPathArray(next_paths->data[0], next_paths->data[1]));
        current_cost += matrix[next_paths->data[0]][next_paths->data[1]];
        
        if ( dijkstras(next_paths->data[0], next_paths->data[1]) == 1) {
            current_path = popNode(current_path);
            current_cost -= matrix[next_paths->data[0]][next_paths->data[1]];
        }
        // IF dikjstas()
        // current_cost -= cost at path
        // curren_path.pop()

        /*
        for (int i = 0; i < 2; i++) {
            printf("%i\n", p->data[i]);
        }*/
        p = p->next;
    }
    
    if (current_path != NULL) {
        current_cost -= matrix[next_paths->data[0]][next_paths->data[1]];
        current_path = popNode(current_path);
    }



    freeList(next_paths);
}

int main() {
    dijkstras(0, 0);

    freeList(current_path);
};