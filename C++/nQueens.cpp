/*
FILE: nQueens.cpp
AUTHOR: Andrew Bowerman
DATE: 20 Sept 2018
PURPOSE: place an amount of n Queens onto a
		 board of n * n squares without placing 
		 queens in squares that can attack each other.
		 when a queen cannot be placed, back track
		 and try new placements of previously placed 
		 queens until all n are placed.
NOTES: this program is based on algorithms found
	   in lecture slides and a great video and 
	   text tutorial recommended by our TA, found 
	   at https://www.geeksforgeeks.org/n-queen-problem-backtracking-3/
	   although that version doesn't use a stack
MODIFICATION HISTORY: 
*/
// N is the number of queens & board dimensions
#define N 4
#include<stdio.h>
#include<stdbool.h> //esp used with safetyDance()
#include <iostream> 
#include <stack> 
using namespace std;
//FUNCTIONS


//printBoard(board) prints the board.
void printBoard(int board[N][N]){
	for(int i = 0; i < N; i++){
		cout << endl;
		for(int j = 0; j < N; j++){
			cout << board[i][j];}}
	cout << endl;
	return;
}

/* bool safetyDance(int board[N][N], int row, int col)
	DESCRIPTION: 
	Before you can place a Queen, she must do the safety dance.
	Since board is filled left to right with 1 queen per 
	column, she only needs to look in 3 directions:
		- all squares in upper left diagonal
		- '' left row
		- '' lower left diagonal
	PARAMETERS:
	board[N][N] - 2d array of board
	int row- the row you're intending to place a queen in
	int column- the intended column
	RETURN VALUES:
	Finding a queen placed in any of these 3 rows returns FALSE
	other wise return TRUE - safety dance passed*/
	
bool safetyDance(int board[N][N], int row, int col){
	
	//sentries to walk up/down board or move left
    int i, j; 
     /* check all squares in upper left diagonal */
    for (i=row, j=col; i>=0 && j>=0; i--, j--)
		// start at current square, check
		// move up 1 row, move left 1 column, check
		// continue while still on board
        if (board[i][j] == 1) 
			//if true, a queen has been found 
			//the current row+col is unsafe
            return false;
	
    /* check all squares in left row */
    for (i = 0; i < col; i++)
        if (board[row][i] == 1)
            return false;
	
	/* check all squares in lower left diagonal */
    for (i=row, j=col; j>=0 && i<N; i++, j--)
        if (board[i][j] == 1)
            return false;
	//if you haven't found an existing queen placed
	//the safety dance passes
    return true;
}//end safetyDance()

/* nQueens()
	//when a safe location is found, place queen on stack by
	  pushing row+col onto stack
	  increment # queens placed

*/
bool nQueens(int board[N][N], int n){
	int row, col, filled = 0;
	stack <int> rowS;
	stack <int> colS;
	//push first queen
	rowS.push(row);
	colS.push(col);
	filled++;
	
	board[col][row]= 1;
	while (filled < n){
		//if queen can be placed
		if (safetyDance(board, filled, col)){
			//place her
			rowS.push(row);
			colS.push(col);
			filled++;
			board[col][row]= 1;
			//cout << "place";
		}
	}//end while
	//exiting while means you've reached base case
	return true;
}




int main() {
	int board[N][N];
	//create board
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			board[i][j] = 0;}}
	//place n Queens on board
	//returning false means N queens could not be placed (eg 2*2)
	nQueens(board, N);
	
	//print solution. 
	printBoard(board);
return 0;
}
