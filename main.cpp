#include <iostream>
#include <algorithm>

#include "DSList.h"
#include "DSStack_array.h"
#include "check_brackets.h"
#include <chrono>

using namespace std;

// file names to check are passed on as command line arguments
int main(int argc, char **argv)
{
    check_brackets checker; //creates check_brackets object that will run through DSStack_array to test functions

    std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
    start= std::chrono::high_resolution_clock::now();

    for(int i = 1; i < argc; i++){ //for DSList
        std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
        start= std::chrono::high_resolution_clock::now();

        checker.checkbrackets(argv[i]); //iterates through check_brackets that calls functions
        
        end=std::chrono::high_resolution_clock::now();              
        std::chrono::duration<double> time= end-start;
        cout << "DSList time: " << time.count() << endl;
    }

    for(int i = 1; i < argc; i++){ //for DSStack_array
        std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
        start= std::chrono::high_resolution_clock::now();
        
        checker.checkbrackets(argv[i]); //iterates through check_brackets that calls functions
        
        end=std::chrono::high_resolution_clock::now();             
        std::chrono::duration<double> time= end-start;
        cout << "DSStack_array time: " << time.count() << endl;
    }

    end=std::chrono::high_resolution_clock::now();             
    std::chrono::duration<double> time= end-start;
    cout << endl;
    cout << "whole process: " << time.count() << endl;

    return 0;               
}

// in the terminal type `cd build` and then `./check_brackets test_data/*`
