#include <stdio.h>
#include <stdlib.h>

struct ll_node {
    int data;
    struct ll_node *next_node;    
};

int main() {
    struct ll_node *head;
    struct ll_node *one = NULL;

    //printf("%i", head->data);
    one = malloc(sizeof(struct ll_node));
    one->data = 1;
    
    //printf("%p", head.data);

};