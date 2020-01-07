# Change maker v2.0
# Accept cost of an item and money from user, then calculate change
# astronaut ascii art from http://www.chris.com/ascii/index.php?art=people/occupations/astronauts

#initialize art template
vendor = """
                     _________________                
        .-----.     | 
       /=      \    | 
      |- /~~~\  |   | 
      |=( '.' ) |  / -----------------  
      \__\_=_/__/     
       {_______}      
     /` *       `'--._ __
    /= .     [] .     {__>
   /  /|ooo     |`'--'
  (   )\_______/      
   \``\/       \      
    `-| ==    \_|
______|________\|_________________________________________"""


# add custom text to astronaut template to allow multiple uses
# I realized if I counted backwards from the end the string i would've
# been able to type my dialogue in the corrcect order but I had already counted to 124, soooo
print ('\n' * 50)
vendorGreeting = (vendor[:124] + "THE MOON STORE!" + vendor[124:])
vendorGreeting = (vendorGreeting[:101] + "WELCOME TO" + vendorGreeting[101:])
vendorGreeting = (vendorGreeting[:78] + "HI!" + vendorGreeting[78:])
print (vendorGreeting)

# decided to initialize some reused dialogue up here so I can pull it later
vendorConf = (vendor[:124] + "DO YOU WANT?" + vendor[124:])
vendorConf = (vendorConf[:101] + "FINE MOONPRODUCT" + vendorConf[101:])
vendorConf = (vendorConf[:78] + "HOW MANY OF THAT" + vendorConf[78:])


# any input continues, followed by a 'cleared screen' and the vendor asking if you want to visit his shop
input("Press ENTER to continue: ")
print ('\n' * 50)

vendorGreeting = (vendor[:124] + "SPACE WARES?" + vendor[124:])
vendorGreeting = (vendorGreeting[:101] + "TO BROWSE MY FANTASTIC" + vendorGreeting[101:])
vendorGreeting = (vendorGreeting[:78] + "WOULD YOU LIKE" + vendorGreeting[78:])


#input validation for shop entry.
print (vendorGreeting)
response = input("(YES/NO): ")
response = response.upper()
while response not in {'YES', 'NO'}:
    print ('\n' * 50)
    vendorValidation = (vendor[:124] + "SAY 'YES' OR 'NO' TO ANSWER." + vendor[124:])
    vendorValidation = (vendorValidation[:101] + "MY RECEIVER IS ON THE FRITZ!" + vendorValidation[101:])
    vendorValidation = (vendorValidation[:78] + "*KSSHHKT* DIDN'T CATCH THAT-" + vendorValidation[78:])
    print (vendorValidation)
    response = input("(YES/NO): ")
    response = response.upper()

# if user doesn't want SPACE GOODS, end program
if response in 'NO':
        print ('\n' * 50)
        vendorGreeting = (vendor[:124] + "KICK MOON ROCKS!" + vendor[124:])
        vendorGreeting = (vendorGreeting[:101] + "EAT YOU REGARDLESS!" + vendorGreeting[101:])
        vendorGreeting = (vendorGreeting[:78] + "THE SPACE WORMS WILL" + vendorGreeting[78:])
        print (vendorGreeting)
        input('"YEAH, YOU TOO, PAL." (continue): ')
        quit()

    
#if they say yes, initialize inventory and continue to shop loop
selection = 0
int(selection)
moonLaser = 0
int(moonLaser)
moonBoots = 0
int(moonBoots)
moonMooseHat = 0
int(moonMooseHat)
while selection > (-1) and selection < 4:
        print ('\n' * 50)
        vendorWall = (vendor[:124] + "(3) MOONLASER - $249.99 (4) THAT'LL DO, MOON PIG" + vendor[124:])
        vendorWall = (vendorWall[:101] + "(1) MOONBOOTS - $99.99  (2) MOONMOOSE HAT - $24.99" + vendorWall[101:])
        vendorWall = (vendorWall[:78] + "WHAT'RE YA BUYING?" + vendorWall[78:])
        print(vendorWall)
        selection = input("SELECTION: ")
        selection = int(selection)


        # I think I could make the inventory an array but I'm not very savvy with them
        # nested ifs for each selection
        if selection == 1:
            print ('\n' * 50)
            print(vendorConf)
            numberWanted = input("SELECTION: ")
            numberWanted = int(numberWanted)
            moonBoots = moonBoots + numberWanted

        if selection == 2:
            print ('\n' * 50)
            print(vendorConf)
            numberWanted = input("SELECTION: ")
            numberWanted = int(numberWanted)
            moonMooseHat = moonMooseHat + numberWanted

        if selection == 3:
            print ('\n' * 50)
            print(vendorConf)
            numberWanted = input("SELECTION: ")
            numberWanted = int(numberWanted)
            moonLaser = moonLaser + numberWanted

        if selection == 4:
            break

