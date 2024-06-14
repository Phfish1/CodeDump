#include<stdio.h>
#include<stdlib.h>

// Create LinkedList structure that stores (pointer to int "data") and (pointer to itself "next") 
struct LinkedList {
    int *data;
    struct LinkedList *next;
};

// Define new dataType of LinkedList pointer = node
typedef struct LinkedList *node; // Node is a pointer to a LinkedList structure ( sizeof(int*) + sizeof(LinktesList*) )

// Creates new node in the linkedList
node createNode() {
    node temp; // Create temp as datatype LinkedList
    temp = (node)malloc(sizeof(struct LinkedList)); // (node) = Return a pointer to LinkedList, Sizeof() = allocate size of LinkedList struct to memory
    temp->next = NULL; // Makes last item in linked_list point to NULL
    temp->data = NULL; // Make temp.data == NULL
    return temp; // returns LinkedList Node
};

node addNode(node head, int *value) {
    node temp; // Create a temp LinkedList struct pointer
    node p; // create a second one

    temp = createNode(); // Create new node store in temp
    temp->data = value; // assign data to newly created LinkedList Node

    if(head == NULL) { // makes it possible to "append" to empty list
        return temp; // Just returns 1 node
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

node popNode(node head) { // The same as addNode
    node temp;
    node p;

    if (head == NULL) {
        return NULL;
    }
    else if (head->next == NULL) {
        free(head);
        return NULL;
    } else {
        p = head;
        while(p->next->next != NULL) { // Goes through entire list, then when next->next == Null, next = Null
            p = p->next;
        }

        free(p->next); // Free
        p->next = NULL; // Then set next to null
        
        return head;
    }
}

// Create the PathArray which our LinkedList will store in Data
int* createPathArray(int value_1, int value_2) { // Another solution could be to create some sort of array structure, storing the length of the array
    int *temp = (int *)malloc(sizeof(int) * 2); // Allocate 2 * sizeof(int) / 8 bytes to memory
    temp[0] = value_1; // store parameters in memory
    temp[1] = value_2;

    return temp;
};

// Goes through entire list and prints it
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

// Free this memory hog!
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

// Copies 
node copyList(node src_list, node dst_list) {
    dst_list = NULL;
    freeList(dst_list);

    node p = src_list;
    while (p != NULL) {
        dst_list = addNode(dst_list, p->data);
        p = p->next;
    }

    return dst_list;
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