//
//  Sequence.h
//  wangv2_P5
//
//  Created by VeeVee Wang on 12/7/17.
//  Copyright © 2017 VeeVee Wang. All rights reserved.
//

#ifndef Sequence_h
#define Sequence_h

#include <string>
#include <stdio.h>
#include "Inverter.h"

using namespace std;

class Sequence: public Inverter {
private:
    unsigned MIN_WORD = 3;
    
protected:
    string encapWord;
    unsigned i = 0;
    
public:
    Sequence();
    bool isActive();
    bool EnterWord(string);
    bool isWord(string);
    string getInvertWord();
    virtual string emit() = 0;
};

#endif /* Sequence_h */
