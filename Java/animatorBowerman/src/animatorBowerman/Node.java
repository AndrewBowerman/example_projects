/*
	Animator java project
	Andrew Bowerman
	CS 240
	8/2/2017
	
	Node.java
	Nodes for double linked list with a string
	based largely on examples from Andy Harris used in CS 240 lectures
 */
package animatorBowerman;

import java.io.Serializable;

public class Node implements Serializable{ 
	private static final long serialVersionUID = 1L; //thanks eclipse
	//PROPERTIES
	private String frame;
	private Node next;
	private Node prev;
	
	//METHODS
	//CONSTRUCTORS
	public Node(){ //initialize properties
		frame = "";
		next = null;
		prev = null;
	} 	
	public Node(String frame, Node prev, Node next){ // full constructor
		this.frame = frame;
		this.prev = prev;
		this.next = next;
	}
	//ACCESSORS
	public void setFrame(String frame){
		this.frame = frame;
	}	
	public String getFrame(){
		return this.frame;
	}
	public void setNext(Node next){
		this.next = next;
	}
	public Node getNext(){
		return this.next;
	}	
	public void setPrev(Node prev){
		this.prev = prev;
	}	
	public Node getPrev(){
		return this.prev;
	}
}

