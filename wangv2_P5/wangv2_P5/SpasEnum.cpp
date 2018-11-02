//
//  SpasEnum.cpp
//  wangv2_P5
//
//  Created by VeeVee Wang on 12/7/17.
//  Copyright © 2017 VeeVee Wang. All rights reserved.
//

#include "SpasEnum.h"

SpasEnum::SpasEnum() {
    
}

string SpasEnum::emit() {
    string newWord = "";    // holds the word variants to emit
    
    for (unsigned i = 0; i < (encapWord.length() / 2); i++)
        newWord += encapWord[i];
    
    // if word length is even, newWord added to internal subsequence
    if (encapWord.length() % 2 == 0)
        newWord = encapWord + newWord;
    
    return newWord;
}
