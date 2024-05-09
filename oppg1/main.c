#include <stdio.h>
#include <string.h>

int *mark_vertecies(int graph[9][10], int row_size, int collumn_size) {
    int marked_vertecies[9][10] = {};

    for(int i = 0; i < row_size; i++) {
        int collumn[10] = {};
        for(int j = 0; j < collumn_size; j++) {
            collumn[j] = 0;
        }; 

        for(int j = 0; j < collumn_size; j++) {
            marked_vertecies[i][j] = collumn[j];
        }

    };

    /*
    for (int i = 0; i < row_size; i++) {
        for (int j = 0; j < collumn_size; j++) {
            printf("%i", marked_vertecies[i][j]);
        }; printf("\n");
    }*/

    printf("%p\n", marked_vertecies[0]);
    printf("%p\n", marked_vertecies[1]);
    //return marked_vertecies; // Pointer Info: When specifing a variable name you get access to the value at the memory address the variable is linked to, when using a pointer to that variable, you get the memory address that varaible name is link to in return

}

    /*for i in range(0, len(graph)):
        marked_vertexes.append([])
        for j in range(0, len(graph[i])):
            marked_vertexes[i].append(False) # "Creates identical matrix and marks the vertix position False" print(i, j, maze[i][j]) 

    return marked_vertexe*/

int find_neighbours(int graph[9][10], int row, int column) {
    int row_vertecies[] = {-1, +1, 0, 0};
    int column_vertecies[] = {0, 0, -1, +1};
    int valid_paths[] = {};

    for (int direction = 0; direction > 4; direction++) {
        int next_row = row + row_vertecies[direction];
        int next_column = column + column_vertecies[direction];

    };
}

int dfs(int graph[9][10], int marked_maze[9][10], int row, int column) {


    find_neighbours(graph, row, column);
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

    int *marked_vertices = mark_vertecies(maze, sizeof(maze) / sizeof(maze[0]), sizeof(maze[0]) / sizeof(maze[0][0]) );

    //dfs(maze, marked_maze, 0, 0);
}


/*
    for direction in range(0, 4):
        next_row = row + row_vertecies[direction]
        next_column = column + column_vertecies[direction]

        if ( (0 <= next_row < len(graph)) and (0 <= next_column < len(graph[0])) ):
            if graph[next_row][next_column] != 0:
                if not marked_maze[next_row][next_column]:
                    valid_paths.append([next_row, next_column])

    return valid_paths
*/
