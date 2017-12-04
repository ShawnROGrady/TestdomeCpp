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
        if(sortedVector.back()<=lessThan){
            //all elements in vector less than given parameter
            //int vectorLength=sortedVector.size();
            if(sortedVector.back()==lessThan){
                return sortedVector.size()-1;
            }
            else{
                return sortedVector.size();
            }
        }
        else if(sortedVector.front()>=lessThan){
            //no elements less than given parameter
            return 0;
        }
        else{
            
            int vectorLength=sortedVector.size();
            int i=1;  //# of vector elements less than the given parameter
            int j=vectorLength/2;
            int k=vectorLength;
            while(k>1){
                if(sortedVector[j]<lessThan){
                    i=j;
                    j=j+j/2;
                }else if(sortedVector[j]>lessThan){
                    i=j;
                    j=j/2;
                }
                else{
                    //middle value of vector was equal to less than
                    i=j;
                    break;
                }
                k=k/2;
                
            }
            //i=j-1;
            if(sortedVector[j]<lessThan){
                while(j<vectorLength/k){
                    if(sortedVector[j]>=lessThan){
                        //return j;
                        i=j;
                        break;
                    }
                    j++;
                }
            }else if(sortedVector[j]>lessThan){
                while(i<j){
                    if(sortedVector[i]>=lessThan){
                        //return i;
                        break;
                    }
                    i++;
                }
                
            }
            else{
                i=j;
            }
            
            
            
        return i;
            
        }
    }
};

