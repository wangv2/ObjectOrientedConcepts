//
//  Rectangle.cpp
//  Rectangle
//
//  Created by VeeVee Wang on 10/25/17.
//  Copyright © 2017 VeeVee Wang. All rights reserved.
//

#include "Rectangle.h"

Rectangle::Rectangle(double width, double length)
{
    this->width = width;
    this->length = length;
}

double Rectangle::getLength() const
{
    return length;
}

double Rectangle::getWidth() const
{
    return width;
}

void Rectangle::setLength(double length)
{
    this->length = length;
}

void Rectangle::setWidth(double width)
{
    this->width = width;
}

