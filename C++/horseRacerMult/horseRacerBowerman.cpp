/*
    horseRacer.cpp
    OOP in C++
    runs a racetrack simulation
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 6 //controls number of lanes and horses in the race

using namespace std;

//CLASS PROTOTYPES

class Horse {
    private:
        int position; // where the horse is
    public:
        Horse(); //constructor
        void advance(); //rolls for movement
        int getPosition(); //returns position
        void setPosition(int); // adds movement roll to position
}; // end Horse

class Race {
    private:
        Horse herd[MAX]; // our stable
    public:
        int length; // how long the track is
        Race();
        Race (int); //sets length of track
        void printLane (int); //takes the horse' number as argument
        void start(); // begins race loop

}; //end Race

//CLASSES

// begin Horse Class
Horse::Horse(){
    Horse::position = 0;
    srand(time(NULL)); //through unholy rites thought lost to time, each horse grows a horrific opposable thumb
    }; //end constructor

    int Horse::getPosition() {
        return position; }

    void Horse::setPosition(int val) {
        Horse::position = (position + val); }

    void Horse::advance(){
        int roll;
        /*coin toss to advance by one position

        though the magick seemed to be holding,
        their thumbs seemed ungainly and painful to walk on.
        some times they stumbled forward with a shrieking limp;
        at others they froze, wild-eyed, locked in a rictus of pain and terror.*/

        roll = rand() % 2; //roll a 0 or a 1
        setPosition(roll); //sends value of roll to be added to position

        };//end advance()
// end Horse Class

//begin Race Class
Race::Race(){
        Race::length = 25;
    };//end constructor

    Race::Race (int length){
        Race::length = 25; //set track length
        };

    void Race::printLane (int horseNum){
        int i, position, remaining;// for loop sentry, horse reference, remaining track length
        Horse currentHorse;
        //determine horse location
        currentHorse = herd[horseNum];
        position = currentHorse.getPosition();

        //print preceding track
        for (i = 0; i < position; i++){
            cout << "." ;
            };
        //print horse
        cout << horseNum;
        //print remaining track
        remaining = length - position;
        for (i = 0; i < (remaining - 1); i++){
            cout << "." ;
                };
            cout << "|";
        };//end printLane

    void Race::start(){
        bool keepRacing; //while sentry
        keepRacing = true;
        int i, numWin, found; //for sentry, number of winners at victory check, found horses at end
        numWin = 0;

        //clear screen
        for (i=0; i < 50; i++) {
            cout << endl;
        };
        //print all lanes to begin race
        cout << "The race is about to start!" << endl;
        for (i=0; i < MAX; i++) {
            Race::printLane(i);
            cout << endl;
            };
        // wait for user
        cout << "Press ENTER to continue: " ;
        cin.ignore();

        //begin race do-while loop
        do {
            //clear screen
            for (i=0; i < 50; i++) {
                cout << endl;
                };//end clearscreen

            //give all horses an advancement round
            cout << "And they're off!" << endl;
            for (i=0; i < MAX; i++) {
                herd[i].advance();
                };//horses have advanced

            //print new lanes with new horse positions
            for (i=0; i < MAX; i++) {

                //check for victory state
                if ((herd[i].getPosition()) == Race::length){
                    cout << "Horse " << i << " has crossed the finish line!";
                    keepRacing = false;
                    numWin++;
                    cout << endl;
                    }//end if

                //otherwise print the lane
                else{
                    Race::printLane(i);
                    cout << endl;
                }; //end else

            };//end for

        // wait for user before starting next round
        cout << "Press ENTER to continue: " ;
        cin.ignore();

        }while (keepRacing == true); //end race do-while

        //clear screen
        for (i=0; i < 50; i++) {
            cout << endl;
        };

        //if you're here, someone has won
        int victors[(numWin)]; //array for horses that cross finish
        found = 0; //horses found at finish line
        for (i=0; i < MAX-1; i++){
            if ((herd[i].getPosition()) == Race::length){ //scan for horses at finish line
                victors[found] = i; //collect horse numbers from finish into victors group
                found++;
                }//end if
            };//end for

        //check for multiple victors
        if (numWin > 1){ //tiebreaker round
            // print tiebreaker message.
            cout << "A photo finish! Horses: " << endl;
                for (i=0; (i < (numWin)); i++){ //print tiebreaker horses
                    cout << victors[i] << endl ;
                    };// end for
            cout << "are almost too close to call!" << endl <<
                    "Let's take a look at the camera!" << endl <<
                    "Press ENTER to continue: " ;
            cin.ignore();
            //roll for victor
            numWin = rand()% numWin;
            victors[0] = victors[numWin]; //reset victor

            };// end tiebreaker

        //clear screen
        for (i=0; i < 50; i++) {
            cout << endl;
        };

        cout << "Horse " << victors[0] << " is the winner!" << endl <<
                "Press ENTER to continue: " ;
            cin.ignore();

    };//end start()

//end race class

int main()
{
    Race a; // make race instance
    a.start(); //start race
    return 0;
}
