//
//  SeqExtract.h
//  wangv2_P5
//
//  Created by VeeVee Wang on 12/7/17.
//  Copyright © 2017 VeeVee Wang. All rights reserved.
//

#ifndef SeqExtract_hpp
#define SeqExtract_hpp

#include <stdio.h>
#include <string>
#include "Sequence.h"

using namespace std;

class SeqExtract:public Sequence {
public:
    SeqExtract();
    virtual string emit();
    string emit(string);
    
};

#endif /* SeqExtract_h */
