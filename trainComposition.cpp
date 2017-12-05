//
//  trainComposition.cpp
//  trainComposition
//
//  Created by Shawn O'Grady on 12/5/17.
//  Copyright © 2017 Shawn O'Grady. All rights reserved.
//

/*
 This code is a practice C++ interview question from testdome.com
 https://www.testdome.com/for-developers/solve-question/11908
 
 Problem statement: A TrainComposition is built by attaching and detaching wagons from the left and the right sides.
    -For example, if we start by attaching wagon 7 from the left followed by attaching wagon 13, again from the left, we get a composition of two wagons (13 and 7 from left to right). 
    -Now the first wagon that can be detached from the right is 7 and the first that can be detached from the left is 13.
    -Implement a TrainComposition that models this problem
 */

#include <stdexcept>
#include <iostream>
#include <stdio.h>

class TrainComposition
{
public:
    void attachWagonFromLeft(int wagonId)
    {
        throw std::logic_error("Waiting to be implemented");
    }
    
    void attachWagonFromRight(int wagonId)
    {
        throw std::logic_error("Waiting to be implemented");
    }
    
    int detachWagonFromLeft()
    {
        throw std::logic_error("Waiting to be implemented");
    }
    
    int detachWagonFromRight()
    {
        throw std::logic_error("Waiting to be implemented");
    }
};
