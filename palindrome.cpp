//
//  palindrome.cpp
//  Palindrome
//
//  Created by Shawn O'Grady on 12/1/17.
//  Copyright © 2017 Shawn O'Grady. All rights reserved.
//
/*
 This code is a practice C++ interview question from testdome.com
 https://www.testdome.com/for-developers/solve-question/7284
 "Write a function that checks if a given word is a palindrome. Character case should be ignored."
 */

#include <stdio.h>
#include <string>
#include <stdexcept>
#include <iostream>

class Palindrome{
public:
    static bool isPalindrome(const std::string &word){
        int stringLength=word.length();
        for(int i=0; i<stringLength; i++){
            if(tolower(word[i])!=tolower(word[stringLength-i-1])){
                //converting chars in string to lower case for comparison
                //cout<< "wordArray["<<i<<"] != wordArray["<<stringLength-i-1<<"]"<<endl;   //debug
                return false;
            }
        }
        return true;
    }
};
