
#include <iostream>
#include "linked_list.h"

/*struct node {
    int data;
    struct *node next;
};*/
using namespace std;

//build_new_linked_list: return a pointer to first node in the linked list
//                       if 0 == total_new_element, then return NULL
struct node * build_new_linked_list (int total_new_elements){
    if (total_new_elements == 0){
        return NULL;
    }else{
        // Create a new node as the root
        struct node * root = new node;
        root->data = -1;
        

        // Create a linked list starting from the root
        struct node *linked_list = root;

        // Loop to create the specified number of elements
        for (int i = 0; i < total_new_elements; i++) {
            // Create a new node for the next element
            linked_list->next = new node;

            // Set the data of the current node (starting from 1)
            linked_list->data = i + 1;

            // Move on to the next element in the linked list
            linked_list = linked_list->next;
        }

        // Return the root of the newly created linked list
        return root;
    }
    
}; 
/*After calling this function, you will have a linked list with nodes containing data values from 1 to total_new_elements. 
The last node in the linked list will have a nullptr in its next field, indicating the end of the list.*/

int get_linked_list_data_item_value(struct node *start, int node_number, int total_elements){
    if (node_number > total_elements){
        return -1;
    }else{
        struct node *linked_list = start;

        //// Loop to traverse the linked list to the specified node
        for (int i = 0; i < node_number - 1; i++){
            linked_list = linked_list->next;
        }
        //return data of that specified node
        return linked_list->data;
    }
};

void print_linked_list(struct node *start, int total_new_elements){
    // Initialize a pointer to traverse the linked list starting from 'start'
    struct node *linked_list = start;

    // Loop to traverse and print the linked list
    for (int i = 0; i < total_new_elements; i++) {
        // Print the data value of the current node
        cout << linked_list->data << endl;

        // Move to the next node in the linked list
        linked_list = linked_list->next;

    }
};

void delete_linked_list(struct node *start){
    struct node *current = start;
    struct node *next; 

    while (current != nullptr){
        next = current->next;
        delete current;
        current = next;
    }
};

bool update_data_in_linked_list (struct node *start,
                                int node_to_update,
                                int update_val,
                                int total_elements){
    if (node_to_update <= 0 || node_to_update > total_elements){
        return false; //invalid requested node
    }else{
        struct node *linked_list = start;

        //traverse to specified node
        for (int i = 0; i < node_to_update - 1; i++){
            linked_list = linked_list->next;
        }

        linked_list->data = update_val;
        return true;
    }
};
