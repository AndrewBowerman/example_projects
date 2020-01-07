#ifndef BOOK_H_INCLUDED
#define BOOK_H_INCLUDED

#include <iostream>

using namespace std;

class Book {
    private:
        string title;
        string author;
        int pageNum;
    public:
        //constructors
        Book();//np constructor
        Book (string inctitle, int incpageNum); //paramaterized constructor
        //accessors required by rubric (skipping others to get on to Heap of Students)
        string getTitle();
        int getPageNum();

}; // end

#endif // BOOK_H_INCLUDED
