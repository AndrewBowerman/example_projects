//horse.h
#ifndef HORSE_H_EXISTS
#define HORSE_H_EXISTS

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

class Horse {
    private:
        int position; // where the horse is
    public:
        Horse(); //constructor
        void advance(); //rolls for movement
        int getPosition(); //returns position
        void setPosition(int); // adds movement roll to position
}; // end Horse

#endif
