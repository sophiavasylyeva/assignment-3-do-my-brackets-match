#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "DSStack_array.h"


//tests couple functions from DSStack_array by testing function and checking if size of array changed appropriately based on purpose of function


TEST_CASE("push", "[DSStack_array]"){
     DSStack_array<int> test;
     REQUIRE(test.getSize() == 0);
     test.push(10);
     REQUIRE(test.getSize() == 1);
}

TEST_CASE("isEmpty", "[DSStack_array]"){
     DSStack_array<int> test;
     REQUIRE(test.getSize() == 0);
     test.isEmpty();
     REQUIRE(test.getSize() == 0);
}

TEST_CASE("getSize", "[DSStack_array]"){               //FIX ME You don't test the copy constructor or the copy assignment operator.
     DSStack_array<int> test;
     REQUIRE(test.getSize() == 0);
     test.push(5);
     //test.getSize();
     REQUIRE(test.getSize() == 1);
}

TEST_CASE("clear", "[DSStack_array]"){
     DSStack_array<int> test;
     test.push(10);
     REQUIRE(test.getSize() == 1);
     test.clear();
     REQUIRE(test.getSize() == 0);
}

TEST_CASE("pop", "[DSStack_array]"){
     DSStack_array<int> test;
     test.push(5);
     REQUIRE(test.getSize() == 1);
     test.pop();
     REQUIRE(test.getSize() == 0);
}


// you can run the test using Run CTest in the task bar or by running the tests executable. 

       