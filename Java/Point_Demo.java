/*
	Point_Demo.java
	Andrew Bowerman
	Contains a point class (x and y coordinates). This object is then passed
	to a couple different subroutines to observe how Java passes objects.
	This file correlates to passValueAndReference.cpp, which does similar
	operations in C++.
*/

class Point {
	public double x;
	public double y;

	public void Point() {}//constructor
	
	public void setPoint(double x, double y){
		this.x = x;
		this.y = y;
	}

	public void setX(double x){
		this.x = x;
	}

	public void setY(double y){
		this.x = y;
	}

	public double getX() {
		return x;
	}

	public double getY() {
		return y;
	}

	public void printMe() {
		System.out.println("X: " + this.x);
		System.out.println("Y: " + this.y);
	}
}

class ParameterSwapper
/*
Swap the parameters in your subprogram
(i.e. Swap the Point objects, not the individual x and y value)
*/
{
public ParameterSwapper( Point x , Point y, Coordinate_Printer print)
{
	
	System.out.println("Inside subprogram 1...");
	Point temp = new Point();
	temp = x;
	x = y;
	y = temp;
	
	//Print out the x and y values of each object within the subprogram
	print.print(x, y);
}
}

class ValueSwapper
/*
swap the actual values of the Point.
(i.e. swap Point1's x with Point2's x, and then swap Point1's y 
with Point2's y.  Don't swap the objects)
*/
{
public ValueSwapper( Point x , Point y, Coordinate_Printer print)
{
	
	System.out.println("Inside subprogram 2...");
	Point temp = new Point();
	
	//swap
	temp.setPoint(x.getX(), x.getY());
	x.setPoint(y.getX(), y.getY());
	y.setPoint(temp.getX(), temp.getY());
	
	//Print out the x and y values of each object within the subprogram
	print.print(x, y);
}
}

class Coordinate_Printer
{
public Coordinate_Printer()
{
}
public void print (Point x , Point y)
{
	System.out.println("Point1:");
	x.printMe();
	System.out.println("Point2:");
	y.printMe();
}
}


public class Point_Demo
{
public Point_Demo()
{
	//initialize
	Point point1= new Point();
	Point point2= new Point();
	Coordinate_Printer print = new Coordinate_Printer();
	point1.setPoint(1, 2);
	point2.setPoint(3, 4);
	print.print(point1, point2);
	
	
	//first test
	System.out.println("First test. Swapping parameters in subprogram:");
	ParameterSwapper test = new ParameterSwapper(point1, point2, print);
	System.out.println("Returning from subprogram...");
	//Print out the x and y values of each object within the calling program.   
	//(They should be back to the original values.)
	print.print(point1, point2);
	System.out.println("Parameters have returned to original value.");
	
	
	//second test
	System.out.println("Second test. Swapping values in subprogram:");
	ValueSwapper test2 = new ValueSwapper(point1, point2, print);
	System.out.println("Returning from subprogram...");
	//Print out the x and y values of each object within the calling program.   
	//(They should be back to the original values.)
	print.print(point1, point2);
	System.out.println("Parameters have remained at swapped values.");

}

public static void main(String[] args)
{
	new Point_Demo();
}

}
