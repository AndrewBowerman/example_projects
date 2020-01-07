/*  heapofStudents
    Andrew Bowerman
    7/19/2017

    student.h
    header for Studentclass
*/
#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED

#include "date.h"
#include "address.h"

class Student {
    private:
        string firstName;
        string lastName;

        int gpa;
        int credHrs;

    public:
        Student();
        Student(string, string, int, int); //constructor w/properties
        ~Student();
        //accessors
        string getFirstName();
        void setFirstName(string);
        string getLastName();
        void setLastName(string);
        int getGpa();
        void setGpa(int);
        int getCredHrs();
        void setCredHrs(int);

        Address address; //contains all fields required in assignment
        Date dob;
        Date gradDate;


};//end class

#endif // STUDENT_H_INCLUDED
