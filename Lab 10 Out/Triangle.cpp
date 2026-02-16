//NhanBui
//Lab10out

#include <iostream>
#include <math.h>
#include"graph1.h"
#include "Color.h"
#include "Triangle.h"

using namespace std;

Triangle::Triangle()
{
	a.setPoint(0, 0);
	b.setPoint(0, 0);
	c.setPoint(0, 0);

	Color(0, 0, 0);
}
Triangle::Triangle(GenPoint a, GenPoint b, GenPoint c, Color color)
{
	this->a.setPoint(a.getX(), a.getY());
	this->b.setPoint(b.getX(), b.getY());
	this->c.setPoint(c.getX(), c.getY());

	Shape::setCol(color);
}
void Triangle::setPoints(GenPoint a, GenPoint b, GenPoint c)
{

	int temp_x = 0;
	int temp_y = 0;

	//Clip A
	if (a.getX() < 0)
		temp_x = 0;
	else if (a.getX() > 639)
		temp_x = 639;
	else
		temp_x = a.getX();

	if (a.getY() < 0)
		temp_y = 0;
	else if (a.getY() > 399)
		temp_y = 639;
	else
		temp_y = a.getY();

	// Set A
	this->a.setPoint(temp_x, temp_y);

	if (b.getX() < 0)
		temp_x = 0;
	else if (b.getX() > 639)
		temp_x = 639;
	else
		temp_x = b.getX();

	if (b.getY() < 0)
		temp_y = 0;
	else if (b.getY() > 399)
		temp_y = 639;
	else
		temp_y = b.getY();

	// Set B
	this->b.setPoint(temp_x, temp_y);

	//Clip C

	if (c.getX() < 0)
		temp_x = 0;
	else if (c.getX() > 639)
		temp_x = 639;
	else
		temp_x = c.getX();

	if (c.getY() < 0)
		temp_y = 0;
	else if (c.getY() > 399)
		temp_y = 639;
	else
		temp_y = c.getY();

	// Set C
	this->c.setPoint(temp_x, temp_y);
}
double Triangle::getArea()
{
	double side1 = 0.0;
	double side2 = 0.0;
	double side3 = 0.0;
	double s = 0.0;
	double area = 0.0;

	side1 = sqrt(pow(b.getX() - a.getX(), 2) + pow(b.getY() - a.getY(), 2));
	side2 = sqrt(pow(c.getX() - b.getX(), 2) + pow(c.getY() - b.getY(), 2));
	side3 = sqrt(pow(a.getX() - c.getX(), 2) + pow(a.getY() - c.getY(), 2));

	s = (side1 + side2 + side3) / 2.0;

	area = sqrt(s * (s - side1) * (s - side2) * (s - side3));

	return area;

}
double Triangle::getPerimeter()
{
	double side[3] = { 0.0 };
	double perimeter = 0.0; 
	int i = 0;

	side[0] = sqrt(pow(b.getX() - a.getX(), 2) + pow(b.getY() - a.getY(), 2));
	side[1] = sqrt(pow(c.getX() - b.getX(), 2) + pow(c.getY() - b.getY(), 2));
	side[2] = sqrt(pow(a.getX() - c.getX(), 2) + pow(a.getY() - c.getY(), 2));

	for (i = 0; i < 3; i++)
	{
		perimeter += side[i];
	}

	return perimeter;
}
void Triangle::print()
{
	gout << setPos(0, 400) << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  - - - - - - - - - - - - - " << endg;
	gout << setPos(200, 405) << "Shape info follows for: Triangle" << endg;
	gout << setPos(200, 420) << "Point a: (" << a.getX() << "," << a.getY() << ")" << endg;
	gout << setPos(200, 435) << "Point b: (" << b.getX() << "," << b.getY() << ")" << endg;
	gout << setPos(200, 450) << "Point c: (" << c.getX() << "," << c.getY() << ")" << endg;
	gout << setPos(200, 465) << "Perimeter: " << getPerimeter() << " Area: " << getArea() << endg;
}
void Triangle::draw()
{
	int line = 0;

	//A-B

	line = drawLine(a.getX(), a.getY(), b.getX(), b.getY(), 3);
	setColor(line, color.getRed(), color.getGreen(), color.getBlue());

	//B-C

	line = drawLine(b.getX(), b.getY(), c.getX(), c.getY(), 3);
	setColor(line, color.getRed(), color.getGreen(), color.getBlue());

	//C-A
	line = drawLine(c.getX(), c.getY(), a.getX(), a.getY(), 3);
	setColor(line, color.getRed(), color.getGreen(), color.getBlue());

}