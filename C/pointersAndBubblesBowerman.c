//bubble.c
//famous bubble sort
//implement the swap algorithm with pointers

#include <stdio.h>
#define MAX 9

//function prototypes
void printValues();
void sort();
void swap(int*, int*);

int values[] = {7, 3, 9, 4, 6, 1, 2, 8, 5};

int main(){
  printf("Before: \n");
  printValues();
  sort();
  printf("After: \n");
  printValues();

  return(0);
} // end main

void printValues(){
    //prints the values list
    int i;
    printf("[");
    for (i=0; i < MAX; i++){
        printf("%d", values[i]);
        if (i<MAX-1){//I know that in the example output there's a space before the last bracket, but leaving it in looks bad.
            printf(" ");
        }
    }
    printf("]\n");
}

//*
void sort(){
    //bubble sorts elements of values list
    //initialize variables for loops
    int i, j;

    //for loop steps through values list
    for (i=0; i < MAX-1; i++){
        //nested loop compares values list elements against their following neighbor
        for (j=0; j < MAX-1; j++){

            if (values[j] > values[j + 1]){
                //if current index has a higher value than the next index,
                //swap list elements with swap function
                swap((values + j), (values + j + 1));

                //print each step
                printValues();

}}}}

void swap(int* j, int* k){
    int swappo; //cache variable

    swappo = *j;
    *j= *k;
    *k= swappo;
}
