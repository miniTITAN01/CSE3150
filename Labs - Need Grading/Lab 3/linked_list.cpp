//valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./a.out

#include <iostream>

#include "linked_list.h"

using namespace std; 

struct node *build_new_linked_list (int number_of_nodes){

    if (number_of_nodes == 0){
        return NULL;
    }else{
        struct node *root = new node;
        root -> data = 0;//// Initial data set to 0, start couting from 0
        struct node *linked_list = root;

        //ensuring that next is only set to a new node 
        //if we are not on the last node of the list 
        //and properly terminates the last node's next pointer with NULL.
        for (int i = 1; i < number_of_nodes; i++) { //// Start i from 1 since the root is already node 0
                linked_list->next = new node; // Create next node 
                linked_list ->next->data = i;
                linked_list = linked_list->next;
        }
        // Last element points to itself
        linked_list->next = NULL;// Properly terminate the list
        linked_list->jumper = linked_list;//// Last element's jumper points to itself

        // Set all jumper pointers to point to the last element
        struct node *last_element = linked_list; //this is the last node
        linked_list = root ;
        while (linked_list!= last_element){
            linked_list->jumper = last_element;
            linked_list = linked_list->next;
        }
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


int delete_linked_list(struct node *first){
    struct node *current_linked_list = first;
    struct node *next_node;
    //struct node *lag_node = first;

    int deleted_number = 0;

    /*for (int i = 0; i < number_of_nodes; i++ ){
        linked_list = linked_list->next;
        delete lag_node;
        deleted_number++;
        lag_node = linked_list;
        
    }*/
    while (current_linked_list != NULL){
        next_node = current_linked_list-> next; //save the next node
        delete current_linked_list; //delete current node
        current_linked_list = next_node; //move to the next node
        deleted_number++;
    }

    return deleted_number;

}

void print_linked_list_by_jumpers( struct node *start, int number_of_nodes){
    struct node *current_linked_list = start;

    while (current_linked_list != NULL){
        cout << "Node data: " << current_linked_list->data;
        if (current_linked_list->jumper != NULL){
            // Assuming that the jumper should always be valid and pointing to the last node
            cout << ", Jumper data: " <<current_linked_list->jumper->data<<endl;
        }else{
            cout << ", No jumper." <<endl;
        }
        current_linked_list = current_linked_list ->next;
    }
}
void double_jumpers(struct node *first) {
    if (first == NULL) {
        cout << "The list is empty." << endl;
        return;
    }

    struct node *linked_list = first;
    
    // Iterate to the last node, which we can find by following the jumper pointers
    while (linked_list->jumper != linked_list) {
        linked_list = linked_list->jumper;
    }
    
    // Now, linked_list points to the last node. Let's print its data.
    cout << "Last node data (reached by jumpers): " << linked_list->data << endl;
}

