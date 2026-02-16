//NhanBui
// Lab10out
//Program to show Inheritance

#include <iostream>
#include "Shape.h"
#include "graph1.h"
#include "Color.h"

Shape::Shape()
{
	color.setColor(0, 0, 0);

}

Color Shape::getColor()
{
	return color;
}

void Shape::setCol(Color color)
{
	this->color.setColor(color.getRed(), color.getBlue(), color.getGreen());
}

