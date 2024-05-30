#include<stdio.h>
#include<stdlib.h>

struct LinkedList {
    int *data;
    struct LinkedList *next;
};

// Define new dataType of LinkedList pointer = node
typedef struct LinkedList *node; // Node is a pointer to a LinkedList structure ( sizeof(int) + sizeof(*int) )

node createNode() {
    node temp;
    temp = (node)malloc(sizeof(struct LinkedList)); // (node) = Return a pointer to LinkedList, Sizeof() = allocate size of LinkedList struct to memory
    temp->next = NULL; // Makes last item in linked_list point to NULL
    temp->data = NULL;
    return temp; // returns LinkedList Node
};

node addNode(node head, int *value) {
    node temp; // Create a temp LinkedList struct pointer
    node p; // create a second one

    temp = createNode(); // Create new node store in temp
    temp->data = value; // assign data to newly created LinkedList Node

    if(head == NULL) { // makes it possible to append to empty list
        return temp;
    }
    else {
        p = head; // assign head Node to p
        while(p->next != NULL) { // if p.next does not point to NULL then traverse through the list until it does
            p = p->next; 
        }

        p->next = temp; // Then when at last Node, make last Node.next point to newly created Node :) 
    }

    return head;
}

node popNode(node head) {
    node temp;
    node p;

    if (head == NULL) {
        return NULL;
    }
    else if (head->next == NULL) {
        free(head->data);
        free(head);
        return NULL;
    } else {
        p = head;
        while(p->next->next != NULL) { // Goes through entire list, then when next->next == Null, next = Null
            p = p->next;
        }

        free(p->next->data);
        free(p->next);
        p->next = NULL;
        
        return head;
    }
}

int* createPathArray(int value_1, int value_2) { // Another solution could be to create some sort of array structure, storing the length of the array
    int *temp = malloc(sizeof(int) * 2); // Allocate 2 * sizeof(int) / 8 bytes to memory
    temp[0] = value_1; // store parameters in memory
    temp[1] = value_2;

    return temp;
};

void printList(node head) {
    node p = head;
    while (p != NULL) {
        printf("[ ");
        for (int i = 0; i < 2; i++) {
            printf("%i, ", p->data[i]);
        }
        printf("]\n");
        p = p->next;
    }
}

void freeList(node head) {
    node temp;
    node p = head;

    while (head != NULL) {
        temp = head;
        head = head->next;

        free(temp->data);
        free(temp);
    }
}

//Example Use code
/*int main() {
    node list = NULL;
    //list->data = createPathArray(10, 15);

    list = addNode(list, createPathArray(100, 150));
    list = addNode(list, createPathArray(200, 300));
    //printList(list);

    //printf("\n\n");
    //popNode(list);

    printf("%i", list->next->data[0]);
    //printList(list);


};*/