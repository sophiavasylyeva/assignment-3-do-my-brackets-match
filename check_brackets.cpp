#include "check_brackets.h"
#include <fstream>
#include <iostream>

                                                        //correct assign 3!
int check_brackets::checkbrackets(char* file){

    std::ifstream stream(file);

    if(!stream.is_open()){ //if file is not opened, throws error
        std::cout << file << "failed to open" << std::endl;
        return 1;

    }

    int counter = 0;
    std::string line;
    DSStack_array <char> brackets; //creates two DSStack_array vectors that will be iterated through and will indicate which bracket and line number a mismatch occurs
    DSStack_array <int> numbers;
    while(!stream.eof()){
        counter++;
        getline(stream, line); //reads in line of data
        for(int i = 0; i < line.length(); i++){
            if((line.at(i) == '[') || (line.at(i) == '(') || (line.at(i) == '{')){
                brackets.push(line.at(i));
                numbers.push(counter); //if bracket is found, it's noted
            }
            else if((line.at(i) == ']') || (line.at(i) == ')') || (line.at(i) == '}')){
                if(brackets.getSize() == 0){
                    std::cout << " error: stray close bracket " << line.at(i) << " found on" << counter << std::endl; //if closed bracket is found, error is thrown
                    return 1;
                }
                else if((brackets.peek() == '(' && line[i] != ')') || (brackets.peek() == '[' && line[i] != ']') || (brackets.peek() == '{' && line[i] != '}')){
                    std::cout << file << " error: " << brackets.top() << " on line number " << numbers.top() << " is mismatched with " << line.at(i)  << " on line number " << counter << std::endl;
                    //if brackets mismatch, error with bracket type and line number is returned
                    return 1;   
                }
                else if ((line.at(i) == '//') || (line.at(i) == '/*')){
                    std::cout << " error: found comment " << line.at(i) << " found on" << counter << std::endl;
                    //checks for comments and throws error
                    //check if characters are next to each other, throw error 
                    return 1;
                }
            
                else {
                    brackets.pop(); 
                    numbers.pop();
                    // std::cout << "no errors!" << std::endl;
                }
            }
            
        }
    }
    stream.close();
    if(brackets.isEmpty() == true){
        std::cout << file << " ok" << std::endl; //if no bracket mismatch, code is good
        return 0;
    }
    else 
        std::cout << " stray open bracket " << brackets.top() << " found on line number " << numbers.top() << std::endl; //otherwise, there is error

    return 1;
}

int check_brackets::checkbracketsList(char* file){

    std::ifstream stream(file);

    if(!stream.is_open()){ //if file is not opened, throws error
        std::cout << file << "failed to open" << std::endl;
        return 1;

    }

    int counter = 0;
    std::string line;
    DSStack_list <char> brackets; //creates two DSStack_array vectors that will be iterated through and will indicate which bracket and line number a mismatch occurs
    DSStack_list <int> numbers;
    while(!stream.eof()){
        counter++;
        getline(stream, line); //reads in line of data
        for(int i = 0; i < line.length(); i++){
            if((line.at(i) == '[') || (line.at(i) == '(') || (line.at(i) == '{')){
                brackets.push(line.at(i));
                numbers.push(counter); //if bracket is found, it's noted
            }
            else if((line.at(i) == ']') || (line.at(i) == ')') || (line.at(i) == '}')){
                if(brackets.getsize() == 0){
                    std::cout << " error: stray close bracket " << line.at(i) << " found on" << counter << std::endl; //if closed bracket is found, error is thrown
                    return 1;
                }
                else if((brackets.peek() == '(' && line[i] != ')') || (brackets.peek() == '[' && line[i] != ']') || (brackets.peek() == '{' && line[i] != '}')){
                    std::cout << file << " error: " << brackets.top() << " on line number " << numbers.top() << " is mismatched with " << line.at(i)  << " on line number " << counter << std::endl;
                    //if brackets mismatch, error with bracket type and line number is returned
                    return 1;   
                }
                else if ((line.at(i) == '//') || (line.at(i) == '/*')){
                    std::cout << " error: found comment " << line.at(i) << " found on" << counter << std::endl;
                    //checks for comments and throws error
                    //check if characters are next to each other, throw error 
                    return 1;
                }
            
                else {
                    brackets.pop(); 
                    numbers.pop();
                    // std::cout << "no errors!" << std::endl;
                }
            }
            
        }
    }
    stream.close();
    if(brackets.isEmpty() == true){
        std::cout << file << " ok" << std::endl; //if no bracket mismatch, code is good
        return 0;
    }
    else 
        std::cout << " stray open bracket " << brackets.top() << " found on line number " << numbers.top() << std::endl; //otherwise, there is error

    return 1;
}
