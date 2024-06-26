#include<stdio.h> // Standard Input Output
#include<stdlib.h> // Standard library (gives me right to mallocate memory, Free it? no)
#include "linkedList.c" // Include what i made

// Initialize matrix with 10 rows and 10 columns
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

// Get size of each row and column in the matrix
long matrix_rows = sizeof(matrix) / sizeof(matrix[0]);
long matrix_columns = sizeof(matrix[0]) / sizeof(matrix[0][0]);

// Create LinkedList Head called current_path and set it to Null
node current_path = NULL;
int current_cost = 0; 

node shortest_path = NULL;
int shortest_cost = 2147483647; // For shortest

//int shortest_cost = 0;

node find_next_paths(int row, int column) {
    // Vertecies representing directions
    int row_vertecies[2] = {1, 0}; 
    int column_vertecies[2] = {0, 1};

    // Create new LinkedList node pointer and set its value to NULL
    node valid_paths = NULL;

    // For each direction
    for(int i = 0; i < 2; i++) {
        // Get next row and column, based on vertecies
        int next_row = row + row_vertecies[i];
        int next_column = column + column_vertecies[i];

        // If cordinates of [next_row][next_collumn] fits inside matrix
        if ( (0 <= next_row && next_row < matrix_rows) && (0 <= next_column && next_column < matrix_columns) ) {
            // Create a subArray with the cordinates
            int *subArray = createPathArray(next_row, next_column);
            
            // Add subArray to validPaths
            valid_paths = addNode(valid_paths, subArray);
        }

    }
    
    // Return the LinkedList node. Pointer to Head of valid paths
    return valid_paths;
}

int dijkstras(int row, int column) {
    // If last index in matrix is hit
    if (row == matrix_rows-1 && column == matrix_columns-1) {
        // If current cost is less than shortest cost
        if (current_cost < shortest_cost) { // TO DO SHORTEST JUST CHANGE "<" to ">" AND shortest_cost = 0

            shortest_path = copyList(current_path, shortest_path);
            shortest_cost = current_cost;
        }

        return 1;
    }
    
    // Store return value of find_next_paths in next_paths
    node next_paths = find_next_paths(row, column);

    // Store head of next paths in P, This is our temp variable, which we loop through
    node p = next_paths;
    while (p != NULL) {
        current_path = addNode(current_path, createPathArray(p->data[0], p->data[1]));
        current_cost += matrix[p->data[0]][p->data[1]];
        
        dijkstras(p->data[0], p->data[1]);
        
        current_cost -= matrix[p->data[0]][p->data[1]];
        current_path = popNode(current_path);

        p = p->next;
    }

    // Free this hogger 🐗
    freeList(next_paths);
    return 0;
}

int main() {

    // Includes cost of first item in matrix
    current_cost += matrix[0][0];
    int do_shortest = 1;

    dijkstras(0, 0); // 0, 0 = row, column

    // Print shortest path
    node p = shortest_path;
    while (p != NULL) {
        printf("[%i, %i]\n", *(p->data + 0), *(p->data + 1));

        p = p->next;
    }

    // Print shortest cost
    printf("%i\n", shortest_cost);
    freeList(current_path);
};