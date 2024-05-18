#include <stdio.h>
#include <stdlib.h>

struct shortest_path
    {
        int cost;
        int path[][2];
    };
    

int can_visit(int *graph, long row_length, long column_length, int next_row, int next_column) {
    if (next_row >= 0 && next_row < row_length && next_column >= 0 && next_column < column_length) { // checks if row is 0 or higher but also not higher that size of row
            return 1;
        }
    return 0;
};

int dijkstras(int *graph, long row_length, long column_length, int current_cost, int *current_path, int row, int column) {
    struct shortest_path shortest_path;

    if (row == row_length-1 && column == column_length-1) {
        return 1;
    }

    

    for (int direction = 0; 2 > direction; direction++) {
        int row_vertecies[] = {+1, 0};
        int column_vertecies[] = {0, +1};

        int next_row = row + row_vertecies[direction];
        int next_column = column + column_vertecies[direction];

        if (can_visit(graph, row_length, column_length, next_row, next_column) == 1) {
            if (dijkstras(graph, row_length, column_length, current_cost, current_path, (row + row_vertecies[direction]), (column + column_vertecies[direction])) == 1) {
                printf("Visits: %d: %d\n", row, column);
                
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
    long row_length = sizeof(matrix) / sizeof(matrix[0]);
    long column_length = sizeof(matrix[0]) / sizeof(matrix[0][0]);

    int current_cost = 0;
    int current_path[][2] = {};

    int is_solvable = dijkstras(&matrix[0][0], row_length, column_length, current_cost, &current_path[0][0], 0, 0);
}


