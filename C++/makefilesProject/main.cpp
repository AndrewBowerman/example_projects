/*  makefilesProject.cpp
     main.cpp - imports .h of library and book classes
                instantiates library
*/

#include <iostream>

#include "library.h"
#include "book.h"

using namespace std;

int main()
{
    Library a;
    a.printTitles();
}
