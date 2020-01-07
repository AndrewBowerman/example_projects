//horse.cpp
#include "horse.h"

// begin Horse Class
Horse::Horse(){
    Horse::position = 0;
    srand(time(NULL)); //through unholy rites thought lost to time, each horse grows a horrific, opposable thumb
    }; //end constructor

    int Horse::getPosition() {
        return position; }

    void Horse::setPosition(int val) {
        Horse::position = (position + val); }

    void Horse::advance(){
        int roll;
        /*coin toss to advance by one position

        from the field notes of inquisitor holbjorn, c.6251 ADE

        though the magick bound the horses' modifications tightly,
        their new thumbs appeared ungainly and painful to walk upon.
        at times they stumbled forward with a shrieking limp;
        at others they froze, wild-eyed, locked in a rictus of pain and terror.

        the crowd continued to goad the miserable beasts forward,
        one ENTER stroke at a time.
                                        -djh
        */

        roll = rand() % 2; //horse flips for a 0 or a 1
        setPosition(roll); //sends value of roll to be added to position

        };//end advance()
// end Horse Class
