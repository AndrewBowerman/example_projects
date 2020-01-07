/* JumpyBrick.java
 * Andrew Bowerman
 * 
 * Flappy Bird clone to demonstrate Java OOP.
 * Based on tutorial from Jaryt Bustard with extensive improvements
 * such as reduced looping in the actionPerformed() function- in original, three
 * different while loops are performed on same array- this implementation refactors
 * functionality into single loop.
 */

package jumpyBrick;

import java.awt.Color;
import java.awt.Font;
import java.awt.Graphics;
import java.awt.Rectangle;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.util.ArrayList;//columns you fly through grouped in array
import java.util.Random;//for height of next column gap
import javax.swing.Timer;//iterate engine
import javax.swing.JFrame;

public class JumpyBrick implements ActionListener, MouseListener, KeyListener //aggregation
{
	//attributes
	public static JumpyBrick jumpyBrick;
	public Random rand;
	public final int WIDTH = 1200, HEIGHT = 800, OFFSET = 10, BRICK_SIDE = 20, SPEED = 10;
	public int ticks, yMotion, score; //engine time, hero motion
	public boolean gameOver, started;
	public Renderer renderer;
	public Rectangle brick; //our intrepid hero
	public ArrayList<Rectangle> columns; //the vile antagonists
	
	//methods
	public JumpyBrick () 
	{
		JFrame jframe = new JFrame();
		Timer timer = new Timer(20, this);//'this' class is an action listener 
		renderer = new Renderer();
		rand = new Random();

		jframe.add(renderer);
		jframe.setTitle("Jumpy Brick");
		jframe.setSize(WIDTH, HEIGHT);
	    jframe.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	    jframe.setSize(WIDTH, HEIGHT);
	    jframe.setVisible(true);
	    jframe.setResizable(false);
	    jframe.addMouseListener(this);
	    jframe.addKeyListener(this);
	    
	    brick = new Rectangle(WIDTH/2-OFFSET, HEIGHT/2-OFFSET, BRICK_SIDE, BRICK_SIDE);
	    columns = new ArrayList<Rectangle>();

	    addColumn(true);
	    addColumn(true);
	    addColumn(true);
	    addColumn(true);
	    
	    timer.restart();
	}
	
	public void jump()//click listener handles all states
	{
		if (gameOver) 
		{
			//recreate assets
			brick = new Rectangle(WIDTH/2-OFFSET, HEIGHT/2-OFFSET, BRICK_SIDE, BRICK_SIDE);
		    columns.clear();//recreate array
		    addColumn(true);
		    addColumn(true);
		    addColumn(true);
		    addColumn(true);
		    yMotion = 0;
		    score = 0;
		    //reset state
			gameOver = false;
		}
		
		if (!started)
		{
			started = true;
		}else if (!gameOver)
		{
			if (yMotion > 0)
			{
				yMotion = 0;
			}
			yMotion -= 10;
		}
	}
		
	
	public void addColumn(boolean start) 
	{
		int space = 300;//gap between top&bottom
		int width = 100;
		int height = 50 + rand.nextInt(300);
		if (start)
		{
			columns.add(new Rectangle(WIDTH + width + columns.size()*300, HEIGHT- height - 120, width, height));
			columns.add(new Rectangle(WIDTH + width + (columns.size()-1)*300, 0, width, HEIGHT - height - space));
		}
		else 
		{
			columns.add(new Rectangle(columns.get(columns.size()-1).x + 600, HEIGHT- height - 120, width, height));
			columns.add(new Rectangle(columns.get(columns.size()-1).x, 0, width, HEIGHT - height - space));
		
		}
	}
	
	public void paintColumn(Graphics g, Rectangle column) 
	{
		g.setColor(Color.green.darker().darker());//.darker() stacked increments darkness 
		g.fillRect(column.x, column.y, column.width, column.height);
	}

	public void repaint(Graphics g) 
	{
		//bg
		g.setColor(Color.cyan);
		g.fillRect(0, 0, WIDTH, HEIGHT);
		g.setColor(Color.orange);
		g.fillRect(0, HEIGHT - 120, WIDTH, 120);
		g.setColor(Color.green);
		g.fillRect(0, HEIGHT - 120, WIDTH, 20);		
		//brick
		g.setColor(Color.red);
		g.fillRect(brick.x, brick.y, brick.width, brick.height);
		//columns
		for (Rectangle column : columns) //for column in columns 
		{//this type of iterator cannot remove data
			paintColumn(g, column);
		}
	
		g.setColor(Color.white);
		g.setFont(new Font("Arial", 1, 100));
		if (!started)
		{
			g.drawString("Click To Start!", WIDTH/5, HEIGHT/2-50);
		}
		if (gameOver)
		{
			g.drawString("Game Over", WIDTH/4, HEIGHT/2-50);
		}
		if (!gameOver && started) 
		{
			g.drawString(String.valueOf(score), WIDTH/2, 100);
		}
	}

	@Override
	public void actionPerformed(ActionEvent e) 
	{
		//increment world
		ticks++;
		
		if (started)
			{
			//adjust columns
			for (int i = 0; i < columns.size(); i++)
			{
				//if bird passes through center of column increment score for
				//each top column
				if ((columns.get(i).y==0)&&(brick.x + brick.width/2 > columns.get(i).x + columns.get(i).x/2-5) && (brick.x + brick.width/2 < columns.get(i).x + columns.get(i).x/2+5))
				{
					score++;
				}
					
				//decrement column
				columns.get(i).x -= SPEED;
				//column collision check
				if (columns.get(i).intersects(brick)) 
				{
					gameOver = true;
					brick.x = columns.get(i).x - brick.width;
				}
				
				if (columns.get(i).x<-100)
				{//remove columns that disappear past left bound
					// replace column in array
					if (columns.get(i).y == 0)
				    {//add pair of columns (top&bottom) for every top column that leaves
						addColumn(false);
				    }
					columns.remove(columns.get(i));
				}
			}		
			//adjust player
			
			if ((ticks %2 ==0) && (yMotion<15))
			{
				yMotion += 2;
			}
			brick.y += yMotion;
			
			//boundary collision check
			if ((brick.y >= HEIGHT - 120) || (brick.y < 0)) 
			{
				gameOver = true;
			}
			/*if ((brick.y >= HEIGHT - 120) ) 
			{
			}*/
			if (brick.y + yMotion >= HEIGHT - 120) 
			{
				brick.x-=SPEED;
				brick.y = HEIGHT - 120 - brick.height;
			}
			
		}
		//render world
		renderer.repaint();
	}
	
	public static void main(String[] args) 
	{
		jumpyBrick = new JumpyBrick();
	}

	
	//MOUSE LISTENER OVERRIDES
	@Override
	public void mouseClicked(MouseEvent e) 
	{
		jump();		
	}

	@Override
	public void mouseEntered(MouseEvent e) {}

	@Override
	public void mouseExited(MouseEvent e) {}

	@Override
	public void mousePressed(MouseEvent e) {}

	@Override
	public void mouseReleased(MouseEvent e) {}

	@Override
	public void keyPressed(KeyEvent e) {}

	@Override
	public void keyReleased(KeyEvent e) 
	{
		if (e.getKeyCode() == KeyEvent.VK_SPACE)
		{
			jump();
		}
	}

	@Override
	public void keyTyped(KeyEvent e) { }
}
