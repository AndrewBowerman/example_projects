/*	perfectPet.java Project
 	Andrew Bowerman
  	CS240 
  	7/28/2017
  	
  	perfectPet.java
  	contains program main
  	PerfectPet class
  		-creates, loads and saves 'save.dat', which contains a serialized Pet object
  		-Displays a menu for user interaction
  		-User interaction modifies pet stats
  			- feedPet() raises hunger level by 5
  			- healPet() raises health by 10
  			- trainPet() raises strength by 2, reducing hunger by 2 and health by 3
  */
package perfectPet;
import java.io.*; //file io, serialization
import java.util.Scanner;
public class PerfectPet {

	Scanner input = new Scanner(System.in);
	Pet userPet = new Pet();
	
	public static void main(String[] args) {
		new PerfectPet();
	}
	
	public PerfectPet() {
		//main method
		//check for previous save data
		File check = new File("save.dat");
		if (check.isFile()) { //if there's data in directory, load it
			loadPet();
		}		
		//if not found create new data
		else {
			createPet();
		}
		//every time pet is loaded, remove three hunger
		userPet.setCurrentHunger(-3);
		//enter menu loop
		boolean keepGoing = true;
		do {
			clearScreen();
			displayMenu();
			String selection = input.nextLine();
			if (selection.equals("1")) {
				feedPet();
			}
			else if (selection.equals("2")) {
				healPet();
			}
			else if (selection.equals("3")) {
				trainPet();
			}
			else if (selection.equals("4")) {
				keepGoing = false;
			}
			else {
				//repeat loop
			}
			//save after every loop
			savePet(userPet);
		}while(keepGoing);
		
		//save data on close
		savePet(userPet);
		clearScreen();
		System.out.println("See you next time!");
	}
	public void healPet() {
		userPet.setCurrentHealth(10);
	}

	public void feedPet() {
		userPet.setCurrentHunger(5);
	}	
	public void trainPet() {
		userPet.setCurrentHunger(-3);
		userPet.setCurrentHealth(-2);
		userPet.setStrength(1);		
	}
	public void displayMenu() {
		//dog sprite modified from chris.com courtesy of hjw, retrieved from http://www.chris.com/ascii/index.php?art=animals/dogs
		System.out.println("---------------------------------------------------------------.________________");
		System.out.println("|       ,                    ,\" e`--o                            " + userPet.getName());
		System.out.println("|      ((                   (  | __,'                            Health: " + userPet.getCurrentHealth() + "/" + userPet.getMaxHealth());
		System.out.println("|      \\\\~----------------' \\_;/                                 Hunger: " + userPet.getCurrentHunger() + "/" + userPet.getMaxHunger());
		System.out.println("|      (                      /                                  Strength: " + userPet.getStrength());
		System.out.println("|      /) ._______________.  )                                   ______________");
		System.out.println("|     (( (               (( (                                   /");
		System.out.println("|      ``-'               ``-'                                  \\");
		System.out.println("|------------------------------------------------------------------------------|");
		System.out.println("|  1: Feed Pet                          |   3: Train Pet                       |");
		System.out.println("|  2: Heal Pet                          |   4: QUIT                            |");
		System.out.println("|------------------------------------------------------------------------------|");
		System.out.println( " ENTER A SELECTION: ");
	}

	public void clearScreen() {
		//the tried and true "shove it offscreen" method
		for (int i=0; i<29;i++) {
			System.out.println("\n");
		}
	}
	public void pressEnter() {
		//press Enter to continue scanner, adapted from a few different examples on stack overflow
		System.out.println("Press ENTER to continue: ");
		input.nextLine();
		clearScreen();
	}
	public void savePet(Pet userPet) { //serializable methods based on Andy Harris' examples
		try {
			FileOutputStream fo = new FileOutputStream("save.dat");
			ObjectOutputStream objectOut = new ObjectOutputStream(fo);
			objectOut.writeObject(userPet);
			objectOut.close();
		} catch (Exception e){
			System.out.println(e.getMessage());
		} // end try
	}
	public void loadPet(){
    	try {
    		FileInputStream fIn = new FileInputStream("save.dat");
    		ObjectInputStream obIn = new ObjectInputStream(fIn);
    		userPet = (Pet)obIn.readObject();
        	obIn.close();
    	}catch (Exception e){
    		System.out.println(e.getMessage());
    	} // end try
    } // end loadCritter
	
	public void createPet() {
		//print 'error' message
		System.out.println("---------------------------------------------------------------.________________");
		System.out.println("|");
		System.out.println("|");
		System.out.println("|");
		System.out.println("|");
		System.out.println("|");
		System.out.println("|");
		System.out.println("|");
		System.out.println("|--------------------------------------------------------------._______________|");
		System.out.println("|  Oh, hi there. It seems you've either misplaced your pet or                  |");
		System.out.println("|  let it go the way of all flesh.                                             |");
		System.out.println("|--------------------------------------------------------------._______________|");
		pressEnter();
		
		System.out.println("---------------------------------------------------------------.________________");
		System.out.println("|");
		System.out.println("|");
		System.out.println("|");
		System.out.println("|");
		System.out.println("|");
		System.out.println("|");
		System.out.println("|");
		System.out.println("|--------------------------------------------------------------._______________|");
		System.out.println("|  Or maybe we never gave you one. In any case.                                |");
		System.out.println("|  Let's see what we have left in the back.                                    |");
		System.out.println("|--------------------------------------------------------------._______________|");
		pressEnter();
		
		System.out.println("---------------------------------------------------------------.________________");
		System.out.println("|       ,                    ,\\\" e`--o     ");
		System.out.println("|      ((                   (  | __,'    \\ ");
		System.out.println("|      \\\\\\\\~----------------' \\\\_;/   ");
		System.out.println("|      (                      /  ");
		System.out.println("|      /) ._______________.  )   ");
		System.out.println("|     (( (               (( ( ");
		System.out.println("|      ``-'               ``-'");
		System.out.println("|--------------------------------------------------------------._______________|");
		System.out.println("|  Hmm. Some sort of long, squat dog.                                          |");
		System.out.println("|  This really is all we have left.                                            |");
		System.out.println("|--------------------------------------------------------------._______________|");
		pressEnter();
		
		//get name
		System.out.println("---------------------------------------------------------------.________________");
		System.out.println("|       ,                    ,\\\" e`--o     ");
		System.out.println("|      ((                   (  | __,'    \\ ");
		System.out.println("|      \\\\\\\\~----------------' \\\\_;/   ");
		System.out.println("|      (                      /  ");
		System.out.println("|      /) ._______________.  )   ");
		System.out.println("|     (( (               (( ( ");
		System.out.println("|      ``-'               ``-'");
		System.out.println("|--------------------------------------------------------------._______________|");
		System.out.println("|  Name your dog.                                                              |");
		System.out.println("|                                                                              |");
		System.out.println("|--------------------------------------------------------------._______________|");
		System.out.println( "Type a name and press ENTER:");
		String temp = input.next();
		userPet.setName(temp);
		//save change
		savePet(userPet);
	}
}
