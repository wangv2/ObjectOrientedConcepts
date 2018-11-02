//
//  SequenceEnum.h
//  wangv2_P5
//
//  Created by VeeVee Wang on 12/7/17.
//  Copyright © 2017 VeeVee Wang. All rights reserved.
//

#ifndef SequenceEnum_hpp
#define SequenceEnum_hpp

#include <string>
#include <stdio.h>
#include <iostream>
#include "Sequence.h"

using namespace std;

class SequenceEnum:public Sequence {
public:
    SequenceEnum();
    virtual string emit();
};

#endif /* SequenceEnum_h */
