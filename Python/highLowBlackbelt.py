### High/Low v2

### User thinks of a random number and the computer will guess correctly
### within 7 turns (if I do it correctly).

# gain ability to generate random numbers
import random

# initialize user's number
print ("\n" * 50)
input ("Think of a number between 1 and 100.\nI'll guess it within 7 tries or I'll double your money back!\n(press ENTER when you've thought of your number): ")
print ("\n" * 50)


# initialize main loop's sentry variable, a counter int, high &
# low bounds, and the computer's first median guess
keepGoing = True
counter = 0
low = 0
high = 100


# while loop for main program
while keepGoing:
    # computer gets 1 guess per loop
    # configure guess amount, clear screen, prompt user
    guess = (high + low) // 2
    print ("\n" * 50)
    print ("Is your number {}?\n(1) Yes\n(2) Too Low\n(3) Too High".format(guess))
    response = int(input("(1/2/3): "))
    counter = counter + 1

    # telling computer they were right displays victory message and ends program
    if response == 1:
        print ("I knew it! It took me {} tries to guess correctly.".format(counter))
        keepGoing = False

    # computer guessing too low yields 'too low' response and resets lower boundary at 'guess'
    elif response == 2:
        print ("\n" * 50)
        print ("Too low?!")
        low = guess + 1

    # if guess isn't correct or too low, display 'too high' reponse and reset upper boundary of guess
    elif response ==3:
        print ("\n" * 50)
        print ("Too high?!")
        high = guess

    # if user enters anything but 1-3, reset counter and go to top of loop
    else:
        counter = counter + 1

#end program
input ("Press ENTER to quit): ")
