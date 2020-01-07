/*
FILE: bst.cpp
AUTHOR: Andrew Bowerman
DATE: 2 Oct 2018
PURPOSE: build a Binary Search Tree from provided integer array
		 Find the Kth Smallest Element in tree using InOrder traversal
		 Input: -- the given set of integers -- user-defined k
		 Output: -- print the BST -- return the k-th smallest element
NOTES: this implementation incorporates some algorithms that have
		been modified to work in this C++ adaption:
		most important were the lecture slides detailing BST algs
		and the detailed breakdown of BST methods in our 
		Introduction to Algorithms textbook. Also incorporates
		some lessons gleaned from harish-r on Gist seen here:
		https://gist.github.com/harish-r/a7df7ce576dda35c9660
		and from msram on cplusplus.com seen here:
		http://www.cplusplus.com/forum/general/1551/
		but only the BST concepts appear here- not their specific code.
		

MODIFICATION HISTORY: 
*/

#include<stdio.h>
#include <iostream> 
#include <stack> 
using namespace std;


//OBJECTS

// Binary Search Tree
class bst{
	private:
	//define nodes for tree
	struct node{
		// each node has a key and points to 2 other child nodes
		int key;
		node* left;
		node* right;
		bool visited;
	};//end node
	
	//create root of tree
	node* root;	
	
	public:
	//METHODS
	//only need a few standard BST methods for this project
	//const
	bst(){root = NULL;}
	//bool isEmpty() tells insert() whether or not to start a new tree
	bool isEmpty() const{ return root == NULL;}
	void insert(int);
	void inorderPrint();
	void inorder(node*);
	void kthSmallest(node*, int);
	void kthSmallestPrint(int);
	void depthFirst(node*);
	void depthFirstPrint();
	
};

// Binary Search Tree Methods
//insert(int data, node* t)
	/*  places new node in tree at suitable null location (leaf).
		WHILE finding a place to land, compare incoming key
		against CURRENT (parent) keys and assign the new node at 
		proper leaf location
	*/
void bst::insert(int x){
	//initialize new node with incoming INT as key
	node* n = new node;
	n->visited=false;
	node* parent;
	n->key = x;
	n->left = NULL;
	n->right = NULL;
	parent = NULL;
	
	//set root of tree to incoming node if nothing exists in tree
	if (isEmpty()){
		root = n;}	
	else {
		//make reference to CURRENT node in tree
		node* current;
		//start at root
		current = root;
		//while we have a CURRENT, we can traverse tree
		while(current){
			parent = current;
			//reassign new parent node and traverse two next level
			if (n->key < current->key){
				current = current->left;}
			else{
				current = current->right;
			}
		}//end traverse While
		
		//once out of loop we have found a place to assign the node
		if (n->key < parent->key){
			parent->left = n;
		}
		else{//n key is >= parent key
			parent->right = n;
		}
	}
}
void bst::inorder(node* n){
	if (n != NULL){
			//as long as we can move down left tree, do so
			if (n->left){
				inorder(n->left); //yay recursion
				}
			//getting here means you've reached the min value
			cout << " " << n->key << " ";
			if (n->right){
				inorder(n->right);
			}
		
	}
}
void bst::kthSmallest(node* n, int k){
	if (n != NULL){
		while (k>0){
			//as long as we can move down left tree, do so
			if (n->left){
				kthSmallest(n->left, k); //yay recursion
				}
			//the following line attempted to solve the repeated walkup what each print does
			//if (n->visited == false){
			cout << " " << n->key << " ";
			k--;
			n->visited = true;
			//}
			if (n->right){
				kthSmallest(n->right, k);
			}
		}
	}
}
void bst::depthFirstPrint()
{
    depthFirst(root);
}

void bst::depthFirst(node* n)
{
    if(n != NULL)
    {
        cout <<" " << n->key<< " ";
        if(n->left) depthFirst(n->left);
        if(n->right)depthFirst(n->right);
    }
    else return;
}
void bst::inorderPrint(){
	//print tree using inorder traversal
	inorder(root);	
}
void bst::kthSmallestPrint(int k){
	//print tree using inorder traversal
	kthSmallest(root, k);	
}
	
int main() {
	//initiate assignment array literal
	int providedArray[15] = {6, 17, 20, 41, 45, 52, 57, 65, 71, 76, 79, 87, 92, 95, 99};
	int providedArraySize = sizeof(providedArray)/sizeof(providedArray[0]);
	//initiate tree
	bst t;
	//insert provided array into tree
	int i, k;
	cout << "The provided array is:" << endl;
	for (i=0; i<providedArraySize; i++){
		t.insert(providedArray[i]);
		cout << " " << providedArray[i];
		if (i<(providedArraySize - 1)){
			cout << ",";
		}	
	}
	cout << endl << 
		"While that was printing, I inserted the array into a Binary Search Tree." <<endl<<
		"Here is a print of the tree:"<<endl;
	t.inorderPrint(); //this prints the same way as my inorder
	cout<< "I will return the kth smallest element of the tree." <<endl<<
		"Enter the number of integers you'd like back:";
	cin >> k;
	t.kthSmallestPrint(k);
	cout <<endl;
return 0;
}
