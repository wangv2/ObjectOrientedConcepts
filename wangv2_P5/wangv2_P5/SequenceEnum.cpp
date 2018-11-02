//
//  SequenceEnum.cpp
//  wangv2_P5
//
//  Created by VeeVee Wang on 12/7/17.
//  Copyright © 2017 VeeVee Wang. All rights reserved.
//

#include "SequenceEnum.h"

SequenceEnum::SequenceEnum() {
    
}

string SequenceEnum::emit() {
    return encapWord + encapWord[(encapWord.length() - 1)];
}
