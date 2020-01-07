""" cryptoBB.py
    Implements a simple substitution cypher
    Added ability to generate a new key in menu
"""



import random
alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
key =   "XPMGTDHLYONZBWEARKJUFSCIQV"

print(("\n" *50) + "            WELCOME TO THE SUPERCIPHER\n" +
                   "---------------------------------------------------\n\nWELCOME\n")

def main():
  keepGoing = True
  while keepGoing:
    response = menu()
    if response == "1":
      plain = input("text to be encoded: ")
      print(("\n" *50) + "            WELCOME TO THE SUPERCIPHER\n" + "---------------------------------------------------\n\n" + "ENCODED: " + encode(plain) + "\n")
    elif response == "2":
      coded = input("code to be decyphered: ")
      print (("\n" *50)+ "            WELCOME TO THE SUPERCIPHER\n" + "---------------------------------------------------\n\n" + "DECODED: " + decode(coded) + "\n")
    elif response == "3":
      # pull correct variable for modification
      

      # call keygen function
      newCypher = input("Press ENTER to generate the new cipher: ")

      #overwrite old key
      key = newKey(newCypher)
      print (("\n" *50) + "            WELCOME TO THE SUPERCIPHER\n" + "---------------------------------------------------\n\n" + "COPY THAT- NEW CIPHER GENERATED.\n")
    elif response == "0":
      print ("Thanks for doing secret spy stuff with me.")
      keepGoing = False
    else:
      print (("\n" *50) + "            WELCOME TO THE SUPERCIPHER\n" + "---------------------------------------------------\n\n" + "ERROR: INVALID ENTRY.\n")


# define menu function
def menu():
    response = input("(1) Encode Message\n(2) Decode Message\n(3) Generate a new Cipher\n(0) Quit\n\nInput selection: ")
    return response

# define function that accepts a string and substitutes its characters with cypher key characters
def encode(plain):    
    # ensure paramater is capitalized
    plain = plain.upper()
    
    # remove spaces from parameter
    plain = plain.replace(" ", "")
    
    # initialize new string that will get cypher characters
    encodedPlain = ""
    
    """ for loop will step through each index position of 'plain' str, compare that character with that
    character's alphabet position, then concatenate the relevant cypher character to 'encodedPlain'"""
    for letter in plain:
        alphaLocation = alpha.find(letter)
        encodedPlain = encodedPlain + key[alphaLocation]
    return encodedPlain

# define function that decodes a str that corresponds to cypher character location
def decode(coded):    
    # ensure paramater is capitalized
    coded = coded.upper()
    
    # remove spaces from parameter
    coded = coded.replace(" ", "")
    
    # initialize new string that will get alpha characters
    decoded = ""
    
    """ for loop will step through each index position of 'coded' str, compare that character with that
    character's key position, then concatenate the relevant alphabet character to 'decoded'"""
    for letter in coded:
        keyLocation = key.find(letter)
        decoded = decoded + alpha[keyLocation]
    return decoded

# define function that generates a new cypher key
def newKey(newCipher):
    # initialize locals- a blank cipher str and a temporary key pool (not sure if necessary)
    newCipher = ""
    functionKey = key
    
    #for length ensures proper number of iterations
    for letter in key:

        # get random int from a gradually decreasing pool of random numbers.
        # decrement happens later
        newChar = random.randint(0, (len(functionKey) - 1))

        # get character from random int's corresponding key index
        newCipherChar = functionKey[newChar]

        # add that character to the new cipher key
        newCipher = newCipher + newCipherChar

        # remove that character from the pool of characters
        functionKey = functionKey.replace(newCipherChar, "")

        
        
    # send new cipher back to main
    return newCipher


    
    

# run program
main()
