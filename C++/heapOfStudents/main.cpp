/*  heapofStudents
    Andrew Bowerman
    7/19/2017

    main.cpp
    include header files.
    instantiate array of student class on heap.
    read student.dat, a csv file and
    parse the data in a variety of ways.
    delete array on heap.
*/
#include <iostream>
#include <iomanip>
#include <fstream>  //ifstream
#include <stdlib.h> //atoi

// header files for classes
#include "address.h"
#include "date.h"
#include "student.h"

//function prototypes
//
void printMenu();         //menu for user to select report
void clearScreen();       //moves everything on screen 50 lines up
void selectionSort(Student[], Student[], int);     //accepts 2 arrays of Students and sorts one alphabetically into the other
void printAll(Student[], int);
void printNames(Student[], int);
void printBirthdays(Student[], int);

//functions
//
void clearScreen(){ //shoves all the old stuff off screen to tidy everything up
    int i;
    for (i=0; i < 50; i++){
        cout << endl;
}} // end clearScreen()

void printMenu(){ //prints menu
    cout << "--------------------------------------------------------------------------------" << endl <<
            "|                                    A Heap of                                 |" << endl <<
            "|                                 Student Records                              |" << endl <<
            "|                                                                              |" << endl <<
            "|                                                                              |" << endl <<
            "|                                                                              |" << endl <<
            "|                                                                              |" << endl <<
            "                                                                               |" << endl <<
            "|------------------------------------------------------------------------------|" << endl <<
            "|  1: View Full Student Report          |   2: View Student Names              |" << endl <<
            "|  3: View Student Birthdays            |   4: QUIT                            |" << endl <<
            "|------------------------------------------------------------------------------|" << endl <<
            " ENTER A SELECTION: ";
} //end displayMenu

void selectionSort(Student unsortedArray[], Student sortedArray[], int arraySize){//accepts 2 arrays of Students and sorts one alphabetically into the other

    //selection sort finds earliest last names and writes students into sortedArray
    string temp;// holds last name
    int index, i, j;// holds position of earliest alph. name and uses that index to overwrite Student data in sortedArray
    index = 1;

    for (j=1; j<arraySize; j++){// outer for loop steps through indices of sortedArray, overwriting each index as the inner loop produces the appropriate student from unsortedArray

        for (i= 1; i<arraySize; i++){ //step through next names of unsorted array

            temp = unsortedArray[i].getLastName();//initialize with current entry of unsorted array
            cout << unsortedArray[i].getLastName() << endl;

            //read last name of unsortedArray index, compare against string that holds the current earliest name
            //if the scanned last name is earlier in the alphabet than the string, overwrite string w/ last name and overwrite index variable
            if (temp < (unsortedArray[i].getLastName())){
                temp = unsortedArray[i].getLastName();
                index = i;
            }
        } //end inner unsorted for
        //index int will have address of student to overwrite from unsorted to sorted array
        sortedArray[index].setLastName(sortedArray[index].getLastName());
        cout << sortedArray[index].getLastName() << endl;


    } //end sorted for. should be sorted now



/* // old version, almost as equally broken

    int i, j, overrider;

    for (i=1; i <(arraySize-1); i++){ //starting at index 1 of unsorted array

        overrider = 1; //overrider holds index of element of earliest alphabet character
        for (j=2; j<=arraySize; j++){ // start at second record and scan array
            // if last name atsecond location
            if (unsortedArray[j].getLastName() > unsortedArray[overrider].getLastName())
            {

                overrider = j;
            }
        }
        sortedArray[i].setLastName(unsortedArray[overrider].getLastName());

        cout << sortedArray[i].getLastName() << endl;
    }
    cin.ignore();*/
}//end sort()


