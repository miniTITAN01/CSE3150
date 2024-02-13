//valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./a.out

#include <iostream>

#include "linked_list.h"

using namespace std; 

struct node *build_new_linked_list (int number_of_nodes){

    if (number_of_nodes == 0){
        return NULL;
    }else{
        struct node *root = new node;
        root -> data = -1;//// Initial data set to -1, but this will be overwritten
        struct node *linked_list = root;

        //ensuring that next is only set to a new node 
        //if we are not on the last node of the list 
        //and properly terminates the last node's next pointer with NULL.
        for (int i = 0; i < number_of_nodes; i++) {
            linked_list->data = i + 1; // Set data for the current node
            if (i < number_of_nodes - 1) {
                linked_list->next = new node; // Create next node only if not last
                linked_list ->jumper = linked_list->next;
                linked_list = linked_list->next;
            } else {
                linked_list->next = NULL; // Properly terminate the list
            }
        }
        linked_list->jumper = linked_list;
        return root;
    }

}

void print_linked_list(struct node *start, int total_elements){
    struct node *linked_list = start;

    for (int i = 0 ; i < total_elements; i++){
        cout << linked_list->data <<endl;
        linked_list = linked_list ->next;
    }
}


int delete_linked_list(struct node *first, int number_of_nodes){
    struct node *linked_list = first;
    //struct node *lag_node = first;

    int deleted_number = 0;

    /*for (int i = 0; i < number_of_nodes; i++ ){
        linked_list = linked_list->next;
        delete lag_node;
        deleted_number++;
        lag_node = linked_list;
        
    }*/
    while (linked_list != NULL){
        struct node *temp = linked_list;
        linked_list = linked_list-> next;
        delete temp;
        deleted_number++;
    }

    return deleted_number;

}

void print_linked_list_by_jumpers( struct node *first, int number_of_nodes){
    struct node *linked_list = first;

    for (int i = 0 ; i < number_of_nodes; i++){
        if (linked_list-> jumper == linked_list){
            break;
        }
        cout << linked_list->data <<endl;
        linked_list = linked_list ->jumper;
    }
}
void double_jumpers( struct node *first, int number_of_nodes){
    struct node *linked_list = first;

    for (int i = 0 ; i < number_of_nodes; i++){
        if (linked_list-> jumper == linked_list){
            break;
        }
        cout << linked_list->data <<endl;
        linked_list = linked_list ->jumper;
        linked_list = linked_list ->jumper;
    }
    
}
