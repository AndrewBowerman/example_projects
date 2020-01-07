// book.cpp
// code for book.h
#include "book.h"

Book::Book(){//np constructor
    title = "Untitled";
    pageNum = 0;
    author = "Anon";
};

Book::Book (string inctitle, int incpageNum){ //paramaterized constructor
    title = inctitle;
    pageNum = incpageNum;
    author = "Anon";
};

//accessors required by rubric (skipping others to get on to Heap of Students)
string Book::getTitle(){
    return title;
};

int Book::getPageNum(){
    return pageNum;
};
