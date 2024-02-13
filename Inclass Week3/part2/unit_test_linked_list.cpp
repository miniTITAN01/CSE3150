
//valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./a.out

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
/*
  https://hackingcpp.com/cpp/tools/testing_frameworks.html
 */

#include "doctest.h"
#include "linked_list.h"


int zero_linked_list_elts = 0;
struct node * zero_linked_list_elts_null_node = NULL;

int one_element_linked_list = 1;
int data_value_of_initial_linked_list_elt = 1;
struct node * linked_list_one_elt = build_new_linked_list(one_element_linked_list);

int two_element_linked_list = 2;
int data_value_of_second_elt = 2;
struct node * linked_list_two_elts = build_new_linked_list(two_element_linked_list);

struct node * linked_list_two_elts_B = build_new_linked_list(two_element_linked_list);
//int deleted = delete_linked_list(linked_list_two_elts_B, two_element_linked_list);


TEST_CASE("linked_list testing") {

    SUBCASE("build_new_linked_list") {
        CHECK_EQ(build_new_linked_list(zero_linked_list_elts), zero_linked_list_elts_null_node);
        
    }
    SUBCASE("delete_linked_list") {
        CHECK_EQ(delete_linked_list(linked_list_two_elts_B, two_element_linked_list), two_element_linked_list);
        
    }



}