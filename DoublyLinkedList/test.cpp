#define CATCH_CONFIG_MAIN
#include "catch_amalgamated.hpp"
#include "doubly_linked_list.h"

doubly_linked_list<int> dli;
doubly_linked_list<float> dlf;
doubly_linked_list<char> dlc;
doubly_linked_list<string> dls;
doubly_linked_list<long> dll;
doubly_linked_list<double> dld;
TEST_CASE("Testing the size of list when it is empty")
{
    REQUIRE(dli.size() == 0);
    REQUIRE(dli.is_empty() == true);
}

TEST_CASE("adding first integer element")
{
    dli.push_front(24);
    REQUIRE(dli.size() == 1);
}
TEST_CASE("adding first float element")
{
    dlf.push_front(4.07);
    REQUIRE(dli.size() == 1);
}
TEST_CASE("adding first char element")
{
    dlc.push_front('J');
    REQUIRE(dlc.size() == 1);
}
TEST_CASE("adding first string element")
{
    dls.push_front("Hello");
    REQUIRE(dli.size() == 1);
}
TEST_CASE("adding first long element")
{
    dll.push_front(214748364);
    REQUIRE(dll.size() == 1);
}
TEST_CASE("adding first double element")
{
    dld.push_front(-4.00000980);
    REQUIRE(dld.size() == 1);
}

TEST_CASE("adding integer elements at the back")
{
    dli.push_back(40);
    REQUIRE(dli.size() == 2);
}
TEST_CASE("adding float elements at the back")
{
    dlf.push_back(4.80);
    REQUIRE(dlf.size() == 2);
}
TEST_CASE("adding char  elements at the back")
{
    dlc.push_back('r');
    REQUIRE(dlc.size() == 2);
}
TEST_CASE("adding string elements at the back")
{
    dls.push_back("EVERYONE");
    REQUIRE(dls.size() == 2);
}
TEST_CASE("adding long elements at the back")
{
    dll.push_back(123456788);
    REQUIRE(dll.size() == 2);
}
TEST_CASE("adding double elements at the back")
{
    dld.push_back(9.876899);
    REQUIRE(dld.size() == 2);
}

TEST_CASE("Inserting element in the invalid position or position > length")
{
    dli.insert(45, 55);
    REQUIRE(dli.size() == 2);
}

TEST_CASE("Inserting element in the negative position")
{
    dli.insert(45, -2);
    REQUIRE(dli.size() == 2);
}
TEST_CASE("Inserting integer element in the first position")
{
    dli.insert(45, 0);
    REQUIRE(dli.size() == 3);
}
TEST_CASE("Inserting float element at a position")
{
    dlf.insert(4.5, 2);
    REQUIRE(dlf.size() == 3);
}
TEST_CASE("Inserting char element at a position")
{
    dlc.insert('a', 2);
    REQUIRE(dlc.size() == 3);
}
TEST_CASE("Inserting string element at a position")
{
    dls.insert("This", 1);
    REQUIRE(dls.size() == 3);
}
TEST_CASE("Inserting long element at a position")
{
    dll.insert(127849332, 2);
    REQUIRE(dll.size() == 3);
}
TEST_CASE("Inserting double element at a position")
{
    dld.insert(4.59291939, 2);
    REQUIRE(dld.size() == 3);
}

TEST_CASE("Inserting element in the last position")
{
    dli.insert(55, 3);
    REQUIRE(dli.size() == 4);
}
TEST_CASE("Removing integer element in the first position")
{
    REQUIRE(dli.size() == 4);
    REQUIRE(dli.remove_front() == 45);
    REQUIRE(dli.size() == 3);
}
TEST_CASE("Removing float element in the first position")
{

    REQUIRE(dlf.size() == 3);
    REQUIRE(dlf.remove_front() == 4.07f);
    REQUIRE(dlf.size() == 2);
}
TEST_CASE("Removing char element in the first position")
{

    REQUIRE(dlc.size() == 3);
    REQUIRE(dlc.remove_front() == 'J');
    REQUIRE(dlc.size() == 2);
}
TEST_CASE("Removing string element in the first position")
{

    REQUIRE(dls.size() == 3);
    REQUIRE(dls.remove_front() == "Hello");
    REQUIRE(dls.size() == 2);
}

