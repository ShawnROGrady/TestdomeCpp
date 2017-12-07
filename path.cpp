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
 
 + References: https://en.wikipedia.org/wiki/Cd_(command) , http://linuxcommand.org/lc3_lts0020.php
 
 + Only says its passing 1/4 tests, but I can't tell what I'm missing...
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
        pastPath=path;
    }
    
    std::string getPath() const
    {
        return currentPath;
    }
    
    void cd(std::string newPath)
    {
        
        int newPathLength=newPath.length();
        
        if (newPathLength==1&&(isspace(newPath[0])||newPath[0]=='/')){
            currentPath="/";
        }
        else if(newPathLength>0&&newPath[0]!='~'){
            int i=0;
            while(i<newPathLength){
                int pathLength=currentPath.length();
                if(newPath[i]=='.'&&newPath[i+1]=='.'){
                    //move up one directory
                    pastPath=currentPath;
                    if(pathLength>2){
                        currentPath.erase(pathLength-2,2);
                        i=i+3;
                    }
                    else{
                        //root directory
                        currentPath="/";
                        i=i+3;
                    }
                    
                }
                else if(newPath[i]=='/'){
                    //direct pathname
                    
                    pastPath=currentPath;
                    //currentPath.erase(0,pathLength);
                    currentPath.clear();
                    int j=0;
                    while(j<newPathLength){
                        //this is ok since we are assuming no invalid paths will be given
                        if(newPath[j]=='.'){
                            break;
                        }
                        currentPath+=newPath[j];
                        j++;
                        
                    }
                    
                    if(currentPath[j-1]=='/'){
                        currentPath.erase(j-1,1);   //get rid of extra '/'
                    }
                    
                    i=i+j;
                     
                    
                }
                else if(newPath[i]=='.'){
                    if(newPath[i+1]=='/'){
                        //relative pathname to child directory
                        i=i+2;
                    }
                    else{
                        i=i+1;
                    }
                    
                }
                
                else if(isspace(newPath[i])){
                    i++;    //just ignore spaces
                }
                 
                else if(newPath[i]=='-'){
                    //didn't say in problem statement to implement this, but figured I'd add it
                    swap(pastPath,currentPath);
                    i++;
                }
                else{
                    //relative pathname to child directory w/o "./"
                    pastPath=currentPath;
                    if (pathLength>1){
                        currentPath=currentPath+"/"+newPath[i];
                    }
                    else{
                        currentPath=currentPath+newPath[i];
                    }
                    i=i+2;
                }
            }
        }
        else{
            //cd command followed by nothing -> go to root directory
            currentPath="/";
        }
        
        
    }
    
private:
    std::string pastPath;
    std::string currentPath;
};
/*
#ifndef RunTests
int main()
{
    Path path("/a/b/c/d");
    //test cases:
    //path.cd("../x");  // '/a/b/c/x' -> example test case
    //path.cd("..");  // '/a/b/c' -> relative pathname to parent directory
    //path.cd("./x"); // '/a/b/c/d/x' -> relative pathname to child directory
    //path.cd("x");   // '/a/b/c/d/x' -> relative pathname to child directory
    //path.cd("/a/b/c"); // '/a/b/c' -> direct pathname to parent
    //path.cd("../../x"); // '/a/b/x'
    //path.cd("./x/../../y"); // 'a/b/c/y'
    //path.cd("x/../../y"); // 'a/b/c/y'
    //path.cd("../../../.."); // '/'
    //path.cd("x/..");    // '/a/b/c/d'
    //path.cd("");    // '/'
    //path.cd("/");   // '/'
    //path.cd("~");   // '/'
    //path.cd(".");   // '/a/b/c/d
    //path.cd("/x/y/z");  // '/x/y/z/' -> another direct pathname
    //path.cd("x/y/z  ");   // '/a/b/c/d/x/y/z'
    path.cd("/a/b/c/../x"); // '/a/b/x'
    
    std::cout << path.getPath();
}
#endif
*/
