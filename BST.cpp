//
//  BST.cpp
//  BST
//
//  Created by Shawn O'Grady on 12/1/17.
//  Copyright © 2017 Shawn O'Grady. All rights reserved.
//
/*
 This code is a practice C++ interview question from testdome.com
 https://www.testdome.com/for-developers/solve-question/12977

 Problem statement: "Write a function that checks if a given binary search tree contains a given value"
 */

#include <stdio.h>
#include <string>
#include <iostream>

class Node
{
public:
    Node(int value, Node* left, Node* right)
    {
        this->value = value;
        this->left = left;
        this->right = right;
    }
    
    int getValue() const
    {
        return value;
    }
    
    Node* getLeft() const
    {
        return left;
    }
    
    Node* getRight() const
    {
        return right;
    }
    
private:
    int value;
    Node* left;
    Node* right;
};
class BinarySearchTree
{
public:
    static bool contains(const Node& root, int value)
    {
    
            if(root.getValue()==value){
                return true;
            }
            else if(root.getValue()<value){
                //value is greater than that held by node we are at
                if(root.getRight()!=NULL){
                    return contains(*root.getRight(),value);
            
                }
            
            }else{
            //value is less than that held by node we are at
                if(root.getLeft()!=NULL){
                    return (contains(*root.getLeft(),value));
            
                }
            
            }

        return false;
    }
};
