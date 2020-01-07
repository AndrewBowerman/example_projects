/*  heapofStudents
    Andrew Bowerman
    7/19/2017

    student.cpp
    code for Studentclass
*/
#include "student.h"
#include "address.h"
#include "date.h"

Student::Student(){
    Student::firstName = "Ymous";
    Student::lastName = "Anon";
    Student::address = Address(); //contains all fields required in assignment
    Student::dob = Date();
    Student::gradDate = Date();
    int gpa = 0;
    int credHrs = 0;
}
Student::Student(string firstName, string lastName, int gpa, int credHrs){ //constructor w/properties
    Student::firstName = firstName;
    Student::lastName = lastName;
    /*  since I'm making the array of students before they
        have data, the classes should already be ready to receive data.
        I think I'll be using setters in a for loop to populate each class, so
        this whole constructor isn't currently going to be utilized anyway.
    Student::address = Address(); //contains all fields required in assignment
    Student::dob = Date();
    Student::gradDate = Date();
    */
    Student::gpa = gpa;
    Student::credHrs = credHrs;
}
Student::~Student(){
}

//accessors
string Student::getFirstName(){
    return firstName;
}
void Student::setFirstName(string firstName){
    Student::firstName = firstName;
}

string Student::getLastName(){
    return lastName;
}
void Student::setLastName(string lastName){
    Student::lastName = lastName;
}

int Student::getGpa(){
    return gpa;
}
void Student::setGpa(int gpa){
    Student::gpa = gpa;
}

int Student::getCredHrs(){
    return credHrs;
}
void Student::setCredHrs(int credHrs){
    Student::credHrs = credHrs;
}

