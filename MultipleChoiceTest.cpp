//
//  MultipleChoiceTest.cpp
//  MultipleChoiceTest
//
//  Created by Shawn O'Grady on 12/5/17.
//  Copyright © 2017 Shawn O'Grady. All rights reserved.
//

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
