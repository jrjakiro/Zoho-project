#define CATCH_CONFIG_MAIN
#include "catch_amalgamated.hpp"
#include "doubly_linked_list.h"

doubly_linked_list dll;
TEST_CASE("Testing the size of list when it is empty"){
    REQUIRE(dll.size() == 0);
    REQUIRE(dll.is_empty() == true);
}

TEST_CASE("adding first element"){
    dll.push_front(24);
    REQUIRE(dll.size() == 1);
}

TEST_CASE("adding elements at the back"){
    dll.push_back(40);
    REQUIRE(dll.size() == 2);
}

TEST_CASE("Inserting element in the invalid position or position > length"){
    dll.insert(45,55);
    REQUIRE(dll.size() == 2);
}
TEST_CASE("Inserting element in the negative position"){
    dll.insert(45,-2);
    REQUIRE(dll.size() == 2);
}
TEST_CASE("Inserting element in the first position"){
    dll.insert(45,0);
    REQUIRE(dll.size() == 3);
}
TEST_CASE("Inserting element in the last position"){
    dll.insert(45,3);
    dll.print_values();
    REQUIRE(dll.size() == 4);
}







