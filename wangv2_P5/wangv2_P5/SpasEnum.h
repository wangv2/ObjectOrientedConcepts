//
//  SpasEnum.h
//  wangv2_P5
//
//  Created by VeeVee Wang on 12/7/17.
//  Copyright © 2017 VeeVee Wang. All rights reserved.
//

#ifndef SpasEnum_hpp
#define SpasEnum_hpp

#include <stdio.h>
#include "Sequence.h"

class SpasEnum: public Sequence {
public:
    SpasEnum();
    virtual string emit();
    
};
#endif /* SpasEnum_h */
