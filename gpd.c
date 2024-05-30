#include <stdio.h>
#include <stdlib.h>

struct LinkedList {
    int *data;
    struct LinkedList *next;
};

typedef struct LinkedList *node;

node createNode() {
    node temp;
    temp = (node)malloc(sizeof(struct LinkedList));
    temp->next = NULL;
    temp->data = NULL;
    return temp;
}

node addNode(node head, int *value) {
    node temp;
    node p;

    temp = createNode();
    temp->data = value;

    if (head == NULL) {
        return temp; // Directly return the new node as the new head
    } else {
        p = head;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = temp;
    }

    return head;
}

node popNode(node head) {
    if (head == NULL) {
        return NULL; // List is already empty
    }

    if (head->next == NULL) {
        free(head->data);
        free(head);
        return NULL; // List had one element, now it's empty
    }

    node p = head;
    while (p->next->next != NULL) {
        p = p->next;
    }

    free(p->next->data);
    free(p->next);
    p->next = NULL;

    return head;
}

int* createPathArray(int value_1, int value_2) {
    int *temp = (int *)malloc(sizeof(int) * 2);
    temp[0] = value_1;
    temp[1] = value_2;

    return temp;
}

void printList(node head) {
    node p = head;
    while (p != NULL) {
        for (int i = 0; i < 2; i++) {
            printf("%i\n", p->data[i]);
        }
        p = p->next;
    }
}

void freeList(node head) {
    node temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp->data);
        free(temp);
    }
}

int main() {
    node list = NULL; // Start with an empty list

    list = addNode(list, createPathArray(10, 15));
    list = addNode(list, createPathArray(100, 150));
    printList(list);

    /*printf("\n\n");
    list = popNode(list);

    printList(list);

    freeList(list); // Free the list to prevent memory leaks
*/
}
