//NhanBui
//Lab10out

#include <iostream>
#include "Circle.h"
#include <math.h>
#include "graph1.h"

using namespace std;

const double Circle::PI = 3.1415926;

Circle::Circle()
{
	int radius = 0;
	GenPoint center(0, 0);
}
Circle::Circle(GenPoint center, int radius, Color c)
{
	this->radius = radius;
	this->center.setPoint(center.getX(), center.getY());
	Shape::setCol(c);
}
void Circle::setCenter(GenPoint center)
{
	this->center = center;
}
void Circle::setRadius(int radius)
{
	this->radius = radius;
}
double Circle::getPerimeter()
{	double perimeter = 0.0;

	perimeter = 2 * PI * radius;

	return perimeter;
}
double Circle::getArea()
{
	double area = 0.0;

	area = 2 * PI * radius;

	return area;
}
void Circle::print()
{
	gout << setPos(0, 400) << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  - - - - - - - - - - - - - " << endg;
	gout << setPos(200, 405) << "Shape info follows for: Circle" << endg;
	gout << setPos(200, 420) << "Center Point: (" << center.getX() << "," << center.getY() << ")" << endg;
	gout << setPos(200, 435) << "Radius: " << radius << endg;
	gout << setPos(200, 450) << "Perimeter: " << getPerimeter() << endg;
	
}
void Circle::draw()
{
	int circle = 0;

	circle = drawCircle(radius, center.getX(), center.getY());
	setColor(circle, color.getRed(), color.getGreen(), color.getBlue());
}
