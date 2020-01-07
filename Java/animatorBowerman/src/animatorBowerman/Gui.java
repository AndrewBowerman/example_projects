/*
	Animator java project
	Andrew Bowerman
	CS 240
	8/2/2017
	
	Gui.java
	implements GUI, including custom asciiCanvas class
 */
package animatorBowerman;

import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.*;
import javax.swing.*;

public class Gui extends JFrame implements ActionListener {
	private static final long serialVersionUID = 1L;//thanks eclipse
	int index = 0;
	//create gui elements
	
	JLabel lblTitle = new JLabel("ANIMATOR");
	JButton btnPrev = new JButton("<< Previous");
	JButton btnNext = new JButton("Next >>");
	JButton btnSave = new JButton("Save");
	JButton btnLoad = new JButton("Load");
	Canvas asciiCanvas = new Canvas();
	
  	public static void main(String args[]){
        new Gui();
    } // end main
    
    public Gui() {
    			
    	//CREATE GUI
    	super("Animator: Andrew Bowerman");
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        Container mainPanel = this.getContentPane();
        mainPanel.setLayout(new GridLayout(0,1));
        mainPanel.add(asciiCanvas);        
        mainPanel.add(btnNext);
        mainPanel.add(btnPrev);       
        mainPanel.add(btnSave);       
        mainPanel.add(btnLoad);
        btnPrev.addActionListener(this);
        btnNext.addActionListener(this);
        btnSave.addActionListener(this);
        btnLoad.addActionListener(this);
                 
        this.setSize(198, 510);
        this.setVisible(true);
        
        //check for save data and if able, load it
    	File check = new File("save.dat");
		if (check.isFile()) { //if there's data in directory, load it
			asciiCanvas.loadFrames();
			asciiCanvas.displayFrame(index);
		}
    } // end constructor
    
    public void actionPerformed(ActionEvent e){
   	 
    	Object press = e.getSource();
    	if (press == btnPrev){
    		prevEvent();
    	}else if (press == btnNext){
    		nextEvent();
    	}else if (press == btnSave){
    		saveEvent();
    	}else if (press == btnLoad){
    		loadEvent();
    	}else {
    		System.out.println("Something went wrong");
    	} // end if
    	 
      }
    public void prevEvent() {
    	//record any changes to frame
    	asciiCanvas.frames.get(index).setFrame(asciiCanvas.getText());
    	//go to prev frame
    	if (index == 0) { //go to end if at beginning
			index = asciiCanvas.frames.size() - 1;
		}
		else {
			index --;
		}
		//display frame
		asciiCanvas.displayFrame(index);
    }
    public void nextEvent() {
    	//record any changes to frame
    	asciiCanvas.frames.get(index).setFrame(asciiCanvas.getText());
    	//go to next frame
    	if (index == (asciiCanvas.frames.size() - 1)) { //reset if at end
			index = 0;
		}
		else {
			index ++;
		}
		//display frame
		asciiCanvas.displayFrame(index);
    }
    public void saveEvent() {
    	//tell canvas to save linked list
    	asciiCanvas.saveFrames();
    }
    public void loadEvent() {
    	index = 0;
    	asciiCanvas.loadFrames();
		asciiCanvas.displayFrame(index);
    }
}
