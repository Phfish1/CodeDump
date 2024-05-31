#include<stdio.h>
#include<stdlib.h>
#include"linkedList.c"
#include<string.h>

node current_path = NULL;
int current_cost = 0;

node shortest_path = NULL;
int shortest_cost = 2147483647;

int main() {
    node valid_paths = NULL;

    for(int i =0; i < 10; i++) {
        valid_paths = addNode(valid_paths, createPathArray(i, i+1));
    }

    /*shortest_path = NULL;
    free(shortest_path);

    node p = valid_paths;
    while (p != NULL) {
        
        //printf("%i\n", p->data[0]);
        shortest_path = addNode(shortest_path, p->data);
        p = p->next;
    }

    //printf("%i", shortest_path->data[0]);*/
    //shortest_path = copyList(valid_paths, shortest_path);
    
    shortest_path = copyList(valid_paths, shortest_path);
    printList(shortest_path);
}