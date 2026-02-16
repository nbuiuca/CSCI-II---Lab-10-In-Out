//Nhan bui
//NhanBui
//lab10out

#include <iostream>
#include <math.h>
#include "graph1.h"
#include "Quadrilateral.h"
#include "Color.h"
#include "Shape.h"
#include "GenPoint.h"

using namespace std;

Quadrilateral::Quadrilateral()
{
	a.setPoint(0, 0);
	b.setPoint(0, 0);
	c.setPoint(0, 0);
	d.setPoint(0, 0);

	Color(0, 0, 0);
}

Quadrilateral::Quadrilateral(GenPoint a, GenPoint b, GenPoint c, GenPoint d, Color color)
{
	this->a.setPoint(a.getX(), a.getY());
	this->b.setPoint(b.getX(), b.getY());
	this->c.setPoint(c.getX(), c.getY());
	this->d.setPoint(d.getX(), d.getY());

	Shape::setCol(color);


}

void Quadrilateral::setPoints(GenPoint a, GenPoint b, GenPoint c, GenPoint d)
{
	// set privatedata fields a,b,c,d

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

	//Clip D

	if (d.getX() < 0)
		temp_x = 0;
	else if (d.getX() > 639)
		temp_x = 639;
	else
		temp_x = d.getX();

	if (d.getY() < 0)
		temp_y = 0;
	else if (d.getY() > 399)
		temp_y = 639;
	else
		temp_y = d.getY();

	// Set D
	this->d.setPoint(temp_x, temp_y);
}

double Quadrilateral::getPerimeter()
{
	double perimeter = 0.0;
	double length[4] = { 0.0 };
	int i = 0;

	// Going from A to B
	length[0] = sqrt(pow(b.getX() - a.getX(), 2) + pow(b.getY() - a.getY(), 2));

	//Going form B to C
	length[1] = sqrt(pow(c.getX() - b.getX(), 2) + pow(c.getY() - b.getY(), 2));

	//Going form C to D
	length[2] = sqrt(pow(d.getX() - c.getX(), 2) + pow(d.getY() - c.getY(), 2));

	//Going form D to A
	length[3] = sqrt(pow(a.getX() - d.getX(), 2) + pow(a.getY() - d.getY(), 2));

	for (i = 0; i < 4; i++)
	{
		perimeter += length[i];
	}

	return perimeter;
}

void Quadrilateral::print()
{
	gout << setPos(0, 400) << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  - - - - - - - - - - - - - " << endg;
	gout << setPos(200, 405) << "Shape info follows for: Quadrilateral" << endg;
	gout << setPos(200, 420) << "Point a: (" << a.getX() << "," << a.getY() << ")" << endg;
	gout << setPos(200, 435) << "Point b: (" << b.getX() << "," << b.getY() << ")" << endg;
	gout << setPos(200, 450) << "Point c: (" << c.getX() << "," << c.getY() << ")" << endg;
	gout << setPos(200, 465) << "Point d: (" << d.getX() << "," << d.getY() << ")" << endg;
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