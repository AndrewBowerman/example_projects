/*  heapofStudents
    Andrew Bowerman
    7/19/2017

    address.cpp
    code for address class used in student class
*/
#include "address.h"

Address::Address(){ //np const
    Address::address1 = "";
    Address::address2 = "";
    Address::city = "";
    Address::state = "";
    Address::zip = "";
}

Address::Address(string addr1, string addr2, string city, string state , string zip){ //constructor w/properties
    Address::address1 = addr1;
    Address::address2 = addr2;
    Address::city = city;
    Address::state = state;
    Address::zip = zip;
}

//accessors
string Address::getAddress1(){
    return address1;
}

void Address::setAddress1(string addr1){
   Address::address1 = addr1;
}

string Address::getAddress2(){
    return address2;
}

void Address::setAddress2(string addr2){
    Address::address2 = addr2;
}

string Address::getCity(){
    return Address::city;
}

void Address::setCity(string city){
    Address::city = city;
}

string Address::getState(){
    return Address::state;
}

void Address::setState(string state){
    Address::state = state;
}

string Address::getZip(){
    return Address::zip;
}

void Address::setZip(string zip){
    Address::zip = zip;
}

//end class
