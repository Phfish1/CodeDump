#include <stdio.h>

int can_visit(int *graph, int *marked_graph, long row_length, long column_length, int next_row, int next_column) {
    if (next_row >= 0 && next_row < row_length && next_column >= 0 && next_column < column_length) { // checks if row is 0 or higher but also not higher that size of row
        if ( *(marked_graph + (column_length * next_row) + next_column) != 1) {
            if ( *(graph + (column_length * next_row) + next_column) == 1) {
                return 1;
            }
        }
    }
    return 0;
};

int dfs(int *graph, int *marked_graph, long row_length, long column_length, int row, int column) {
    if (row == row_length-1 && column == column_length-1) {
        return 1;
    }

    *((marked_graph) + (column_length * row) + (column)) =  1;

    for (int direction = 0; 2 > direction; direction++) {
        int row_vertecies[] = {+1, 0};
        int column_vertecies[] = {0, +1};

        int next_row = row + row_vertecies[direction];
        int next_column = column + column_vertecies[direction];

        
        if (can_visit(graph, marked_graph, row_length, column_length, next_row, next_column) == 1) {
            if (dfs(graph, marked_graph, row_length, column_length, row + row_vertecies[direction], column + column_vertecies[direction]) == 1) {
                return 1;
            }
        };
    }

    return 0;
};

int main() {
    int matrix[][10] = {
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

    

    int marked_matrix[sizeof(matrix) / sizeof(matrix[0])][sizeof(matrix[0]) / sizeof(matrix[0][0])] = {{0}};

    long matrix_rows = sizeof(matrix) / sizeof(matrix[0]);
    long matrix_columns = sizeof(matrix[0]) / sizeof(matrix[0][0]);

    int is_solvable = dfs(&matrix[0][0], &marked_matrix[0][0], matrix_rows, matrix_columns, 0, 0);
    printf("%d\n", is_solvable);
}


