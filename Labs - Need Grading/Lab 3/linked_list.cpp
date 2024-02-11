
#include <iostream>

#include "linked_list.h"

struct node *build_new_linked_list (int number_of_nodes){
    struct node * linked_list = new node;
    struct node *root = linked_list;

    root->data = -1;

    for (int i = 0; i <number_of_nodes; i++){
        linked_list->next = new node;
        linked_list->jumper = linked_list->next;
        linked_list->data = i+1;
        linked_list= linked_list->next;
    }

    linked_list->jumper = linked_list;
    return root;

}

void print_linked_list(struct node *start, int number_of_nodes){
    struct node * linked_list = start;

    for (int i =0; i <number_of_nodes; i++){
        cout <<linked_list->data<<endl;
        linked_list = linked_list->next;
    }

}

void print_linked_list_by_jumpers(struct node *first, int number_of_nodes){
    struct node *linked_list = first;

    for (int i = 0; i < number_of_nodes; i++){
        if (linked_list->jumper == linked_list){
            break;
        }
        cout <<linked_list->data<<endl;
        linked_list = linked_list->jumper
    }
}

int delete_linked_list(struct node *first, int number_of_nodes){
    struct node *linked_list =first;
    struct node *lag_node = first; 

    int delete_number = 0;
}

void double_jumpers(struct node* first, int number_of_nodes){

    struct node *linked_list = start;

    for (int i = 0; i < number_of_nodes; i++){
        if (linked_list->jumper == linked_list){
            break;
        }

        cout <<linked_list->data <<endl;
        linked_list = linked_list->jumper
        linked_list = linked_list->jumper

        //linked_list = linked_list->next;
        if (){

        }


    }
}