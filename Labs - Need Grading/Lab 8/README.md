# LAB 8 - NEED GRADING  


## **Compiling Instruction** 
0. Ensure that Doctest is installed before running tests

1. Type the following command to compile specific files (**Main Function**, **Unit Tests**)
```bash
        g++ LinkedList.cpp main.cpp  
        g++ LinkedList.cpp unittest.cpp 
 
```
2. Run complied files
```bash
        ./a.out
```


## **Problem Clarification**
**Main Linked List with shared_ptr:**
Creation: Construct a singly  linked list where each node is an object managed by a std::shared_ptr. This is the main list.

Node Management: Use shared_ptr for the next (and potentially prev, if doubly linked) pointers in the nodes. This will ensure that nodes are automatically destroyed when the list is destroyed or when a node is removed, and its reference count drops to zero.

**CopyNode with weak_ptr:**
Creation: For each node in the main list, create a corresponding CopyNode that contains a weak_ptr pointing to the shared_ptr node.
Purpose: The CopyNode acts as a non-owning reference to the nodes in the main list. It's useful for observers or external entities that need to access the node data without affecting its lifetime.

**Array of CopyNodes:**
Construction: Create an array  of CopyNode instances, each initialized with the weak_ptr to each node in the main list.
Usage: This array can be passed to functions or classes that need to observe the list without owning the nodes.

**Root Node:**
We need a starting point for the linked list, commonly referred to as the head or root. This is a shared_ptr that points to the first node in the list.

**Demonstrating Ownership and Access:**
Pre-deletion: Show that the CopyNode array can access the main list nodes.
Post-deletion: Demonstrate that once the main list is deleted, and the shared_ptr's reference counts drop to zero, the weak_ptr in each CopyNode is no longer able to lock and access the main list nodes, since the shared_ptr has been deallocated.

**Use Count Check:**
Optionally, we can print the use count of each shared_ptr before and after deletion to show the reference count mechanism in action. Before deletion, the use count should be greater than zero. After deletion, any attempt to lock the weak_ptr should fail, indicating that the use count is zero and the resource has been deallocated.