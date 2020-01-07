#ifndef LIBRARY_H_INCLUDED
#define LIBRARY_H_INCLUDED

#include "book.h"
#define MAXBOOKS 100000

class Library {
    private:
        Book b[MAXBOOKS];
        int bookNum;
    public:
        //constructors
        Library();//np constructor
        //accessors required by rubric (skipping others to get on to Heap of Students)
        int getBookNum();
        void printTitles();

}; // end

#endif // LIBRARY_H_INCLUDED
