/*	perfectPet.java Project
 	Andrew Bowerman
  	CS240 
  	7/28/2017
  	
  	pet.java
  	
  	Pet class
  		-basic stats with accessor methods
  			-String name
  			-int health   (current/max)
  			-int hunger   (current/max)
  				going below 1 in current hunger reduces current health
  			-int strength 
  			
  	GOALS:
  		implement abilities
  		have stats affect each other (eg max health dependent on total strength)
  */
package perfectPet;
import java.io.*;

public class Pet implements Serializable{
	private static final long serialVersionUID = 1L; //Eclipse generated UID
	String name;
	int currentHunger;
	int maxHunger;
	int currentHealth;
	int maxHealth;
	int strength;
	
	public  Pet() {
		this.name = "Jib Jub the Mighty";
		this.currentHunger = 10;
		this.maxHunger = 10;
		this.currentHealth = 20;
		this.maxHealth = 20;
		this.strength=5;
	}	
	public Pet(String iName) {
		this.name = iName;
		this.currentHunger = 10;
		this.maxHunger = 10;
		this.currentHealth = 20;
		this.maxHealth = 20;
		this.strength=5;
	}	
	public void setName(String modifier) {
		this.name = modifier;
	}	
	public String getName() {
		return this.name;
	}	
	public void setCurrentHunger(int modifier) {
		if ((this.currentHunger + modifier) > this.maxHunger) {
			// don't eat more than max
			this.currentHunger = this.maxHunger;
		}
		else if ((this.currentHunger + modifier) <= 0) {
			// starving reduces health
			this.currentHunger = 0;
			setCurrentHealth(-2);
		}
		else {
			this.currentHunger = this.currentHunger + modifier;
		}
	}	
	public int getCurrentHunger() {
		return this.currentHunger;
	}	
	public void setMaxHunger(int modifier) {
		this.maxHunger = this.maxHunger + modifier;
	}	
	public int getMaxHunger() {
		return this.maxHunger;
	}
	public void setCurrentHealth(int modifier) {
		if ((this.currentHealth + modifier) > this.maxHealth) {
			// don't heal higher than max 
			this.currentHealth = this.maxHealth;
		}
		else {
			this.currentHealth = this.currentHealth + modifier;
		}
	}	
	public int getCurrentHealth() {
		return this.currentHealth;
	}	
	public void setMaxHealth(int modifier) {
		this.maxHealth = this.maxHealth + modifier;
	}	
	public int getMaxHealth() {
		return this.maxHealth;
	}
	public void setStrength(int modifier) {
		this.strength = this.strength + modifier;
	}
	
	public int getStrength() {
		return this.strength;
	}
}
