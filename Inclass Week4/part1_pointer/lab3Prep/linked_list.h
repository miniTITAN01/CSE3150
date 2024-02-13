#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

struct node {
    int data;
    node *next; //struct node *next; same thing in c++
    node *jumper;
};

struct node *build_new_linked_list (int total_new_elements);

void print_linked_list(struct node *start, int total_elements);
void print_linked_list_by_jumpers( struct node *first, int number_of_nodes);
void double_jumpers( struct node *first, int number_of_nodes);

int delete_linked_list(struct node *first, int number_of_nodes);

#endif