//Nhan bui
//Lab10in

#include <iostream>
#include <cmath>
#include "Color.h" 
#include "GenPoint.h"
#include "Quadrilateral.h"
#include "GenRectangle.h"
#include "graph1.h" 
using namespace std;

Quadrilateral::Quadrilateral()
{
	//set all to 0

	a.setPoint(0, 0);
	b.setPoint(0, 0);
	c.setPoint(0, 0);
	d.setPoint(0, 0);

	color.setColor(0, 0, 0);
}
void Quadrilateral::setPoints(GenPoint a, GenPoint b, GenPoint c, GenPoint d)
{

	this->a.setPoint(a.getX(), a.getY());
	this->b.setPoint(b.getX(), b.getY());
	this->c.setPoint(c.getX(), c.getY());
	this->d.setPoint(d.getX(), d.getY());


}
void Quadrilateral::setCol(Color color)
{

	this->color.setColor(color.getRed(), color.getGreen(), color.getBlue());

}
double Quadrilateral::getPerimeter()
{
	double perimeter = 0.0;
	perimeter += sqrt(pow(b.getX() - a.getX(), 2) + pow(b.getY() - a.getY(), 2));
	perimeter += sqrt(pow(c.getX() - b.getX(), 2) + pow(c.getY() - b.getY(), 2));
	perimeter += sqrt(pow(d.getX() - c.getX(), 2) + pow(d.getY() - c.getY(), 2));
	perimeter += sqrt(pow(a.getX() - d.getX(), 2) + pow(a.getY() - d.getY(), 2));

	return perimeter;
}
void Quadrilateral::print()
{
	int obj = drawLine(0, 385, 640, 385, 1);
	::setColor(0, 255, 0);

	gout << setPos(200, 405) << "Shape info follows for: Quadrilateral" << endg;
	gout << setPos(200, 420) << "Point a: (" << a.getX() << ", " << a.getY() << ")" << endg;
	gout << setPos(200, 435) << "Point b: (" << b.getX() << ", " << b.getY() << ")" << endg;
	gout << setPos(200, 450) << "Point c: (" << c.getX() << ", " << c.getY() << ")" << endg;
	gout << setPos(200, 465) << "Point d: (" << d.getX() << ", " << d.getY() << ")" << endg;
	gout << setPos(200, 480) << "Perimeter: " << getPerimeter() << endg;


}
void Quadrilateral::draw()
{
	int line = 0;

	//A-B

	line = drawLine(a.getX(), a.getY(), b.getX(), b.getY(), 3);
	setColor(line, color.getRed(), color.getGreen(), color.getBlue());

	//B -C

	line = drawLine(b.getX(), b.getY(), c.getX(), c.getY(), 3);
	setColor(line, color.getRed(), color.getGreen(), color.getBlue());

	//C-D

	line = drawLine(c.getX(), c.getY(), d.getX(), d.getY(), 3);
	setColor(line, color.getRed(), color.getGreen(), color.getBlue());

	//D - A

	line = drawLine(d.getX(), d.getY(), a.getX(), a.getY(), 3);
	setColor(line, color.getRed(), color.getGreen(), color.getBlue());

}