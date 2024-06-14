#include <stdio.h>

int find_neighbours(int *graph, int *marked_graph, long row_length, long column_length, int next_row, int next_column) {
    
    //Checks if next_row and next_column is within the graph [diameter]
    if (next_row >= 0 && next_row < row_length && next_column >= 0 && next_column < column_length) { // checks if row is 0 or higher but also not higher that size of row
        // Checks if is visited by using the marked_graph
        if ( *(marked_graph + (column_length * next_row) + next_column) != 1) {
            // Checks if it is a rock...
            if ( *(graph + (column_length * next_row) + next_column) == 1) {
                return 1; // Return 1/True if all checks are True
            }
        }
    }
    // If some checks FAIL return 0/False
    return 0;
};

int dfs(int *graph, int *marked_graph, long row_length, long column_length, int row, int column) {
    
    // Base condition to check if current row and column is at its last index
    if (row == row_length-1 && column == column_length-1) {
        // Return 1 if so
        return 1;
    }

    // Takes the memory-address of array[0][0], + (column_length * row) which is the same as array[row] then the specified column, (basically this means array[row][column] )
    //*( (marked_graph) + (column_length * row) + (column)) =  1;
    marked_graph[column + (column_length * row)] = 1;     // TA UT ARK

    // Loop 4 times and store index in direction (Representing the direction we should move through the maze) 
    for (int direction = 0; 4 > direction; direction++) {
        int row_vertecies[] = {-1, +1, 0, 0}; // Direction trough the row 
        int column_vertecies[] = {0, 0, -1, +1}; // Direction trough the column in the mze

        // Takes current direction("vertecies") and adds it to current "row" to find out next row/column
        int next_row = row + row_vertecies[direction];
        int next_column = column + column_vertecies[direction];

        // Call find_neighbours and pass in EVERYTHING
        if (find_neighbours(graph, marked_graph, row_length, column_length, next_row, next_column) == 1) {
            // IF find neighbour checks are all True, CALL dfs with --> "next_row and next_column" <-- this represents moving trough the maze
            if (dfs(graph, marked_graph, row_length, column_length, next_row, next_column) == 1) {
                return 1; // IF BASE FUNCTION IS HIT, Return 1/True (Our maze is solvabole :)
            }
        };
    }

    // Return 0/False if we explored everything and never came to an end ;(
    return 0; 
};

int main() {
    // Initialize 2D Array with 9 Rows and 10 collumns
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

    // Create empty 2D array of 0's with them same size as "maze"
    int marked_maze[sizeof(maze) / sizeof(maze[0])][sizeof(maze[0]) / sizeof(maze[0][0])] = {{0}};

    // Get the lenght of maze Rows and Columns 
    long maze_rows = sizeof(maze) / sizeof(maze[0]); // sizeof returns the size of a varible in bytes
    long maze_columns = sizeof(maze[0]) / sizeof(maze[0][0]);

    // Call dfs which takes pointer to the first addresses of maze and marked_maze
    // Could also be written more simply as "maze" or "marked maze"
    int is_solvable = dfs(&maze[0][0], &marked_maze[0][0], maze_rows, maze_columns, 0, 0);

    // Print 
    printf("Is it solvable: %d\n", is_solvable);
}

