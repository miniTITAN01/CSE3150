#include "LinkedList.h"

using namespace std;

// Implement Node constructors
LinkedList::Node::Node(int data, std::shared_ptr<Node> ptr) : data(data), next(ptr) {}

// Implement LinkedList constructor
LinkedList::LinkedList() : root(nullptr), nodeCount(0) {}

// Implement LinkedList destructor
LinkedList::~LinkedList() {
    delete_node_shared_ptr_list();
}

/* Implement build_node_list
void LinkedList::build_node_list(int k) {
    for (int i = 0; i < k; i++) {
        root = std::make_shared<Node>(i, root);
        nodeCount++;
    }
}

##OUTPUT: 
print_node_list_shared_ptrs START
0xafdf80 shared_ptr count: [2]
0xafdf50 shared_ptr count: [2]
0xafdf20 shared_ptr count: [2]
0xafdef0 shared_ptr count: [2]
0xafdec0 shared_ptr count: [2]*/

void LinkedList::build_node_list(int totalNumber) {
    std::shared_ptr<Node> lastNode = root;

    // Find the last node
    while (lastNode && lastNode->next) {
        lastNode = lastNode->next;
    }

    // Append new nodes
    for (int i = 0; i < totalNumber; ++i) {
        auto newNode = std::make_shared<Node>(nodeCount++, nullptr);
        //std::cout << "New Node created, shared_ptr count: [" << newNode.use_count() << "]" << std::endl;
        if (!lastNode) {
            root = newNode;  // List was empty, set root
            //std::cout << "Root node set, shared_ptr count: [" << root.use_count() << "]" << std::endl;
        } else {
            lastNode->next = newNode;
            //std::cout << "Node linked, new node shared_ptr count: [" << newNode.use_count() << "]" << std::endl;
        }
        lastNode = newNode; // Move lastNode to the new node
    }
}


// Implement build_copyNodes_weak_ptrs
LinkedList::CopyNode * LinkedList::build_copyNodes_weak_ptrs() {
    if (nodeCount == 0) {
        return nullptr;
    }

    auto array = new CopyNode[nodeCount];
    auto current = root;
    for (int i = 0; i < nodeCount; ++i) {
        array[i].weak_node_ptr = current;
        current = current->next;
    }
    return array;
}

int LinkedList::getNodeCount() const {
    return nodeCount;
}

void LinkedList::delete_node_shared_ptr_list() {
    std::shared_ptr<Node> current = root; // Use a local pointer to iterate and delete nodes
    while (current != nullptr) {
        std::shared_ptr<Node> next = current->next; // Safely store the next node
        std::cout << current.get() << " shared_ptr count: [" << current.use_count() - 1 << "]" << std::endl;
        current.reset(); // Manually delete the current node, which decrements the reference count
        current = next; // Move to the next node
    }
    root.reset(); // Ensure the root is also reset
    nodeCount = 0; // Reset the node count after clearing the list
}


void LinkedList::print_node_list_shared_ptrs() {
    auto current = root;
    std::cout << "print_node_list_shared_ptrs START" << std::endl;
    while (current) {
        std::cout << reinterpret_cast<void*>(current.get()) << " shared_ptr count: [" << current.use_count() << "]" << std::endl;
        current = current->next;
    }
    std::cout << "print_node_list_shared_ptrs END" << std::endl;
}


void LinkedList::print_node_array_weak_ptrs(CopyNode* copyNodes, int size) {
    cout << "print_node_array_weak_ptrs START" << endl;
    
    // Check if the CopyNode array is a nullptr
    if (!copyNodes) {
        cout << "CopyNode array is nullptr, likely not initialized or already deleted." << endl;
    } else {
        // Track if all weak_ptrs have expired
        bool allExpired = true;

        for (int i = 0; i < size; ++i) {
            auto sp = copyNodes[i].weak_node_ptr.lock();
            if (sp) {
                // If weak_ptr successfully locked to a shared_ptr, print its info
                cout << reinterpret_cast<void*>(sp.get()) << " weak_ptr to shared_ptr count: [" << sp.use_count() << "]" << endl;
                allExpired = false; // At least one weak_ptr is still alive
            } else {
                // If weak_ptr is expired, indicate this
                cout << "Node [" << i << "] weak_ptr is expired." << endl;
            }
        }

        // If all weak_ptrs are expired, indicate all nodes have been deleted
        if (allExpired) {
            cout << "All weak_ptrs have expired, indicating that the shared_ptrs have been deleted and no longer manage any objects." << endl;
        }
    }
    
    cout << "print_node_array_weak_ptrs END" << endl;
}

