/*
FILE: heap.cpp
AUTHOR: Andrew Bowerman
DATE: 19 Oct 2018
PURPOSE: a program where: 
		the input is a set of integers (any set of any size, which should be user defined), 
		and the output is a heap in array format.
NOTES: 
MODIFICATION HISTORY: 
*/

#include<stdio.h>
#include <iostream> 
#include <algorithm>
#include <vector>
using namespace std;


/** Functions**/
void heaper(int num){
	int myints[num-1];
	int i=0;
	for (i; i<num; i++){
		cout <<"Enter a number for the heap ("<< num-i <<") indexes remaining: " <<endl;
		cin >>myints[i];
	}
	vector<int> v1(myints,myints+(num));
	make_heap(v1.begin(), v1.end());
	
	cout << "The heap is: " << endl << "[";
	for (i=0; i<num ; i++){
		cout << " " << v1[i] ;
		if (i < (num-1)){cout << ",";}
	}
	cout << "]" << endl;
}

	
int main() {
	bool keepGoing = true;
	int choice, item;
	
	while (keepGoing)
    {	
		cout<<"~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
        cout<<"~~   Heaper           ~~"<<endl;
        cout<<"~~   1. Make a heap   ~~"<<endl;
        cout<<"~~   2. Exit          ~~"<<endl;
        cout<<"Enter your Choice: ";
        cin>>choice;
        if (choice == 1){
            cout<<"How many number will go into array: ";
            cin>>item;
			heaper(item);
		}
		else if (choice == 2){
            keepGoing=false; 
		}
        else{
			cout<<"Invalid selection"<<endl;
		}
        
    }
return 0;
}
