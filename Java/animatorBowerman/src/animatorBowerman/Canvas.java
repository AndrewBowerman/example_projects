/*
	Animator java project
	Andrew Bowerman
	CS 240
	8/2/2017
	
	Canvas.java
	Extends JTextArea
	Creates Linked Lists of nodes
	Controls access to and displays nodes of linked list animation
 */
package animatorBowerman;

import java.io.*;
import java.util.*;
import javax.swing.*;

public class Canvas extends JTextArea implements Serializable{
	private static final long serialVersionUID = 1L; //thanks Eclipse	
	public LinkedList<Node> frames = new LinkedList<>();
	
	public Canvas() {
		this.setColumns(30);
		this.setRows(10);
		this.setLineWrap(true);
		this.createFrames(11); //thanks rubric :)
		this.setText(frames.getFirst().getFrame());		
	}
	
	void displayFrame(int index) {
		this.setText(frames.get(index).getFrame());
	}
	
	void loadFrames() {
		try {
    		FileInputStream fIn = new FileInputStream("save.dat");
    		ObjectInputStream obIn = new ObjectInputStream(fIn);
    		this.frames = (LinkedList<Node>)obIn.readObject();
        	obIn.close();
    	}catch (Exception e){
    		System.out.println(e.getMessage());
    	} // end try
    } // end loadFrames()
	
	void saveFrames() {
		try {
			FileOutputStream fo = new FileOutputStream("save.dat");
			ObjectOutputStream objectOut = new ObjectOutputStream(fo);
			objectOut.writeObject(this.frames);
			objectOut.close();
		} catch (Exception e){
			System.out.println(e.getMessage());
		} // end try
	}
	
	void createFrames(int numFrames) { 		
		//creates double LL based on Andy Harris' examples used in 240 lectures
		// (sort of, mine's in a loop)
		//create frame nodes to step through
		for (int i=0; i<numFrames; i++) {
			Node frame = new Node();
			
			//create string with number of spaces = canvas height&width
			String data = "";
			for (int j=0; (j<this.getRows()); j++) {
				for (int k=0; k<this.getColumns(); k++) {
					data = data + " ";
				}				
			}
			//save to node
			frame.setFrame(data);
			
			// two paths for setting prev and next
			// if a head exists, make a body piece
			if (i > 0) {
				//set prev
				frame.setPrev(frames.getLast());			
				//set next
				frame.setNext(frames.getFirst());
				//tell old last about its new neighbor
				frames.getLast().setNext(frame);				
			}
			else {
				//create head
				//set prev
				frame.setPrev(null);			
				//set next
				frame.setNext(null);
			}				
			//add frame to list
			frames.add(frame);			
		}//end LL creation
		//make first node's prev the last node
		frames.getFirst().setPrev(frames.getLast());
	}//end createFrames()
}