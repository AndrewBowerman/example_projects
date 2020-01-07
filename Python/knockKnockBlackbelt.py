# Knock Knock Blackbelt
# Andrew Bowerman 2/15/17
# This HelloWorld v2.0 is an intro to the python language
# Blackbelt version contains input validation and a special prize for
# users that complete the joke without guessing
# cow ascii art is credited to Joan Stark and found at http://www.ascii-code.com/ascii-art/animals/cows.php

cow = """             /( ,,,,, )\\
            _\\,;;;;;;;,/_
         .--; ;;;;;;;;; ;--.
         '.__/`_ / \\ _`\\__.'
            | (')| |(') |
            | .--' '--. |        ______
            |/ o     o \|       |_moo._|
            |           |      /
           / \\ _..=.._ / \\
          /:. '._____.'   \\
         ;::'    / \\      .;
         |     _|_ _|_   ::|
       .-|     '==o=='    '|-.
      /  |  . /       \\    |  \\
      |  | ::|         |   | .|
      |  (  ')         (.  )::|
      |: |   |; U U U ;|:: | `|
      |' |   | \ U U / |'  |  |
      ##V|   |_/`---`\_|   |V##
jgs      ##V##         ##V##"""
# ask user for name
print ("Hi! Welcome to Python 3! What is your name?")

# collect name from user as a string called "name"
name = input()

# repeat name back in a greeting & find out if user wants to hear a joke
response = input("Hi, " + name + ". It is nice to meet you! \nWould you like to hear a joke? \n(Y/N) ")
response = response.upper()


# only allow for Y or N as an input
while response not in {'Y', 'N'}:
    print("I didn't catch that- please respond with a Y or N.")
    response = input()
    response = response.upper()

# if user doesn't want a joke, end program
if (response == 'N'):
    print("Fine with me, " + name + ", have a good one!")
    quit()
    
#if they say yes, continue
if (response == 'Y'):
    print ("Alright!\nKnock knock!")

# get a response from user and force them to input "who's there?"
response = input()
response = response.upper()

while response not in {"WHO'S THERE?"}:
    print("You're SUPPOSED to ask 'Who's there?'")
    response = input()
    response = response.upper()

# print more joke
if (response == "WHO'S THERE?"):
    print("Cow says.")

# force user to say "cow says who?" and give them an eye roll if they guess it
response = input()
response = response.upper()
while response not in {"COW SAYS WHO?", "COW SAYS MOO"}:
    print("Say, 'Cow says who?'")
    response = input()
    response = response.upper()

if (response == 'COW SAYS MOO'):
    print("You aren't supposed to guess, " + name + ".\nBut yes, a cow says moo.")
    quit()
    
#finish joke 
print("No, a cow says MOO!\n")
print(cow)

#end program
quit()


