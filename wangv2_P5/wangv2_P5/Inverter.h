//
//  Inverter.h
//  wangv2_P5
//
//  Created by VeeVee Wang on 12/7/17.
//  Copyright © 2017 VeeVee Wang. All rights reserved.
//

#ifndef Inverter_h
#define Inverter_h

#include <stdio.h>
#include <string>

using namespace std;

class Inverter {
public:
    Inverter();
    virtual string getInvertWord() = 0;
};

#endif /* Inverter_h */
