/*  parsingFileIOProject.cpp
    Andrew Bowerman
    7/19/2017

    -reads .txt of a predetermined format
    eg.     int,int,int
            string
            (repeated)
    -prepares output.txt file
    -parses incoming data into reformatted output
*/

#include <iostream>
#include <fstream>  // ifstream & ofstream
#include <stdlib.h> // atoi

using namespace std;

int main(){
//initialization
ifstream inFile; // input file
ofstream outFile; // output file
int i, total, number; //sentry, total of incoming ints, int converted from cache
string word, cache; //file input cache

//open input and output files
inFile.open("input.txt", ios::in);
outFile.open("output.txt", ios:: out);

while (!inFile.eof()){

    total = 0; //reset total

    //read and parse input file
    //interpret number line
    std::getline(inFile, cache, ','); //1st num
    number = atoi(cache.c_str());// convert cache string to char, and then again to int
    total += number; //add to total

    std::getline(inFile, cache, ','); //2nd num
    number = atoi(cache.c_str());// convert cache string to char, and then again to int
    total += number;

    std::getline(inFile, cache); //3rd num
    number = atoi(cache.c_str());
    total += number;

    std::getline(inFile, word); //interpret string line

    //write to output file
    //for loop writes 'word' 'total' number of times in line seperated by commas to outFile
    for (i = 0; i <= (total-1); i++){
        outFile << word ;

        if (i < (total-1)){ //if this isn't the last entry, place a comma
            outFile << ",";
        }
    }//end for

    outFile << endl;

}//end while

inFile.close(); //close files
outFile.close();

    return 0;
}//end main()
