#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

struct node{
    node *next;
    node *jumper;
    int data;
}

struct node *build_new_linked_list (int number_of_nodes);

void print_linked_list(struct node *start, int number_of_nodes);
void print_linked_list_by_jumpers(struct node *first, int number_of_nodes);

void double_jumpers(struct node *first, int number_of_nodes);

int delete_linked_list(struct node *first, int number_of_nodes);

//int get_linked_list_data_item_value(struct node *start, int node_number, int total_elements);
//void delete_linked_list(struct node *start);

#endif