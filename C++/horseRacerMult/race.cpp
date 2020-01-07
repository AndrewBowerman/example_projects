//race.cpp
#include "horse.h"
#include "race.h"

using namespace std;

//begin Race Class
Race::Race(){
    Race::length = 25;
    };//end constructor

    Race::Race (int length){
        Race::length = 25; //set track length
                           //I don't think I'm using this one correctly since I never needed to call it
                           //It's in the UML though
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
        bool keepRacing; //do-while sentry
        keepRacing = true;
        int i, numWin, victorsElement; //for sentry, number of winners at victory check, horse identifier
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

                //check for victory lanes
                if ((herd[i].getPosition()) == Race::length){
                    cout << "Horse " << i << " has crossed the finish line!";
                    keepRacing = false;
                    numWin++; //increment number of horses at finish line
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

        // VICTORY STATE
        //clear screen
        for (i=0; i < 50; i++) {
            cout << endl;
        };

        // create array of horses that finished
        int victors[(numWin-1)]; //(number of winners - 1)
        victorsElement = 0; //horseNum of horse found at finish line will be placed into this element of the victors array
        for (i=0; i < MAX-1; i++){
            if ((herd[i].getPosition()) == Race::length){ //scan for horses at finish line
                victors[victorsElement] = i; //collect horse numbers from finish into victors group
                victorsElement++;
                }//end if
            };//end for

        //check for multiple victors

        if (numWin > 1){
            // tiebreaker round
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
