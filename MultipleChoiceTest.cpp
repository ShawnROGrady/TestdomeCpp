//
//  MultipleChoiceTest.cpp
//  MultipleChoiceTest
//
//  Created by Shawn O'Grady on 12/5/17.
//  Copyright © 2017 Shawn O'Grady. All rights reserved.
//
/*
 This code is a practice C++ interview question from testdome.com
 https://www.testdome.com/for-developers/solve-question/9808
 
 Problem statement: Multiple choice test has several multiple choice questions. Each question can have only one correct answer. Additionally, timed multiple choice test can specify the time allowed for solving each question in the test.
 -The code seen at the url above satisfies this specification, but the customer complained that the memory usage of the program constantly increases. Fix this problem.
 
 +Problem is that memory is never de-allocated
    -fixed with a couple of simple class destructors
    -making destructor of MultipleChoiceTest class (the base class) important for when using TimedMultipleChoiceTest class as a derived class
        -this article helped me understand the logic behind this a bit better: http://www.gotw.ca/publications/mill18.htm
 
 + Runs well with 3/3 tests passed
 */
#include <stdio.h>
#include <iostream>
#include <string>

class MultipleChoiceTest
{
public:
    MultipleChoiceTest(int questionsCount)
    {
        this->questionsCount = questionsCount;
        answers = new int[questionsCount];
        for (int i = 0; i < questionsCount; i++)
        {
            answers[i] = -1;
        }
        
    }
    
    void setAnswer(int questionIndex, int answer)
    {
        answers[questionIndex] = answer;
    }
    
    int getAnswer(int questionIndex) const
    {
        return answers[questionIndex];
    }
    virtual ~MultipleChoiceTest(){
        //destructor, deallocate memory
        delete[] answers;
    }
    
protected:
    int questionsCount;
    
private:
    int* answers;
};

class TimedMultipleChoiceTest : public MultipleChoiceTest
{
public:
    TimedMultipleChoiceTest(int questionsCount)
    : MultipleChoiceTest(questionsCount)
    {
        times = new int[questionsCount];
        for (int i = 0; i < questionsCount; i++)
        {
            times[i] = 0;
        }
    }
    
    void setTime(int questionIndex, int time)
    {
        times[questionIndex] = time;
    }
    
    int getTime(int questionIndex) const
    {
        return times[questionIndex];
    }
    ~TimedMultipleChoiceTest()
    {
        //destructor, deallocate memory
        delete[] times;
    }
    
private:
    int* times;
};
/*
#ifndef RunTests
void executeTest()
{
    MultipleChoiceTest test(5);
    for (int i = 0; i < 5; i++)
    {
        test.setAnswer(i, i);
    }
    
    for (int i = 0; i < 5; i++)
    {
        std::cout << "Question " << i + 1 << ", correct answer: " << test.getAnswer(i) << "\n";
    }
}

int main()
{
    for (int i = 0; i < 3; i++)
    {
        std::cout << "Test: " << i + 1 << "\n";
        executeTest();
    }
}
#endif
*/
