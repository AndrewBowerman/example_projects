/*  heapofStudents
    Andrew Bowerman
    7/19/2017

    address.h
    header for address class used in student class
*/
#ifndef ADDRESS_H_INCLUDED
#define ADDRESS_H_INCLUDED

#include <string>
using namespace std;

class Address {
    private:
        std::string address1;
        std::string address2;
        std::string city;
        std::string state;
        std::string zip;

    public:
        Address();
        Address(std::string, std::string, std::string, std::string, std::string); //constructor w/properties
        //accessors
        string getAddress1();
        void setAddress1(string);
        string getAddress2();
        void setAddress2(string);
        string getCity();
        void setCity(string);
        string getState();
        void setState(string);
        string getZip();
        void setZip(string);

};//end class


#endif // ADDRESS_H_INCLUDED
