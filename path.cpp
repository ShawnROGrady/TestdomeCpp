//
//  path.cpp
//  Path
//
//  Created by Shawn O'Grady on 12/5/17.
//  Copyright © 2017 Shawn O'Grady. All rights reserved.
//

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
