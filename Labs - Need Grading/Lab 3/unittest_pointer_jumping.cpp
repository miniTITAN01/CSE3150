#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "linked_list.h"
#include <sstream>

using namespace std;

TEST_CASE("Testing build_new_linked_list function") {
    // Test with zero nodes
    struct node *list0 = build_new_linked_list(0);
    CHECK(list0 == nullptr);

    // Test with one node
    struct node *list1 = build_new_linked_list(1);
    CHECK(list1 != nullptr);
    CHECK(list1->data == 0);
    CHECK(list1->next == nullptr);
    CHECK(list1->jumper == list1); // Jumper should point to itself for the last node

    // Clean up
    delete list1;

    // Test with multiple nodes
    struct node *list2 = build_new_linked_list(5);
    CHECK(list2 != nullptr);
    struct node *current = list2;
    struct node *last = nullptr;
    int count = 0;
    while (current != nullptr) {
        CHECK(current->data == count); // Check if data is as expected
        last = current; // Keep track of the last node
        current = current->next;
        count++;
    }
    CHECK(count == 5); // Ensure we have the correct number of nodes

    // Check if jumpers point to the last node
    current = list2;
    while (current->next != nullptr) {
        if (current->next != nullptr) { // Check jumper only if not the last node
        CHECK(current->jumper == last);
        }
        current = current->next;
    }

    // Clean up
    int deleted_nodes = delete_linked_list(list2);
    CHECK(deleted_nodes == 5);
}

TEST_CASE("Testing delete_linked_list function") {
    // Test deletion of an empty list
    struct node *list0 = nullptr;
    int deleted_nodes0 = delete_linked_list(list0);
    CHECK(deleted_nodes0 == 0);

    // Test deletion of a non-empty list
    struct node *list1 = build_new_linked_list(3);
    int deleted_nodes1 = delete_linked_list(list1);
    CHECK(deleted_nodes1 == 3);
}

TEST_CASE("Testing print_linked_list_by_jumpers function") {
    // Prepare the linked list
    struct node *list = build_new_linked_list(3);

    // Capture the output
    stringstream buffer;
    streambuf *old = cout.rdbuf(buffer.rdbuf());

    // Call the function to test
    print_linked_list_by_jumpers(list, 3);

    // Restore the original buffer
    cout.rdbuf(old);

    // Check the output
    string expected = "Node data: 0, Jumper data: 2\nNode data: 1, Jumper data: 2\nNode data: 2, Jumper data: 2\n";
    CHECK(buffer.str() == expected);

    // Clean up
    delete_linked_list(list);
}

TEST_CASE("Testing double_jumpers function") {
    // Prepare the linked list
    struct node *list = build_new_linked_list(3);

    // Capture the output
    stringstream buffer;
    streambuf *old = cout.rdbuf(buffer.rdbuf());

    // Call the function to test
    double_jumpers(list);

    // Restore the original buffer
    cout.rdbuf(old);

    // Check the output
    string expected = "Last node data (reached by jumpers): 2\n";
    CHECK(buffer.str() == expected);

    // Clean up
    delete_linked_list(list);
}

TEST_CASE("Testing print_linked_list_by_jumpers with an empty list") {
    struct node *list = build_new_linked_list(0); // Empty list

    stringstream buffer;
    streambuf *old = cout.rdbuf(buffer.rdbuf());

    print_linked_list_by_jumpers(list, 0);

    cout.rdbuf(old);

    string expected = ""; // Expect no output for an empty list
    CHECK(buffer.str() == expected);

    // No need to delete, list is empty
}

TEST_CASE("Testing double_jumpers with a single element list") {
    struct node *list = build_new_linked_list(1); // List with one element

    stringstream buffer;
    streambuf *old = cout.rdbuf(buffer.rdbuf());

    double_jumpers(list);

    cout.rdbuf(old);

    // In your current implementation, double_jumpers always prints the last node data
    string expected = "Last node data (reached by jumpers): 0\n"; // Expect the data of the single node
    CHECK(buffer.str() == expected);

    delete_linked_list(list);
}