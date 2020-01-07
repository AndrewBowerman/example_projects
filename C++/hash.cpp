/***
FILE: hash.cpp
AUTHOR: Andrew Bowerman
DATE: 15 Nov 2018
PURPOSE: Hash a text file of words by their first and second letter into a dictionary.
		 Dictionary is my own ADT which is a 2d vector with linked lists
		 User can input a word & program will check for it within dictionary
NOTES: for my linked list I got help from a couple places:
		a linked list tutorial from https://www.codementor.io/codementorteam/a-comprehensive-guide-to-implementation-of-singly-linked-list-using-c_plus_plus-ondlm5azr
		a linked list implementation used by stackoverflow user charlierm helped me fix my linkedList.print() https://gist.github.com/charlierm/5691020
 ***/
#include<iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <typeinfo>
#include "TimeInterval.h"
using namespace std;
 

 
/***CLASSES ***/

/***
	okay everything is public so it should probably be a struct
	CLASS: node
	USE: Data and pointer structure for singly linked list
		 no methods
 ***/
class node {
public:
    node* next;
    string data;
};
/*** end node ***/

/***
	CLASS: linkedList
	USE: structure to hold nodes
	METHODS: push(string) accepts a string and sets it as the new head of the linkedList
			 print() prints the link list
 ***/
class linkedList {
	public:
    node* head;

    linkedList();
    ~linkedList();
    void push(string data);
    void print();
};

linkedList::linkedList(){
    this->head = NULL;
}

linkedList::~linkedList(){
    node* next = head;
    node* cur = NULL;
    while (next != NULL) {
        cur = next;
        next = next->next;
		//delete all the way through
        delete cur;
    }
}

void linkedList::push(string data){
    node* temp = new node();
	//set key
    temp->data = data;
	//make the old head the new 2nd node
    temp->next = this->head;
	//and set the new node as the new head
    this->head = temp;
}

void linkedList::print(){
    node* head = this->head;
    int i = 1;
	//iterate while  there are still nodes in list
    while(head){
        cout << i << ". " << head->data << endl;
        head = head-> next;
        i++;
    }
}

/*** end linkedList ***/
/*** END CLASSES ***/

/*** FUNCTIONS ***/
/***
	FUNCTION: hash(vector<vector<linkedList &a, string)
	USE: hashes a string into a 2d vector with linkedLists
	RETURN: N/A
 ***/
 void hash(vector<vector<linkedList> > &dictionary, string item){
	/*
		to place a word in the dictionary, the hash looks at the string sent in
		int(item[0]) is the ascii value of the first character of the word
		int(item[1]) is the second character.
		since the ascii of the character 'a' = 97, we'll take each of those values and 
		mod them by 97, giving us the index of the linkedList they'll hash to
	*/
	int x, y;
	x = int(item[0])%97;
	if (item[1]){
		y = int(item[1])%97;
	}else y=0;
	try {
		dictionary[x][y].push(item);
		//cout<< "coordinates of " << item << " are at " << x << ", " << y << " in the dictionary";
		//dictionary[x][y].print();
	} 
	catch (const std::exception& e) {}
	return;
}//end hash()
/***
	FUNCTION: search(vector<vector<linkedList>> &a, string)
	USE: search a linkedList within a 2d vector using the hash function
			if found print TRUE 
			else print FALSE
			in both cases, print the rest of items in its linkedList
	RETURN: N/A
 ***/
 void search(vector<vector<linkedList> > &dictionary, string item){
	/*
		using same logic as hash, find appropriate linked list of suggested words.
		if the word they entered is in the dictionary, print "true", else print "false"
		print list of suggested words
	*/
	int x, y;
	x = int(item[0])%97;if (item[1]){
		y = int(item[1])%97;
	}else y=0;
	
	//step through linkedList
	node* head = dictionary[x][y].head;
	bool found = false;//search flag
	
	//step through linkedList and check parameter item against the value in the current node
    while(head){
		/***
		right now I can't get these 2 things to match in the if statement (line 153) 
		if I uncomment these print statements, their ourput and types LOOK identical
		but there's something gumming it up :(   ***/
		//cout << item << " looks just like " << head->data << endl;
		//cout << typeid(item).name() << " type looks just like " << typeid(head->data).name() << endl;
		//string maybe = head->data;//tried putting it into a string but it didn't work either
        if (item == head->data){
			found = true; //never occurs with my current logic
		}			
        head = head->next;//iterate to next node
    }
	if (found == true){
		cout << "True" << endl;
	}else cout << "False" << endl;//right now this always comes out false
	
	cout << "Suggested words:"<< endl;
	dictionary[x][y].print();
	return;
}//end search()

/*** END FUNCTIONS ***/

 
/*** MAIN ***/
int main(){
	int choice; 
	string item;
    linkedList list;
	TimeInterval x;
	//2d vector with linkedList to parse words
	vector<vector<linkedList> > dictionary;

	//this line makes the first vector 26 deep with another vector in its indexes
	// and then makes each of those vectors 26 wide with linkedLists in its indexes
	dictionary.assign(26, vector<linkedList>(26, list));
	
	/*** 	
	GREAT SUCCESS- getting that right might be my crowning CS accomplishment so far haha
	dictionary works as intended- uncomment this to verify
	TimeInterval x; 
	x.start();
	dictionary[0][0].push("aardvark");	
	dictionary[0][0].push("aavalanche");	
	dictionary[0][0].print();
	x.stop();
	cout<< x.GetInterval() << "micro-sec" << endl;
	****/
	
	//read Dictionary.txt and hash into dictionary
	//must be in directory
	cout<<"Opening 'Dictionary.txt'"<<endl;
	ifstream file ("Dictionary.txt");
	if (file.is_open()){
		
		cout<<"Hashing into dictionary..."<<endl;
		while (getline (file, item)){
			//make sure everything is properly lowercase
			transform(item.begin(), item.end(), item.begin(), ::tolower);
			hash(dictionary, item);
		}
		file.close();
		cout<<"Hashing Complete; 'Dictionary.txt' closed."<<endl;
	}
	//menu loop
	bool keepGoing = true;
    while (keepGoing)
    {
        cout<<"Spell Check"<<endl;
        cout<<"1. Check a word"<<endl;
        cout<<"2. Add a word to the Dictionary"<<endl;
        cout<<"3. Exit"<<endl;
        cout<<"Enter your Choice: ";
        cin>>choice;
        if (choice == 1){
            cout<<"Enter the word to check: ";
            cin>>item;
			//CONVERT TO LOWERCASE 
			transform(item.begin(), item.end(), item.begin(), ::tolower);
			
			//run a timer, per rubric
			x.start();
            search(dictionary, item);
			x.stop();
			cout<< "This check took " << x.GetInterval() << " micro-seconds." << endl;
			
		}
        else if (choice == 2){
			cout<<"Enter word to be inserted: ";
            cin>>item;
			transform(item.begin(), item.end(), item.begin(), ::tolower);
			x.start();
            hash(dictionary, item);			
			x.stop();
			cout<< "This insertion took " << x.GetInterval() << " micro-seconds." << endl;
        }
		else if (choice == 3){
            keepGoing=false; 
		}
        else{
			cout<<"Invalid selection"<<endl;
		}
        
    }
    return 0;
}