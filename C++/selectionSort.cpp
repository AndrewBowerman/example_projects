/* 
selectionSort.cpp
Andrew Bowerman
4 Sept 2018

    user picks a number (n)
    array of n numbers are generated
	array of n numbers are sorted with selection sort
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

// clearScreen() shoves all the old stuff off screen to tidy everything up
void clearScreen(){ 
    int numLines, i;
    numLines = 50;
    for (i=0; i < numLines; i++){
        cout << endl;
    }
} // end clearScreen()

// printArray(int array, int) iterates through and prints an array
void printArray(int printMe[], int n){
	int i; //sentry
	for (i=0; i < n; i++) {
		//print each element
		cout << printMe[i];
		// put commas between elements
		if (i < (n-1))
			cout << ", ";
    }
}//end printArray




// selectionSort performs an in-place sort of an array using swap() to swap values
void selectionSort(int sortMe[], int n)
{
	int i, j, minimum, temp; //sentry, sentry, min val, holder variable
	// One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++)
    {
        // Find the minimum element in unsorted array
        minimum = i;
        for (j = i+1; j < n; j++)
          if (sortMe[j] < sortMe[minimum])
            minimum = j;
 
        // Swap the found minimum element with the first element
		temp = sortMe[minimum];
		sortMe[minimum] = sortMe[i];
		sortMe[i] =temp;
	}
}

int main(){
	
	//initialize variables
	int i, n, x; // sentry, array size, max array size
	x=10; //set max array size
	
	//initialize array for sorting
	//collect array size
	clearScreen();
	cout << "It's time to sort an array." << endl <<
			"You decide how big it will be," << endl <<
			"then I'll make that many random numbers & sort them." << endl <<
			"How many numbers would you like to sort?" << endl <<
			"ENTER AN INTEGER (1-10): ";
	cin >> n;
	while ((n<1) || (n>10)){
		cout << endl<< "ENTER AN INTEGER (1-10): ";
		cin >> n;
	} 
	
	//generate random seed
	srand(time(NULL));
	
	//create array of n integers
	int sortMe[n];
	
	//populate with random values
	for (i=0; i < n; i++) {
        sortMe[i] = rand() % 501; //put a random value from 0-500 inside the array
    }
	
	//display unsorted array
	clearScreen();
	cout << "Here's your array:" << endl ;
	printArray(sortMe, n);
	cout << endl << 
	"Let's sort it using a SELECTION SORT" << endl <<
	"Press ENTER to continue: " << endl;
	cin.ignore(); cin.ignore(); // wait for user
	
	//sort array
	selectionSort(sortMe, n);
	
	//display sorted array
	cout << "All sorted:" << endl;
	printArray(sortMe, n);
	cout << endl;
} // end main()




