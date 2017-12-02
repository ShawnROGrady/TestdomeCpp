//
//  userInput.cpp
//  User Input
//
//  Created by Shawn O'Grady on 12/1/17.
//  Copyright © 2017 Shawn O'Grady. All rights reserved.
//
/*
 This code is a practice C++ interview question from testdome.com
 https://www.testdome.com/for-developers/solve-question/11966
 
 Problem statement:
 +User interface contains two types of user input controls: TextInput, which accepts all characters and NumericInput, which accepts only digits.
 +Implement the following methods:
    -add on class TextInput - adds the given character to the current value
    -getValue on class TextInput - returns the current value
    -add on class NumericInput - overrides the base class method so that each non-numeric character is ignored
 */
#include <stdio.h>
#include <iostream>
#include <string>

class TextInput{
private:
    std::string value;
public:
    virtual void add(char c){
        value=value+c;
    }
    std::string getValue() {
        return value;
    }
    
};
class NumericInput: public TextInput{
private:
    //std::string value;
public:
    void add(char c){
        if(!isalpha(c)){
            //is numeric
            return TextInput::add(c);
        }
        
    }
};
