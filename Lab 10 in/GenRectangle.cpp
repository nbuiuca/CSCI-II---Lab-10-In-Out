//Nhan Bui
//Lab10in

#include <iostream>
#include <cmath>
#include "Color.h" 
#include "GenPoint.h"
#include "Quadrilateral.h"
#include "GenRectangle.h"
#include "graph1.h" 
using namespace std;

GenRectangle::GenRectangle()
{

}
void GenRectangle::setPoints(GenPoint ul, GenPoint lr)
{
	//Sets the pdf based on ul and lr

	a.setPoint(ul.getX(), ul.getY());
	b.setPoint(lr.getX(), ul.getY());
	c.setPoint(lr.getX(), lr.getY());
	d.setPoint(ul.getX(), lr.getY());

	//set a,b,c,d genpoint objects to the a,b,c,d private data feilds
	Quadrilateral::setPoints(a, b, c, d);
}
double GenRectangle::getArea()
{
	double area = 0.0;
	double width = 0.0;
	double height = 0.0;

	width = sqrt(pow(b.getX() - a.getX(), 2) + pow(b.getY() - a.getY(), 2));

	height = sqrt(pow(c.getX() - b.getX(), 2) + pow(c.getY() - b.getY(), 2));

	area = width * height;

	return area;

}
void GenRectangle::print()
{
	Quadrilateral::print();

	gout << setPos(a.getX(), a.getY() - 30) << "Rectangle Information" << endg;
	gout << setPos(a.getX(), a.getY() - 15) << "Area: " << getArea() << endg;
}