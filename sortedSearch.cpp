//
//  sortedSearch.cpp
//  sortedSearch
//
//  Created by Shawn O'Grady on 12/2/17.
//  Copyright © 2017 Shawn O'Grady. All rights reserved.
//

/*
 This code is a practice C++ interview question from testdome.com
 https://www.testdome.com/for-developers/solve-question/11891
 
  Problem statement: "Implement function countNumbers that accepts a sorted vector of integers and counts the number of vector elements that are less than the parameter lessThan."
 
  +Currently function is taking too long to run
    -need to find alternative approach
 */

#include <stdio.h>
#include <vector>
#include <stdexcept>
#include <iostream>



class SortedSearch
{
public:
    static int countNumbers(const std::vector<int>& sortedVector, int lessThan)
    {
        int vectorLength=sortedVector.size();
        int i=0;    //# of vector elements less than the given parameter
        while(i<vectorLength){
            if(sortedVector[i]>=lessThan){
                //return i;
                break;
            }
            i++;
        }
        return i;
    }
};
