# funky.py
# exceptions in python
# andrew bowerman
# cs355

#collect integer  
x = int(input("Enter a number greater than zero: "))

if x < 0:
	#condition based exception is raised
	raise Exception("Sorry, no numbers below zero")
else:
	print x