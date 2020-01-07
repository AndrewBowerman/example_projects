// sherlockBlackBelt.cpp
// Andrew Bowerman
// 7/6/2017
/*
    blackbelt incorporates more features into sherlock.cpp
        menu w/ score displayed
            1. 'Play Game'. A random number is generated and the user and
                            Sherlock take turns guessing. Correct guess gets a point.
            2. 'Observe Method'. Sherlock uses binary sort to guess user's number from 1-100
            3. 'Practice Method'. Sherlock thinks of a random number and the user guesses it.
            4. 'Quit'

    Incorporates variations of algorithms I worked on for a similar Python assignment in 230.

    I started to implement character frames for dialogue but I ran out of time to get them fully finished. You can see the beginnings of this concept in the 'play game' mode.

    characters created by Arther Conan Doyle
    Mycroft and emptyTV ASCII art modified from 'man on TV' by jgs, retrieved from http://www.oocities.org/spunk1111/men.htm#faces
    Watson art modified from 'man with hanger' by jgs, retrieved from http://www.oocities.org/spunk1111/men.htm#faces
    Shelrock art retrieved from http://ascii.co.uk/art/sherlockholmes
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

int playerScore, computerScore;
void initializeScores(); // initializes scores on run
void clearScreen(); // this was my solution for cleanliness in command line programs in python (without having to prototype back then)
void mycroftFrame(string, string, string, int, int); // prints manOnTV art. parameters are lines of dialogue at the locations passed
void watsonFrame(string, string, string); // etc.
void sherlockFrame(string, string, string); //etc.
void displayMenu(); //prints menu
void playGame(); // runs man v computer mode
int observeMethod(); // runs computer guessing mode
void practiceMethod(); // runs player guessing mode

void initializeScores(){
    playerScore = 0;
    computerScore = 0;
}

void clearScreen(){ //shoves all the old stuff off screen to tidy everything up
    int numLines, i;
    numLines = 50;
    for (i=0; i < numLines; i++){
        cout << endl;
    }
} // end clearScreen()

void displayMenu(){ //prints menu

    cout << "--------------------------------------------------------------------------------" << endl <<
            "|                               ~ ~ SHERLOCK'S~  ~                             |" << endl <<
            "|                                ~  ~ALGORITHM~ ~                              |" << endl <<
            "|                                                                              |" << endl <<
            "|________                                                            __________|" << endl <<
            "| WATSON |                                                          | SHERLOCK |" << endl <<
            "|_______-                                                            -_________|" << endl <<
            "  " << playerScore << " |                                                                     | "<< computerScore <<"   " << endl <<
            "|------------------------------------------------------------------------------|" << endl <<
            "|  1: PLAY GAME                          |   2: OBSERVE METHOD                 |" << endl <<
            "|  3: PRACTICE METHOD                    |   4: QUIT                           |" << endl <<
            "|------------------------------------------------------------------------------|" << endl <<
            " ENTER A SELECTION: ";



} //end displayMenu

void playGame(){ // take turns guessing against computer
    clearScreen();
    bool keepGoing; //sentry
    keepGoing = true;
    int turn, rando, counter, low, high, guess; //turn state, random number, turn counter, low & high bounds, guess variable
    string line1, line2, line3; //lines for character frames
    turn = rand() % 2; //coin toss for who guesses first
    rando = rand() % 100;
    low = 0;
    high = 100;

    //intro dialogue
    // holmes calls mycroft
    line1 = "Holmes calling Mycroft.";
    line2 = " ";
    line3 = "Mycroft, come in.";
    sherlockFrame(line1, line2, line3);
    system("pause");
    clearScreen();
    //mycroft responds
    line1 = "Mycroft here.";
    line2 = "Ah.";
    line3 = "This again.";
    mycroftFrame(line1, line2, line3, low, high);
    system("pause");
    clearScreen();
    line1 = "Mycroft, think of a number between 1 and 100";
    line2 = "if you would. Watson and I are";
    line3 = "going to guess at it.";
    sherlockFrame(line1, line2, line3);
    system("pause");
    clearScreen();
    line1 = "Yes, I already have it.";
    line2 = "I've flipped a coin and";
    if (turn == 1){
        line3 = "Watson will guess first.";
        }
    else {
        line3 = "Sherlock will guess first." ;
        }
    mycroftFrame(line1, line2, line3, low, high);
    system("pause");
    clearScreen();

    /*  each turn is an iteration of the other programs, where
        either the user or computer are guessing a random number */
    while (keepGoing){
        // collect one user guess per loop
        // basically copy+paste from my practiceMethod()
        if (turn == 1){
            clearScreen();
            cout << "LOW: " << low << " HI: " << high << endl <<
                    "(type a number and press ENTER): ";
            cin >> guess;
            counter++; //increment number of guesses. user can guess as many as they need
            clearScreen();

            //if chain determines response.
            if (guess < rando){
                low = guess;
                cout << guess << "? That's too low!" << endl;
                system("pause");
                turn++;
                }
            else if (guess > rando){
                high = guess;
                cout << guess << "? That's too high!" << endl;
                system("pause");
                turn++;
                }
            else if (guess == rando){
                cout << guess << "? Brilliant! You've guessed it!" << endl ;
                system("pause");
                keepGoing = false;
                playerScore++;
                clearScreen();
                }
            // Entering anything not 1, 2, or 3 results in counter reset and asking again
            // characters still completely break it
            else {
                counter--;
            }
        }//end of player turn code

        else { //if turn isn't 1, it's the computer's turn

            counter++; // increment number of guesses
            guess = (high + low) / 2;
            clearScreen();
            cout << "The logical choice is " << guess << "." << endl;
            system("pause");
            clearScreen();

            // Guessing too low sets lower bound at (guess + 1)
            if (guess < rando){
                low = guess + 1;
                cout << guess << "? That's too low!" << endl;
                system("pause");
                turn = 1;
            }

            // Guess too high sets upper bound to the guess
            else if (guess > rando){
                high = guess;
                cout << guess << "? That's too high!" << endl;
                system("pause");
                turn = 1;
            }

            // Correct guess ends loop
            else if (guess == rando){
                cout << guess << "? Brilliant! You've guessed it!" << endl <<
                system("pause");
                keepGoing = false;
                computerScore++;
                clearScreen();
            }
        } //end of computer turn code

    } //end game while loop

}// end playGame

