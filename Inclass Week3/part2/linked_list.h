
#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

struct node {
    int data;
    struct node *next;
};

struct node *build_new_linked_list (int total_new_elements);

void print_linked_list(struct node *start, int total_elements);

int delete_linked_list(struct node *first, int number_of_nodes);

int get_linked_list_data_item_value(struct node *start, int node_number, int total_elements);

bool update_data_in_linked_list (struct node *start,
                                int node_to_update,
                                int update_val,
                                int total_elements);

#endif
