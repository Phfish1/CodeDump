#include <stdio.h>

int find_neighbours(int *graph, int *marked_graph, long row_length, long column_length, int next_row, int next_column) {
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

    // Takes the memory-address of array[0][0], + (column_length * row) which is the same as array[row] then the specified column, (basically this means array[row][column] )
    *((marked_graph) + (column_length * row) + (column)) =  1;

    for (int direction = 0; 4 > direction; direction++) {
        int row_vertecies[] = {-1, +1, 0, 0};
        int column_vertecies[] = {0, 0, -1, +1};

        int next_row = row + row_vertecies[direction];
        int next_column = column + column_vertecies[direction];

        
        if (find_neighbours(graph, marked_graph, row_length, column_length, next_row, next_column) == 1) {
            if (dfs(graph, marked_graph, row_length, column_length, row + row_vertecies[direction], column + column_vertecies[direction]) == 1) {
                return 1;
            }
        };
    }

    return 0;
};

int main() {
    int maze[9][10] = {
        {1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
        {1, 0, 1, 0, 1, 1, 1, 1, 0, 1 },
        {1, 1, 1, 0, 1, 1, 0, 1, 0, 1 },
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 1 },
        {1, 1, 1, 0, 1, 1, 1, 1, 1, 1 },
        {1, 0, 1, 1, 1, 1, 0, 1, 0, 0 },
        {1, 0, 1, 0, 0, 0, 0, 0, 0, 1 },
        {1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
        {1, 1, 0, 0, 0, 1, 1, 1, 0, 1 }
    };
    /*int maze[3][3] = {
        {1, 1, 1},
        {1, 0, 1},
        {0, 1, 1}
    };*/

    int marked_maze[sizeof(maze) / sizeof(maze[0])][sizeof(maze[0]) / sizeof(maze[0][0])] = {{0}};

    long maze_rows = sizeof(maze) / sizeof(maze[0]);
    long maze_columns = sizeof(maze[0]) / sizeof(maze[0][0]);

    int is_solvable = dfs(&maze[0][0], &marked_maze[0][0], maze_rows, maze_columns, 0, 0);
    printf("%d\n", is_solvable);
}