int observeMethod(){ //observe method function
    // initialize loop variables
    bool keepGoing; //while loop sentry
    keepGoing = true;
    int low, high, counter, guess, response; //low guess bound, high guess bound, turn counter, computer guess variable, menu response
    low = 0;
    high = 100;
    counter = 0;

    //initialize user guess
    clearScreen();
    cout << "Think of a random number, between 1 and 100." << endl<<
    "I'll determine it in seven guesses or less!" << endl;
    system("pause");

    // main loop
    while (keepGoing){
        counter++; // increment number of guesses
        guess = (high + low) / 2 ; // first step of binary search algorithm determines guess

        // check guess against user number
        clearScreen();
        cout << "Is your number " << guess << "?" << endl << endl <<
                "1: That's too LOW" << endl <<
                "2: That's too HIGH" << endl <<
                "3: Yes" << endl << endl <<
                "CHOOSE A RESPONSE: ";
        cin >> response;

        // Guessing too low sets lower bound at (guess + 1) and guesses again
        if (response == 1){
            low = guess + 1;
        }

        // Guess too high sets upper bound to the guess and guesses again
        else if (response == 2){
            high = guess;
        }

        // Correct guess ends loop
        else if (response == 3){
            keepGoing = false;
        }

        // Entering anything not 1, 2, or 3 results in counter reset and asking again
        // characters still completely break it
        else {
            counter--;
        } // end of menu chain

    } //end while loop

    // correct guess prints victory statement and ends program
    clearScreen();
    cout << "AHA! A simple algorithm to be sure." << endl <<
            "It only took " << counter << " guesses to determine your number!" << endl;
    system("pause");
return 0;
} // end observeMethod()

void practiceMethod(){ // generates a random number for user to guess
    int rando, low, high, counter, guess; //random, low guess bound, high guess bound, turn counter, user guess variable
    rando = rand()%100;//establish random number
    bool keepGuessing; //while loop sentry
    keepGuessing = true;
    low = 0;
    high = 100;
    counter = 0;
    clearScreen();
    cout << "I have a random number from 1-100" << endl <<
            "in my head. Guess it" << endl <<
            "within  7 tries." << endl ;
            system("pause");

    //begin guessing loop
    while (keepGuessing){
        clearScreen();
        cout << "LOW: " << low << " HI: " << high << endl <<
                "You have guessed " << counter << " times." << endl <<
                "(type a number and press ENTER): ";
        cin >> guess;
        counter++; //increment number of guesses. user can guess as many as they need
        clearScreen();

        //if chain determines response.
        if (guess < rando){
            low = guess;
            cout << guess << "? That's too low!" << endl;
            system("pause");
            }
        else if (guess > rando){
            high = guess;
            cout << guess << "? That's too high!" << endl;
            system("pause");
            }
        else if (guess == rando){
            cout << guess << "? Brilliant! You've guessed it!" << endl <<
            system("pause");
            keepGuessing = false;
            clearScreen();
            }
        // Entering anything not 1, 2, or 3 results in counter reset and asking again
        // characters still completely break it
        else {
            counter--;
        }
    } // end while

    // victory or failure state check
    // if user guessed <= 7 times, victory prompt
    cout << counter << " tries?" << endl;
    if (counter <= 7){
        cout << "Congratulations are in order!" << endl <<
                "It seems you've cracked the algorithm!" << endl ;
                system("pause");
        }
    else { // failure prompt
        cout << "Pretty close, friend!" << endl <<
                "Perhaps you should watch Sherlock run the algorithm again?" << endl ;
                system("pause");
        }


}// end practice method

