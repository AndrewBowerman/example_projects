#	selectionSort.pl
#	Andrew Bowerman
#	CS 355 
#	example of sorting Perl to illustrate differences in Python
#	modification history:
#		20190914: creation
# Prompt:
#  "Write a program that inputs ten (10) integers and then sorts them in order from largest to smallest in Python.
#  You do not need to error check the input; you can assume the user enters integers.  
#  You can select the sorting algorithm of your choice, but you must implement this algorithm yourself.  
#  You cannot use a built-in sorting function."

sub printArray()
{
	#find largest element in array and place it at current index, then iterate
	print "[";
	for my $i (0 .. 10)
	{
		print $_[0][$i];
		if ($i < (9))
		{
			print ", ";
		}
		
	}
	print "]";
} #end printArray()

sub main
{
	#collect user nums for array
	my @sortingArray =(0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	print "Enter 10 numbers to be sorted: \n";
	my $i=0;
	for (@sortingArray)
	{
		#fill array
		print "Enter num: ";
		my $input = <STDIN>;
		chomp $input; #removes newline/carriage return
		@sortingArray[$i]=$input;
		$i++;
	}
	
	print "Unsorted Array: \n";
	&printArray(\@sortingArray);
	print "\n";
	
	
	#selection sort
	### this had been its own function but wasn't using the values correctly (see ln 60)
	#&selectionSort(\@sortingArray);

	for ($i=0; $i<10; $i++)		#initially I avoided the C for loops in favor of Perl  
	{							#style loops (e.g. "for  my $j ($i .. 10)") but it was a mess
		my $max=$i;
		
		for  ($j=$i; $j<10; $j++) 
		{
			## BUG ##
			# for some reason this will swap values that are smaller than @sortingArray[$j]. Sometimes.
			if (@sortingArray[$j] > @sortingArray[$max])
			{
				$max=$j;
			}
			$temp = @sortingArray[$max];
			@sortingArray[$max] = @sortingArray[$i];
			@sortingArray[$i] =$temp;
		}
	}
	
	print "Sorted Array: \n";
	&printArray(\@sortingArray);
	print "\n";
} #end main()

main();