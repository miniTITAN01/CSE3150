#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "LinkedList.h"

TEST_CASE("Testing LinkedList functionality") {
    LinkedList list;

    SUBCASE("Test empty list initialization") {
        CHECK(list.getNodeCount() == 0);
        list.print_node_list_shared_ptrs();  // Should output nothing indicating the list is empty
    }

    SUBCASE("Adding nodes to the list") {
        list.build_node_list(5);
        CHECK(list.getNodeCount() == 5);

        SUBCASE("Check node connectivity and count increment") {
            auto copyNodes = list.build_copyNodes_weak_ptrs();
            for (int i = 0; i < 5; i++) {
                CHECK(!copyNodes[i].weak_node_ptr.expired()); // Ensure weak pointers are valid
                auto lockedNode = copyNodes[i].weak_node_ptr.lock();
                CHECK(lockedNode != nullptr);  // Locked weak pointer should not be null
                CHECK(lockedNode->data == i); // Data should match the index when added sequentially
            }
            delete[] copyNodes; // Clean up dynamically allocated array
        }
    }

    SUBCASE("Deleting the list") {
        list.build_node_list(5);
        REQUIRE(list.getNodeCount() == 5);  // Ensure nodes are added correctly.
        list.delete_node_shared_ptr_list();
        CHECK(list.getNodeCount() == 0);  // Ensure node count is zero after deletion.

        // Optional: Verify that all nodes are actually deleted if necessary.
        auto copyNodes = list.build_copyNodes_weak_ptrs();  // Should return nullptr if list is empty.
        CHECK(copyNodes == nullptr);
}


    SUBCASE("Testing weak pointers after deletion") {
        list.build_node_list(5);
        auto copyNodes = list.build_copyNodes_weak_ptrs();
        list.delete_node_shared_ptr_list();

        for (int i = 0; i < 5; i++) {
            CHECK(copyNodes[i].weak_node_ptr.expired());  // All weak pointers should be expired after list deletion
        }
        delete[] copyNodes;
    }
}