void mycroftFrame(string line1, string line2, string line3, int high, int low){ // prints Mycroft frame with dialogue passed in
    //80<>x24^\/
    cout <<
"                       ___________________________" << endl <<
"                      / _________________________ \\" << endl <<
"                      |/----,                    \\|" << endl <<
"                      ||MCTV|                   -----------------\\" << endl <<
"                      ||----'     .-""-.         | " << line1<< endl <<
"                      ||         / \\    \\      | " << line2 << endl <<
"                      ||         | /`-._|      | " << line3 << endl <<
"                      ||         |/ . . |     //_________________/" << endl <<
"                      ||         (   _\\ )    /   ||" << endl <<
"                      ||         |\\  = |         ||" << endl <<
"                      ||        /\\ \\_._/         ||" << endl <<
"                      ||       /\\_\\___//\\        ||" << endl <<
"                      ||     /`  \\  \\|   `\\      ||" << endl <<
"                      |\\____/_____|__;_____|_____/|" << endl <<
"                      \\___________________________/" << endl <<
"                          |::::LOW:::::::HIGH::|" << endl <<
"                          |::| " << low << "|:::::| " << high << " |::|" << endl <<
"                        __|:::---:::::::----:::|__" << endl <<
"                       /            (0)           \\" << endl <<
"_______________________________________________________________________________" << endl ;
   // tv is 20x29*/

} //end mycroftFrame


void watsonFrame(string line1, string line2, string line3){ // prints player frame with dialogue passed in
    cout <<
"                       ___________________________" << endl <<
"                      /" << endl <<
"                      | " << line1 << endl <<
"                      | " << line2 << endl <<
"         .-" << "-.       | " << line3 << endl <<
"        / _/'-\\     //---------------------------" << endl <<
"        (c   '\\'   /" << endl <<
"         \\    =" << endl <<
"         _) --'" << endl <<
"      .-' <\\\\_/>-." << endl <<
"     /      :  , \\\\" << endl <<
"    / /|    :  |\\\\ \\\\__.._" << endl <<
"   / / |    :  | \\\\_/_/\\\\\\\\\\\\" << endl <<
"   \\_\\\\ \\\\    :  /      |`" << endl <<
"    \\_\\\\ |I=I==I    .--'--." << endl <<
"     /|\\\\|     |   /_______\\\\" << endl <<
"_______________________________________________________________________________" << endl ;
} //end watsonFrame

void sherlockFrame(string line1, string line2, string line3){ // prints sherlock frame with dialogue passed in

    cout <<
"  " << endl <<
"   " << endl <<
"    " << endl <<
"    " << endl <<
"                              --------------------" << endl <<
"                             / " << line1<< endl <<
"                            | " << line2 << endl <<
"                            | " << line3 << endl <<
"                             \\____________________          ,N." << endl <<
"                                                   \\\\     _/__ \\" << endl <<
"                                                     \\     -/o\\_\\" << endl <<
"                                                         __\\_-./" << endl <<
"                                                        / / V \\`U-." << endl <<
"                                            ())        /, > o <    \\" << endl <<
"                                            <\\.,.-._.-- [-\\ o /__..-' " << endl <<
"                                            |/_  ) ) _.--| \\o/  |  \\ o!0" << endl <<
"                                               `'-'-" << endl <<
"   " << endl <<
"____________________________________________________________________________" << endl ;

           /*       ,N.           original
                  _/__ \
                   -/o\_\
                 __\_-./
                / / V \`U-.
    ())        /, > o <    \
    <\.,.-._.-" [-\ o /__..-'
    |/_  ) ) _.-"| \o/  |  \ o!0
       `'-'-"
           */ // 9 tall
} //end sherlockFrame

int main(){
    if ((playerScore + computerScore) < 1){
        initializeScores();
        }
    srand(time(NULL));
    bool keepGoing;
    keepGoing = true;
    int selection;
    selection = 0;

    while (keepGoing){
        clearScreen();
        displayMenu();

        cin >> selection;
        //if chain for menu
        if (selection == 1){
            playGame();
            }
        else if (selection == 2){
            observeMethod();
            }
        else if (selection == 3){
            practiceMethod();
            }
        else if (selection == 4){
            keepGoing = false;
            }
        else{
            displayMenu();
            }
    } // end while

    // play exit message


}//end main
