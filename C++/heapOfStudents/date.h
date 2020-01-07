/*  heapofStudents
    Andrew Bowerman
    7/19/2017

    date.h
    header for Date class used in Student class
*/
#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED

#include <iostream>
using namespace std;

class Date {
    private:
        string day;
        string month;
        string year;

    public:
        Date();
        Date(string, string, string); //constructor w/day month and year
        //accessors
        string getDay();
        void setDay(string);
        string getMonth();
        void setMonth(string);
        string getYear();
        void setYear(string);
        string getDate(); //returns date formatted MM/DD/YYYY as a string

};//end class Date
#endif // DATE_H_INCLUDED
