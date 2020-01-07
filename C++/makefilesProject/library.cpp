//library.cpp
//code for library class
//andrew bowerman

#include "library.h"

Library::Library(){//np constructor
    bookNum = 100000;
    };


//accessors required by rubric (skipping others to get on to Heap of Students)
int Library::getBookNum(){
    return bookNum;
    };

void Library::printTitles(){
    cout << "Titles" ;
    };
