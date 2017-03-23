#include <iostream>
#include <string>
#ifndef RECTANGLE2D_H 
#define RECTANGLE2D_H
//EX04_04 11.9
class Rectangle2D {
private:
	double X, Y, Width, Height;
public:
	//const get & set fxns
	double getX() const { return X; }
	double getY() const { return Y; }
	double getWidth() const { return Width; }
	double getHeight() const  { return Height; }
	double setX(double x) { X = x; }
	double setY(double y) { Y = y; }
	double setWidth(double width) { Width = width; }
	double setHeight(double height) { Height = height; }
	//no arg & arg constructors
	Rectangle2D() {
		X = Y = 0;
		Width = Height = 1;
	}
	Rectangle2D(double x, double y, double width, double height) {
		X = x;
		Y = y;
		Width = width;
		Height = height;
	}
	//Fxns
	const double getArea() { return (Height*Width); }
	const double getPerimeter() { return ((2*Height)+(2*Width)); }
	const bool contains(double x, double y) { //is point contained
		//test that center point within sides of rectangle
		return ((x < (X + Width/2)) && (x > (X - Width/2)) && (y < (Y + Height/2)) && (y > (Y - Height/2)));
	}
	const bool contains(const Rectangle2D &r) { //is rectangle contained
		double rT = r.getY() + r.getHeight() / 2; //top of test rectangle  ///should these all be ptrs to save mem space???
		double rB = r.getY() - r.getHeight() / 2; //bottom of test rectangle
		double rR = r.getX() + r.getWidth() / 2; //right of test rectangle
		double rL = r.getX() - r.getWidth() / 2; //left of test rectangle
		double mainT = Y + Height / 2; //Top of Main Rectangle (class rectangle)
		double mainB = Y - Height / 2; //Bottom of Main Rectangle
		double mainR = X + Width / 2; //Right of Main Rectangle
		double mainL = X - Width / 2; //Left of Main Rectangle

		//test that each side of test "under" respective side of Main
		return ((rT < mainT) && (rB > mainB) && (rR < mainR) && (rL > mainL));
	}
	const bool overlaps(const Rectangle2D &r) { //does rectangle overlap
		double rT = r.getY() + r.getHeight() / 2; //top of test rectangle
		double rB = r.getY() - r.getHeight() / 2; //bottom of test rectangle
		double rR = r.getX() + r.getWidth() / 2; //right of test rectangle
		double rL = r.getX() - r.getWidth()/2; //left of test rectangle
		double mainT = Y + Height/2; //Top of Main Rectangle (class rectangle)
		double mainB = Y - Height/2; //Bottom of Main Rectangle
		double mainR = X + Width/2; //Right of Main Rectangle
		double mainL = X - Width/2; //Left of Main Rectangle
		//TEST is if the right side of test lies to the left of main, etc etc. if it does, test does NOT overlap
		return !((rT < mainB) || (rB > mainT) || (rR < mainL) || (rL > mainR)); //if these are true, overlap = FALSE (thnx to !)
				//these should be || right.... doesnt matter 
	}
};

/*
UML DIAGRAM
- double X, Y, Width, Height;
+ double getX() const
+ double getY() const 
+ double getWidth() const 
+ double getHeight() const 
+ double setX(double x) 
+ double setY(double y) 
+ double setWidth(double width)
+ double setHeight(double height) 
+ Rectangle2D()
+ Rectangle2D(double x, double y, double width, double height)
+ const double getArea()
+ const double getPerimeter()
+ const bool contains(double x, double y)
+ const bool contains(const Rectangle2D &r)
+ const bool contains(const Rectangle2D &r)
+ const bool overlaps(const Rectangle2D &r)
*/

#endif
