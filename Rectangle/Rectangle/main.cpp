//
//  main.cpp
//  Rectangle
//
//  Created by VeeVee Wang on 10/25/17.
//  Copyright © 2017 VeeVee Wang. All rights reserved.
//

#include "Rectangle.h"
#include <iostream>

using namespace std;

void print(Rectangle &);

int main()
{
    Rectangle r(5.2, 3.8);
    print(r);
    
    Rectangle r2;
    print(r2);
    
    Rectangle r3(7.4);
    print(r3);
    
    return 0;
}

void print(Rectangle &r)
{
    cout << "width: " << r.getWidth() << ", ";
    cout << "length: " << r.getLength() << endl;
}
