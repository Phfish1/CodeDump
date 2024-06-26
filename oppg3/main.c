#include <stdio.h>
#include <stdlib.h>
#include "linkedList.c"
#include "arrayList.c"

// Create LinkedList head and current cost
node current_path = NULL; 
int current_cost = 0; // For 

node shortest_path = NULL;
int shortest_cost = 2147483647;
//int shortest_cost = 0; // For longest path
int do_shortest = 1;

node find_next_paths(matrixList matrix, int row, int column) {
    // SAME LOGIC
    int row_vertecies[3] = {1, 1, 1};
    int column_vertecies[3] = {0, 1, -1};

    node valid_paths = NULL;

    for (int i = 0; i < 3; i++) 
    {
        int next_row = row + row_vertecies[i];
        int next_column = column + column_vertecies[i];

        // IMPORTANT
        // Checks if next_row and next_column is within matrix
        // Matrix is variable lengths so we use the SIZE atribute to get the lenght of the right matrix
        // Matrix->size = Array of pointer length, // matrix->data[next_row] = Lenght of arrlist within matrix

        if ((0 <= next_row && next_row < matrix->size) && (0 <= next_column && next_column < matrix->data[next_row]->size))
        {
            int *subArray = createPathArray(next_row, next_column);
            valid_paths = addNode(valid_paths, subArray);
        }
    }

    return valid_paths;
}

int dijkstras(matrixList matrix, int row, int column)
{
    int matrix_rows = matrix->size;
    int matrix_last_columns = matrix->data[matrix_rows-1]->size;

    // BASEd CONDITION
    if (row == matrix_rows - 1)
    {
        if (do_shortest == 1) {
            if (current_cost < shortest_cost)
            {
                shortest_path = copyList(current_path, shortest_path);
                shortest_cost = current_cost;
            }
        } else {
            if (current_cost > shortest_cost) {
                shortest_path = copyList(current_path, shortest_path);
                shortest_cost = current_cost;
            }
        }

        return 1;
    }

    // finc next paths
    node next_paths = find_next_paths(matrix, row, column);

    // Loop trough each path
    node p = next_paths;
    while (p != NULL) // For each path in next_paths DO:
    {
        // THE SAME LOGIC
        current_path = addNode(current_path, createPathArray(p->data[0], p->data[1]));
        current_cost += matrix->data[p->data[0]]->data[p->data[1]];

        dijkstras(matrix, p->data[0], p->data[1]);
        
        current_cost -= matrix->data[p->data[0]]->data[p->data[1]];
        current_path = popNode(current_path);

        p = p->next;
    }

    freeList(next_paths);
    return 0;
}

int main()
{
    // Spawn matrix 👾
    matrixList matrix = spawnMatrix();
    current_cost += matrix->data[0]->data[0];

    dijkstras(matrix, 0, 0);
   

    // Prints out list
    node p = shortest_path;
    while (p != NULL)
    {
        printf("[%i, %i]\n", *(p->data + 0), *(p->data + 1));

        p = p->next;
    }

    // Print shortest cost
    printf("%i\n", shortest_cost);

    freeList(current_path);
    freeMatrix(matrix);

};