TEST_CASE("Removing integer element in the Last position")
{
    REQUIRE(dli.size() == 3);
    REQUIRE(dli.remove_back() == 55);
    REQUIRE(dli.size() == 2);
}
TEST_CASE("Removing double element in the Last position")
{
    REQUIRE(dld.size() == 3);
    REQUIRE(dld.remove_back() == 4.59291939);
    REQUIRE(dld.size() == 2);
}

TEST_CASE("Removing integer element at the Third position")
{
    dli.push_front(23);
    dli.push_front(44);
    dli.push_front(11);
    dli.push_front(9);
    REQUIRE(dli.size() == 6);
    dli.remove(3);
    REQUIRE(dli.size() == 5);
}
TEST_CASE("Removing long element at the Third position")
{
    dll.push_front(12893490);
    dll.push_front(12340987);
    dll.push_front(99872345);
    dll.push_front(12726483);
    REQUIRE(dll.size() == 7);
    dll.remove(3);
    REQUIRE(dll.size() == 6);
}

TEST_CASE("Removing element at the Invalid position greater than length")
{
    REQUIRE(dli.size() == 5);
    dli.remove(40);
    REQUIRE(dli.size() == 5);
}
TEST_CASE("Removing element at the Invalid negative position")
{
    REQUIRE(dli.size() == 5);
    dli.remove(-4);
    REQUIRE(dli.size() == 5);
}
TEST_CASE("Removing element at the length value")
{
    REQUIRE(dli.size() == 5);
    dli.remove(5);
    REQUIRE(dli.size() == 5);
}

TEST_CASE("Removing elements at the given range")
{
    REQUIRE(dli.size() == 5);
    dli.remove(2, 4);
    REQUIRE(dli.size() == 2);
}
TEST_CASE("Removing elements at the invalid negative range")
{
    REQUIRE(dli.size() == 2);
    dli.remove(-2, 4);
    REQUIRE(dli.size() == 2);
}
TEST_CASE("Removing elements at the invalid range where start is greater than end ")
{
    REQUIRE(dli.size() == 2);
    dli.remove(3, 1);
    REQUIRE(dli.size() == 2);
}
TEST_CASE("Removing elements at the invalid range where start is greater than length ")
{
    REQUIRE(dli.size() == 2);
    dli.remove(40, 50);
    REQUIRE(dli.size() == 2);
}
TEST_CASE("Clearing the integer Elements")
{
    dli.print_values();
    REQUIRE(dli.size() == 2);
    dli.clear();
    REQUIRE(dli.size() == 0);
    REQUIRE(dli.is_empty() == true);
}
TEST_CASE("Clearing the float Elements")
{
    dlf.print_values();

    REQUIRE(dlf.size() == 2);
    dli.clear();
    REQUIRE(dli.size() == 0);
    REQUIRE(dli.is_empty() == true);
}
TEST_CASE("Clearing the char Elements")
{
    dlc.print_values();

    REQUIRE(dlc.size() == 2);
    dlc.clear();
    REQUIRE(dlc.size() == 0);
    REQUIRE(dlc.is_empty() == true);
}
TEST_CASE("Clearing the String Elements")
{
    dls.print_values();

    REQUIRE(dls.size() == 2);
    dls.clear();
    REQUIRE(dls.size() == 0);
    REQUIRE(dls.is_empty() == true);
}
TEST_CASE("Clearing the Double Elements")
{
    dld.print_values();

    REQUIRE(dld.size() == 2);
    dld.clear();
    REQUIRE(dld.size() == 0);
    REQUIRE(dld.is_empty() == true);
}
TEST_CASE("Clearing the Long Elements")
{
    dll.print_values();

    REQUIRE(dll.size() == 6);
    dll.clear();
    REQUIRE(dll.size() == 0);
    REQUIRE(dll.is_empty() == true);
}

TEST_CASE("Removing element in the first position after clearing the list")
{
    REQUIRE(dli.remove_front() != 1);
}
TEST_CASE("Removing element in the last position after clearing the list")
{
    REQUIRE(dli.remove_back() != 1);
}
