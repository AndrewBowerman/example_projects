/*  heapofStudents
    Andrew Bowerman
    7/19/2017

    date.cpp
    code for Date class used in Student class
*/

#include "date.h"

Date::Date(){
    Date::day = "00";
    Date::month = "00";
    Date::year = "0000";
}

Date::Date(string day, string month, string year){ //constructor w/day month and year
    Date::day = day;
    Date::month = month;
    Date::year = year;
}

//accessors
string Date::getDay(){
    return day;
}
void Date::setDay(string day){
    Date::day = day;
}

string Date::getMonth(){
    return month;
}
void Date::setMonth(string month){
    Date::month = month;
}

string Date::getYear(){
    return year;
}
void Date::setYear(string year){
    Date::year = year;
}

string Date::getDate(){
    string date;
    date = (day + "/" + month + "/" + year);
    return date;
}
