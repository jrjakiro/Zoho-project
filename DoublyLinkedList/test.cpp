#define CATCH_CONFIG_MAIN
#include "catch_amalgamated.hpp"
#include "doubly_linked_list.h"

doubly_linked_list dll;
TEST_CASE("Testing the size of list when it is empty"){
    REQUIRE(dll.size() == 0);
    REQUIRE(dll.is_empty() == 1);
}

TEST_CASE("adding first element"){
    dll.push_front(24);
    REQUIRE(dll.size() == 1);
}

TEST_CASE("adding elements at the back"){
    dll.push_back(40);
    REQUIRE(dll.size() == 2);
}
TEST_CASE("removing elements at the front"){
    dll.push_front(33);

    REQUIRE(dll.remove_front() == 33);
}
TEST_CASE("removing elements at the back"){
    dll.push_front(33);
    REQUIRE(dll.remove_back() == 40);
}

TEST_CASE("Inserting element in the second position"){
    dll.insert(45,2);
    REQUIRE(dll.remove_back() == 45);
}
TEST_CASE("Inserting element in the invalid position or position > length"){
    dll.insert(45,55);
    REQUIRE(dll.size() == 2);
}
TEST_CASE("Inserting element in the negative position"){
    dll.insert(45,-2);
    REQUIRE(dll.size() == 2);
}
TEST_CASE("Removing at a  invalid position"){
    dll.remove_at(-1);
    REQUIRE(dll.size() == 2);
}

TEST_CASE("clearing all the elemtents"){
    dll.print_values();
    dll.clear();
    REQUIRE(dll.size() == 0);
}
TEST_CASE("Removing  element at front when the list is empty"){
    REQUIRE(dll.remove_front() == 0);
}
TEST_CASE("Removing  element at back when the list is empty"){
    REQUIRE(dll.remove_back() == 0);
}
TEST_CASE("clearing all the elemtents when the list is empty"){
    dll.print_values();
    dll.clear();
    REQUIRE(dll.size() == 0);
}
TEST_CASE("Removing at a position or invalid when the list is empty"){
    dll.remove_at(1);
    REQUIRE(dll.size() == 0);
}