void printAll(Student array[], int arraySize){
    int i;
    cout << "Full Student Report" <<endl;
    for (i=1; i< (arraySize); i++)
    {
        cout << left <<  "____________________________________________________" << endl <<
                "Last:      " << setw(12)<< array[i].getLastName() <<  "Address: " << array[i].address.getAddress1()<< endl <<
                "First:     " << setw(12)<< array[i].getFirstName()<< "Addr. 2: " << array[i].address.getAddress2() << endl <<
                "DOB:       " << setw(12)<< array[i].dob.getDate() << "City:    " << array[i].address.getCity() << endl <<
                "GradDate:  " << setw(12)<< array[i].gradDate.getDate()<< "ST:      " << array[i].address.getState() << endl <<
                "GPA :      " << setw(12)<< array[i].getGpa()<< "Zip:     " << array[i].address.getZip() << endl <<
                "Credit Hours: " << array[i].getCredHrs()<< endl;
    }
    cout << "Press ENTER to Continue:";
    cin.ignore();
}
void printNames(Student array[], int arraySize){
    clearScreen();
    int i;
    cout << "                Student Names" <<endl <<
            "____________________________________________________" << endl <<
            "Last:           First:" << endl <<
            "____________________________________________________" << endl ;
    for (i=1; i < (arraySize); i++)
    {
        cout << array[i].getLastName()<< setw(20) << left << array[i].getFirstName() << setw(20) << left <<endl ;
    }
    cout << "Press ENTER to Continue:";
    cin.ignore();
}
void printBirthdays(Student array[], int arraySize){
    clearScreen();
    int i;
    cout << "                      Student Birthdays" <<endl <<
            "____________________________________________________" << endl <<
            "Last:           First:            Birthday:" << endl <<
            "____________________________________________________" << endl ;
    for (i=1; i < (arraySize); i++)
    {
        cout << left<< setw(20) << array[i].getLastName()<< setw(20) << array[i].getFirstName() << array[i].dob.getDate()<<endl ;
    }
    cout << "Press ENTER to Continue:";
    cin.ignore();
}

int main()
{
    int arraySize, i, selection, number; //size=number of data, sentry, menu selection, number cache
    arraySize = 51; //size of data lines
    bool keepGoing; //menu bool
    keepGoing = true;
    Student *unsortedArray = new Student[arraySize]; //create array of Students on heap
    Student *sortedArray = new Student[arraySize]; //create blank array for alphabetized data

    //read data file
    ifstream inFile; //holds student.dat
    string cache;    //holds non-numerical items from inFile
    inFile.open("student.dat", ios::in);

    //populate unsorted array with values from file
    //i = 0; //prepares to skip importing header -while loop version
    for (i=0; i < arraySize; i++){
        if (i == 0){//skip header
            getline(inFile, cache);
        }
        else{
        //read record and assign to current index of array
        //get lastName
        getline(inFile, cache, ','); //read until comma
        unsortedArray[i].setLastName(cache); //overwrite current object's property with imported data
        //get first name
        getline(inFile, cache, ',');
        unsortedArray[i].setFirstName(cache);
        //address 1
        getline(inFile, cache, ',');
        unsortedArray[i].address.setAddress1(cache);
        //address 2
        getline(inFile, cache, ',');
        unsortedArray[i].address.setAddress2(cache);
        //city
        getline(inFile, cache, ',');
        unsortedArray[i].address.setCity(cache);
        //state
        getline(inFile, cache, ',');
        unsortedArray[i].address.setState(cache);
        //zip
        getline(inFile, cache, ',');
        unsortedArray[i].address.setZip(cache);
        //dob.day
        getline(inFile, cache, '/');
        unsortedArray[i].dob.setDay(cache);
        //dob.month
        getline(inFile, cache, '/');
        unsortedArray[i].dob.setMonth(cache);
        //dob.year
        getline(inFile, cache, ',');
        unsortedArray[i].dob.setYear(cache);
        //gradDate.day
        getline(inFile, cache, '/');
        unsortedArray[i].gradDate.setDay(cache);
        //gradDate.month
        getline(inFile, cache, '/');
        unsortedArray[i].gradDate.setMonth(cache);
        //gradDate.year
        getline(inFile, cache, ',');
        unsortedArray[i].gradDate.setYear(cache);
        //gpa
        getline(inFile, cache, ',');
        number = atoi(cache.c_str());// convert cache string to char, and then again to int
        unsortedArray[i].setGpa(number);
        //credit hours
        getline(inFile, cache); //reads until end of line
        number = atoi(cache.c_str());
        unsortedArray[i].setCredHrs(number);
        //move to next record and increment index
        }
    }//end 'populate' for
    inFile.close(); //close student.dat


    //sort student array alphabetically by last name
    selectionSort(unsortedArray, sortedArray, arraySize);

    //run menu loop
    while (keepGoing){
        clearScreen();
        printMenu();

        cin >> selection;
        cin.ignore();
        //if chain for menu
        if (selection == 1){
            printAll(unsortedArray, arraySize);
            }
        else if (selection == 2){
            printNames(unsortedArray, arraySize);
            }
        else if (selection == 3){
            printBirthdays(unsortedArray, arraySize);
            }
        else if (selection == 4){
            keepGoing = false;
            }
        else{
            clearScreen();
            printMenu();
            }
    } // end while

    delete[] unsortedArray; //my god what has science done
    delete[] sortedArray;   //think of the damn children
    return 0;
}
