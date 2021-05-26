#include "catch_amalgamated.hpp"
//test cases for the successful testing for lru
#include "lru.h"

lru <int> ca(4);

TEST_CASE("referring pages lesser than capacity pages")
{
    ca.refer(1);
    ca.refer(2);
    ca.display();
    REQUIRE(ca.size() == 2);
}

TEST_CASE("referring pages greater than capacity pages")
{
    ca.refer(1);
    ca.refer(2);
    ca.refer(3);
    ca.refer(1);
    ca.refer(4);
    ca.refer(5);
    ca.display();
    REQUIRE(ca.size() == 4);
}