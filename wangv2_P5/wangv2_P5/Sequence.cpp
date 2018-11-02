//
//  Sequence.cpp
//  wangv2_P5
//
//  Created by VeeVee Wang on 12/7/17.
//  Copyright © 2017 VeeVee Wang. All rights reserved.
//

#include "Sequence.h"
#include <string>
#include <cstdlib>

using namespace std;

Sequence::Sequence() {
    encapWord = "";
    i = 0;
}

bool Sequence::isActive() {
    return encapWord != "";
}

bool Sequence::EnterWord(string input) {
    if (input.length() < MIN_WORD)
        return false;
    
    i = 0;
    encapWord = input;
    return true;
}

bool Sequence::isWord(string input) {
    if (input == encapWord) {
        encapWord = "";
        i = 0;
        return true;
    }
    return false;
}

string Sequence::getInvertWord() {
    string invertWord = encapWord;
    
    swap(invertWord[i], invertWord[i+1]);
    return invertWord;
}

