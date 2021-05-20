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
    dll.insert(55,3);
    REQUIRE(dll.size() == 4);
}
TEST_CASE("Removing element in the first position"){
    REQUIRE(dll.size() == 4);
    REQUIRE(dll.remove_front() == 45);
    REQUIRE(dll.size() == 3);
}
TEST_CASE("Removing element in the Last position"){
    REQUIRE(dll.size() == 3);
    REQUIRE(dll.remove_back() == 55);
    REQUIRE(dll.size() == 2);
}
TEST_CASE("Removing element at the Third position"){
    dll.push_front(23);
    dll.push_front(44);
    dll.push_front(11);
    dll.push_front(9);
    REQUIRE(dll.size() == 6);
    dll.remove(3);
    REQUIRE(dll.size() == 5);
}
TEST_CASE("Removing element at the Invalid position greater than length"){
    REQUIRE(dll.size() == 5);
    dll.remove(40);
    REQUIRE(dll.size() == 5);
}
TEST_CASE("Removing element at the Invalid negative position"){
    REQUIRE(dll.size() == 5);
    dll.remove(-4);
    REQUIRE(dll.size() == 5);
}
TEST_CASE("Removing element at the length value"){
    REQUIRE(dll.size() == 5);
    dll.remove(5);
    REQUIRE(dll.size() == 5);
}

TEST_CASE("Removing elements at the given range"){
    REQUIRE(dll.size() == 5);
    dll.remove(2,4);
    REQUIRE(dll.size() == 2);
}
TEST_CASE("Removing elements at the invalid negative range"){
    REQUIRE(dll.size() == 2);
    dll.remove(-2,4);
    REQUIRE(dll.size() == 2);
}
TEST_CASE("Removing elements at the invalid range where start is greater than end "){
    REQUIRE(dll.size() == 2);
    dll.remove(3,1);
    REQUIRE(dll.size() == 2);
}
TEST_CASE("Removing elements at the invalid range where start is greater than length "){
    REQUIRE(dll.size() == 2);
    dll.remove(40,50);
    REQUIRE(dll.size() == 2);
}


















