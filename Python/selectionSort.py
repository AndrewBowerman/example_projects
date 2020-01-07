"""
	selectionSort.py
	Andrew Bowerman
	CS 355 
	example of sorting Python to illustrate differences in Perl
	modification history:
		20190913: creation
		20190914: selection sort implemented
  Prompt:
  "Write a program that inputs ten (10) integers and then sorts them in order from largest to smallest in Python.
  You do not need to error check the input; you can assume the user enters integers.  
  You can select the sorting algorithm of your choice, but you must implement this algorithm yourself.  
  You cannot use a built-in sorting function."
"""


# sorting function
# this sorts high-low
def selectionSort (sortingArray):

	#find largest element in array and place it at current index, then iterate
	for i in range(0, len(sortingArray)):
		#current index is new max
		max=i
		
		#search for higher num in rest of array
		for j in range(i, len(sortingArray)):
			if (sortingArray[j]>sortingArray[max]):
				#if a higher number is found, record index
				max=j
		
		#swap current index with max value
		temp = sortingArray[max];
		sortingArray[max] = sortingArray[i];
		sortingArray[i] =temp;
	
	return sortingArray

# end selectionSort()
	
	
	
def main():

	#initialize
	sortingArray = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
	
	#collect user nums
	print("Enter 10 numbers to be sorted: ")
	for integer in range(0, len(sortingArray)):
		sortingArray[integer]=int(input("Enter num: "))
	
	print("Unsorted array:")	
	print(sortingArray)
	
	selectionSort(sortingArray)
	
	#display sort
	print("Sorted array:")
	print(sortingArray)
	
#end main
		
		
main()