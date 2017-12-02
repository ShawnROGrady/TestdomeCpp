//
//  twoSum.cpp
//  Two Sum
//
//  Created by Shawn O'Grady on 12/1/17.
//  Copyright © 2017 Shawn O'Grady. All rights reserved.
//

/*
 This code is a practice C++ interview question from testdome.com
 https://www.testdome.com/for-developers/solve-question/10283
 "Write a function that, given a vector and a target sum, returns zero-based indices of any two distinct elements whose sum is equal to the target sum.
 If there are no such elements, the function should return (-1, -1)."
 
 +Currently this function is taking too long to run
    -need to find better alternative to nested loops
 */


#include <stdio.h>
#include <iostream>
#include <vector>
#include <utility>


class TwoSum
{
public:
    static std::pair<int, int> findTwoSum(const std::vector<int>& list, int sum)
    {
        int ListLength=list.size();
        //std::cout<<"list length:"<<ListLength<<'\n';
        std::pair <int, int> match=std::pair <int, int>(-1,-1);
        for(int i=0; i<ListLength; i++){
            
            for(int j=i+1; j<ListLength-1; j++){
                if(list[i]+list[j]==sum){
                    //return std::pair<int, int> (i, j);
                    match.first=i;
                    match.second=j;
                    return match;
                }
            }
            
            
        }
        return match;
    }
};
