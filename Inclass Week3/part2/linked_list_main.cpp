
#include <iostream>
#include "linked_list.h"

using namespace std;

/*int main(){
    struct node *linked_list_one_elt = build_new_linked_list(1);
    print_linked_list(linked_list_one_elt, 1);

    cout <<"---------------"<< endl;

    struct node *linked_list_two_elts = build_new_linked_list(2);
    print_linked_list(linked_list_two_elts,2);

    return 0;
}*/
int main() {
    int number_of_nodes;
    cout << "Enter the number of nodes: ";
    cin >> number_of_nodes;

    struct node *myList = build_new_linked_list(number_of_nodes);
    if (myList != NULL) {
        print_linked_list(myList, number_of_nodes);
        int deleted_nodes = delete_linked_list(myList, number_of_nodes);
        cout << "Deleted " << deleted_nodes << " nodes." << endl;
    } else {
        cout << "The list is empty." << endl;
    }

    return 0;
}
