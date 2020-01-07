""" oopRectangle.py
intro to OOP by building a Rectangle class that demonstrates
inheritance and polymorphism.
"""

def main():
    print ("Rectangle a:")
    a = Rectangle(5, 7)
    print ("area:      {}".format(a.area))
    print ("perimeter: {}".format(a.perimeter))
    
    print ("")
    print ("Rectangle b:")
    b = Rectangle()
    b.width = 10
    b.height = 20
    print (b.getStats())

# start of my code

# create a base class with a constructor to inherit into rectangle class
class Progenitor(object):
    def __init__(self, height = 10, width = 10):
        object.__init__(self)
        self.setHeight(height)
        self.setWidth(width)

# lets get down to business
# to defeat the huns
class Rectangle(Progenitor):

    #METHODS
    #constructor is imported from progenitor

    #setters for width and height
    def setWidth (self, width):
        self.__width = width
    def setHeight (self, height):
        self.__height = height
    def setArea (self):
        return getArea()

    # getters return area and perimeter
    def getArea (self):
        return (self.__height * self.__width)
    def getPerimeter (self):
        return ((self.__height + self.__width) * 2)

    # getter for all rectangle stats
    def getStats (self):
        print("width:        {}".format(self.__width))
        print("height:       {}".format(self.__height))
        print("area:         {}".format(self.__area))
        print("perimeter:    {}".format(perimeter))

    #ATTRIBUTES
    width = property(fset = setWidth)
    height = property(fset = setHeight)
    area = property(fset = setArea, fget = getArea)
    perimeter = property(fget = getPerimeter)
    

main()
