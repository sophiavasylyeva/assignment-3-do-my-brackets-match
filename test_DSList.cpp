#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "DSList.h"


//tests couple functions from DSList by populating list, testing function, and checking if size of list changed appropriately based on purpose of function


TEST_CASE("insert", "[DSList]"){            
    DSList<int> test;
    REQUIRE(test.getsize() == 0);
    test.insert(10, 0);
    REQUIRE(test.getsize() == 1);   
}

TEST_CASE("pop_back", "[DSList]"){
     DSList<int> test;
     REQUIRE(test.getsize() == 0);
     test.insert(5,0);
     test.pop_back();
     REQUIRE(test.getsize() == 0);
}

TEST_CASE("pop_front", "[DSList]"){
     DSList<int> test;
     REQUIRE(test.getsize() == 0);
     test.insert(3,0);
     test.pop_front();
     REQUIRE(test.getsize() == 0);

}

TEST_CASE("isEmpty", "[DSList]"){
     DSList<int> test;
     REQUIRE(test.getsize() == 0);
     test.isEmpty();
     REQUIRE(test.getsize() == 0);

}

TEST_CASE("clear", "[DSList]"){
     DSList<int> test;
     REQUIRE(test.getsize() == 0);
     test.insert(3,0);
     REQUIRE(test.getsize() == 1);
     test.clear();
     REQUIRE(test.getsize() == 0);

}

  
    


  
// you can run the test using Run CTest in the task bar or by running the tests executable. 