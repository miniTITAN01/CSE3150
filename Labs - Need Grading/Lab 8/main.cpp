#include "LinkedList.h"
#include <iostream>

using namespace std;

int main() {
    LinkedList list;

    cout << "Building a linked list with 5 nodes." << endl;
    list.build_node_list(5);

    cout << "The linked list before deletion:" << endl;
    list.print_node_list_shared_ptrs();

    LinkedList::CopyNode* copyNodes = list.build_copyNodes_weak_ptrs();
    if (!copyNodes) {
        cout << "Failed to create CopyNode array, exiting." << endl;
        return 1;  // Handle error case
    }

    cout << "\nCopyNode array before deleting the list (weak pointers should be valid):" << endl;
    list.print_node_array_weak_ptrs(copyNodes, list.getNodeCount());

    cout << "\nDeleting the main linked list." << endl;
    list.delete_node_shared_ptr_list();

    cout << "\nCopyNode array after deleting the list (weak pointers should be expired):" << endl;
    list.print_node_array_weak_ptrs(copyNodes, list.getNodeCount());

    delete[] copyNodes;  // Clean up the CopyNode array
    copyNodes = nullptr;  // Prevent dangling pointer usage

    cout << "Program completed successfully." << endl;
    return 0;
}
