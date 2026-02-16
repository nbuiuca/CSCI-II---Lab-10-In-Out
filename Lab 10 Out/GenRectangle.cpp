//Nhan Bui
//Lab10in
#include <iostream>
#include <math.h>
#include "graph1.h"
#include "GenRectangle.h"
#include "Quadrilateral.h"
#include "Color.h"

using namespace std;

GenRectangle::GenRectangle()
{

}

GenRectangle::GenRectangle(GenPoint ul, GenPoint lr, Color c)
{

	Quadrilateral::setPoints(ul, GenPoint(lr.getX(), ul.getY()), lr, GenPoint(ul.getX(), lr.getY()));

	Shape::setCol(c);
}
void GenRectangle::setPoints(GenPoint ul, GenPoint lr)
{
	Quadrilateral::setPoints(ul, GenPoint(lr.getX(), ul.getY()), lr, GenPoint(ul.getX(), lr.getY()));
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

	gout << setPos(0, 15) << "Rectangle Information" << endg;
	gout << setPos(0, 30) << "Area: " << getArea() << endg;
}