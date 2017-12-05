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
 
 + This sounds a lot like a doubly-linked list queue, with the only modification being that you an enqueue+dequeue from either end
 
 + Runs well with 3/3 tests passed
 */

#include <stdexcept>
#include <iostream>
#include <stdio.h>
//basically just the node for a dll
class TrainNode{
private:
    int value;
    TrainNode *leftTrain;
    TrainNode *rightTrain;
public:
    TrainNode(){leftTrain=rightTrain=NULL;}
    TrainNode(int wagonId){
        value=wagonId;
        leftTrain=rightTrain=NULL;
    }
    int getValue(){return value;}
    void setLeftTrain(TrainNode *newNode){leftTrain=newNode;}
    void setRightTrain(TrainNode *newNode){rightTrain=newNode;}
    TrainNode* getRightTrain(){return rightTrain;}
    TrainNode* getLeftTrain(){return leftTrain;}
};

class TrainComposition
{
private:
    TrainNode *leftMost;
    TrainNode *rightMost;
public:
    TrainComposition(){leftMost=rightMost=NULL;}
    void attachWagonFromLeft(int wagonId)
    {
        TrainNode *tmp=new TrainNode(wagonId);
        if(leftMost !=NULL){
            //there are trains in the composition
            leftMost->setLeftTrain(tmp);
            tmp->setRightTrain(leftMost);
            leftMost=tmp;
        }else{
            leftMost=tmp;
            rightMost=tmp;
        }
    }
    
    void attachWagonFromRight(int wagonId)
    {
        TrainNode *tmp=new TrainNode(wagonId);
        if(rightMost !=NULL){
            //there are trains in the composition
            rightMost->setRightTrain(tmp);
            tmp->setLeftTrain(rightMost);
            rightMost=tmp;
            
        }else{
            leftMost=tmp;
            rightMost=tmp;
        }
    }
    
    int detachWagonFromLeft()
    {
        TrainNode *tmp;
        if(leftMost!=NULL){
            //there are trins in the composition
            tmp=leftMost;
            leftMost=leftMost->getRightTrain();
            int tmpValue=tmp->getValue();
            delete tmp;
            return tmpValue;
        }else{
            return NULL;
        }
    }
    
    int detachWagonFromRight()
    {
        TrainNode *tmp;
        if(rightMost!=NULL){
            //there are trins in the composition
            tmp=rightMost;
            rightMost=rightMost->getLeftTrain();
            int tmpValue=tmp->getValue();
            delete tmp;
            return tmpValue;
        }else{
            return NULL;
        }
    }
};
