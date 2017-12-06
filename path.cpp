//
//  path.cpp
//  Path
//
//  Created by Shawn O'Grady on 12/5/17.
//  Copyright © 2017 Shawn O'Grady. All rights reserved.
//
/*
 This code is a practice C++ interview question from testdome.com
 https://www.testdome.com/for-developers/solve-question/12281
 
 Problem statement: Write a function that provides change directory (cd) function for an abstract file system.
    -additional notes:
        -root path is '/'
 `      -path separator is '/'
        -parent directory is addressable as ".."
        -directory names consist only of English alphabet letters (A-Z and a-z)
        -the function should support both realtive and absolute paths
        -the function will not be passed any invalid paths
        -do not use built-in path-related functions
 */
#include <stdio.h>
#include <iostream>
#include <string>
#include <stdexcept>

class Path
{
public:
    Path(std::string path)
    {
        currentPath = path;
    }
    
    std::string getPath() const
    {
        return currentPath;
    }
    
    void cd(std::string newPath)
    {
        throw std::logic_error("Waiting to be implemented");
    }
    
private:
    std::string currentPath;
};
/*
#ifndef RunTests
int main()
{
    Path path("/a/b/c/d");
    path.cd("../x");
    std::cout << path.getPath();
}
#endif
*/
