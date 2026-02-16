//NhanBui
//Lab10out
#include <iostream>
#include <math.h>
#include "Color.h"
#include "graph1.h"
#include "Trapezoid.h"

Trapezoid::Trapezoid()
{

}
Trapezoid::Trapezoid(GenPoint a, GenPoint b, GenPoint c, GenPoint d, Color color)
{
	Quadrilateral::setPoints(a, b, c, d);

	Shape::setCol(color);
}
void Trapezoid::setPoints(GenPoint a, GenPoint b, GenPoint c, GenPoint d)
{
	Quadrilateral::setPoints(a, b, c, d);
}
double Trapezoid::getArea()
{
	double area = 0;
	double base1 = 0;
	double base2 = 0;
	double height = 0;

	base1 = sqrt(pow(a.getX() - b.getX(), 2) + pow(a.getY() - b.getY(), 2));
	base2 = sqrt(pow(c.getX() - d.getX(), 2) + pow(c.getY() - d.getY(), 2));

	height = sqrt(pow(b.getX() - c.getX(), 2) + pow(b.getY() - c.getY(), 2));

	area = 0.5 * (base1 + base2) * height;

	return area;
}
void Trapezoid::print()
{
	Quadrilateral::print();

	gout << setPos(0, 15) << "Trapezoid Information" << endg;
	gout << setPos(0, 30) << "Area: " << getArea() << endg;

}