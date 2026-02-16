//NhanBui
//Lab10out

#include <iostream>
#include<math.h>
#include"graph1.h"
#include"Color.h"
#include"Triangle.h"
#include "RightTriangle.h"

using namespace std;

RightTriangle::RightTriangle()
{

}
RightTriangle::RightTriangle(GenPoint vertex, int height, int base, Color color)
{
	b.setPoint(vertex.getX(), vertex.getY() - base);
	c.setPoint(vertex.getX() + height, vertex.getY());

	Triangle::setPoints(vertex, b, c);

	Shape::setCol(color);
}
void RightTriangle::print()
{
	Triangle::print();
	gout << setPos(0, 15) << "Right Triangle" << endg;
}