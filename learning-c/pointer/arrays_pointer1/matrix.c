#include <stdio.h>

int main() {
    int maze[][2] = { {10, 25}, {15, 60} };

    /*printf("%p\n", &maze[0][0]); // &maze[0][0] stores the same memory address as maze and maze[0]
    printf("%p\n", &maze[0][1]);

    printf("%p\n", &maze[1][0]);
    printf("%p\n", &maze[1][1]);*/

    for (int i = 0; i < sizeof(maze) / sizeof(maze[0]); i++) {
        for (int j = 0; j < 2; j++) {
            printf("%p : %i\n", &maze[i][j], maze[i][j]);
        };
    };




}