//
//  Rectangle.hpp
//  Rectangle
//
//  Created by VeeVee Wang on 10/25/17.
//  Copyright © 2017 VeeVee Wang. All rights reserved.
//

#ifndef Rectangle_hpp
#define Rectangle_hpp

#include <stdio.h>

class Rectangle
{
private:
    double length;
    double width;
public:
    Rectangle(double = 1.0, double = 1.0);
    double getLength() const;
    double getWidth() const;
    void setLength(double);
    void setWidth(double);
};

#endif /* Rectangle_hpp */
