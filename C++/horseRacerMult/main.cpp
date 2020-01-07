/*
    Andrew Bowerman
    7/13/2017
    CS 240
    ------
    horseRacerMult.cpp

    This version is the same program as horseRacer.cpp
    but makes use of multiple files.
        ____________
        header files:
        ------------
        horse.h
        race.h

        __________
        c++ files:
        ----------
        horse.cpp
        race.cpp

        _____
        also:
        -----
        makefile
        readMe

    OOP in C++
    racetrack simulation

*/

#include "horse.h"
#include "race.h"

using namespace std;

int main()
{
    Race a; // make race instance
    a.start(); //start race
    return 0;
}
