//race.h
#ifndef RACE_H_EXISTS
#define RACE_H_EXISTS

#define MAX 9

#include "horse.h"

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

class Race {
    private:
        Horse herd[MAX]; // our stable
    public:
        int length; // how long the track is
        Race();
        Race (int); //sets length of track //currently unused in my program
        void printLane (int); //takes the horse' number as argument
        void start(); // begins race loop

}; //end Race

#endif
