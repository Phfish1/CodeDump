#include <stdio.h>
#include <stdlib.h>

int matrix[][10] = {
    { 272, 362, 965, 995, 603, 909, 758, 390, 709, 693 },
    { 665, 600, 806, 201, 905, 688, 294, 860, 6, 501 },
    { 362, 454, 902, 479, 632, 78, 469, 255, 650, 755 },
    { 337, 927, 535, 858, 839, 236, 813, 457, 360, 482 },
    { 153, 742, 367, 793, 749, 870, 413, 81, 961, 165 },
    { 937, 88, 291, 35, 325, 580, 912, 15, 777, 779 },
    { 813, 638, 641, 918, 140, 758, 755, 522, 745, 12 },
    { 902, 978, 273, 9, 80, 498, 850, 863, 651, 123 },
    { 262, 104, 32, 735, 780, 177, 327, 175, 667, 128 },
    { 45, 344, 622, 627, 349, 184, 802, 400, 701, 550 }
};

long row_length = sizeof(matrix) / sizeof(matrix[0]);
long column_length = sizeof(matrix[0]) / sizeof(matrix[0][0]);

int *current_path;
int current_cost;

int *shortest_path;
int shortest_path_cost;

int canVisit(int next_row, int next_column) {
    if (next_row >= 0 && next_row < row_length && next_column >= 0 && next_column < column_length) { // checks if row is 0 or higher but also not higher that size of row
        if ( *(marked_matrix + (column_length * next_row) + next_column) != 1) {
            if ( *(matrix + (column_length * next_row) + next_column) == 1) {
                return 1;
            }
        }
    }
}

int dijkstras(int row, int column) {
    if (row == row_length-1 && column == column_length-1) {
        return 1;
    };

    for (int i = 0; i < 2; i++) {
        int row_vertecies[] = {+1, 0};
        int column_vertecies[] = {0, +1};


        int nextRow = row + row_vertecies[i];
        int nextColumn = column + column_vertecies[i];

        if (canVisit(nextRow, nextColumn)) {
            printf("Row: %d | Column: %d\n", row, column);
            if (dijkstras(nextRow, nextColumn) == 1) {
                printf("Visits: %d: %d\n", row, column);
                return 1;
            }   
        }
    }



    return 0;
};


int main() {
    dijkstras(0, 0);

};