# Give breakdown of items and provide total
totalItems = 0
totalItems = moonBoots + moonMooseHat + moonLaser
cost = 0
cost = float(cost)
cost = (moonBoots * 99.99) + (moonMooseHat * 24.99) + (moonLaser * 249.99)

vendorTotal = (vendor[:124] + "YOUR TOTAL IS {} MOONBUCKS.".format(round(cost, 2)) + vendor[124:])
vendorTotal = (vendorTotal[:101] + "FINE MOONPRODUCTS!" + vendorTotal[101:])
vendorTotal = (vendorTotal[:78] + "YOU'RE PURCHASING {} SUPER".format(totalItems) + vendorTotal[78:])
print ('\n' * 50)
print(vendorTotal)


# pay merchant
moneyTendered = input ("HOW MANY MOONBUCKS ARE YOU PAYING WITH? $")

#convert variables to floats and from dollars to pennies
moneyTendered = float(moneyTendered)

# 'change' will be used to calculate individual change types
# initialize and convert to pennies
# rounding to two decimals here ensures proper penny number
change = moneyTendered - cost
change = round(change, 2)
change = change * 100
change = int(change)

# identify number of HUNDRED dollar bills needed in change
hundreds = change // 10000
# and calculate remaining change
change = change % 10000

# identify number of FIFTY dollar bills needed in change
fifties = change // 5000
# and calculate remaining change
change = change % 5000

# identify number of twenty dollar bills needed in change
twenties = change // 2000
# and calculate remaining change
change = change % 2000

# identify number of ten dollar bills needed in change
# and calculate remaining change
tens = change // 1000
change = change % 1000

# identify number of five dollar bills needed in change
# and calculate remaining change
fives = change // 500
change = change % 500

# identify number of one dollar bills needed in change
# and calculate remaining change
ones = change // 100
change = change % 100

# identify number of quarters needed in change
# and calculate remaining change
quarters = change // 25
change = change % 25

# identify number of dimes needed in change
# and calculate remaining change
dimes = change // 10
change = change % 10

# identify number of nickels needed in change
# and calculate remaining change
nickels = change // 5
change = change % 5

# identify number of pennies needed in change
pennies = change

# tell user their change and individual currencies
change = moneyTendered - cost

vendorFinal = (vendor[:209] + "{} MOONDIMES, {} MOONNICKELS, AND {} MOONPENNIES!".format(dimes, nickels, pennies) + vendor[209:])
vendorFinal = (vendorFinal[:186] + "{} MOONWASHINGTONS, {} MOONQUARTERS,".format(ones, quarters) + vendorFinal[186:])
vendorFinal = (vendorFinal[:124] + "{} MOONTUBMANS, {} MOONHAMILTONS, {} MOONLINCOLNS,".format(twenties, tens, fives) + vendorFinal[124:])
vendorFinal = (vendorFinal[:101] + "THAT'S {} MOONBENJAMINS, {} MOONGRANTS,  ".format(hundreds, fifties) + vendorFinal[101:])
vendorFinal = (vendorFinal[:78] + "YOUR CHANGE COMES OUT TO {} MOONBUCKS!".format(round(change, 2))) + vendorFinal[78:]

print ("\n" *50)
print (vendorFinal)
input ("THANKS! WATCH OUT FOR MOON WORMS! (press enter to quit): ")




