#include <stdio.h>
#include <stdlib.h>

struct deck{
    int number;
    struct deck *next;
};

struct node {
   int number;
   struct node *next;
   struct deck *decks;
};


int main() {
    struct node *current_node, *new_node;
    struct deck *current_deck, *new_deck;

    current_node = (struct node *) malloc(sizeof(struct node));

    for(i=0; i<number_of_nodes-1;i++) {
        current_deck = (struct deck* ) malloc (sizeof(struct deck));
        current_node->decks = current_deck;
        for (j=0; j<number_of_decks_in_node_i-1; j++) {
            new_deck = (struct deck* ) malloc (sizeof(struct deck));
            current_deck->next = new_deck;
            current_deck = new_deck;
        }
        new_node = (struct node *) malloc (sizeof(struct node));
        current_node->next = new_node;
        current_node = new_node;
    }
}