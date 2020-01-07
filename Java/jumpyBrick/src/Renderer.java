package jumpyBrick;

import java.awt.Graphics;
import javax.swing.JPanel;

public class Renderer extends JPanel //inheritence
{
	private static final long serialVersionUID = 1L;
	
	@Override
	protected void paintComponent(Graphics g) 
	{
		super.paintComponent(g);
		JumpyBrick.jumpyBrick.repaint(g);
	}
}
