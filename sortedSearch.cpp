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
        
        if(sortedVector.back()<lessThan){
            //all elements in vector less than given parameter
            int vectorLength=sortedVector.size();
            return vectorLength;
        }
        else if(sortedVector.front()>=lessThan){
            //no elements less than given parameter
            return 0;
        }
        else{
  
            int vectorLength=sortedVector.size();
            if(sortedVector.back()==lessThan){
                return vectorLength-1;
            }
            else{
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
            
        }
        
    }
};
