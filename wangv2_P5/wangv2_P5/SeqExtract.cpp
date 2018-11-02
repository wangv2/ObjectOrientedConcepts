//
//  SeqExtract.cpp
//  wangv2_P5
//
//  Created by VeeVee Wang on 12/7/17.
//  Copyright © 2017 VeeVee Wang. All rights reserved.
//

#include "SeqExtract.h"

SeqExtract::SeqExtract() {
    
}

string SeqExtract::emit() {
    return encapWord + encapWord[(encapWord.length() - 1)];
}

string SeqExtract::emit(string input) {
    int counter = -1;           // counter to track what to return
    string newWord = "";        // holds the newWord to emit
    string errorMessage = "Proffer does not match";
    
    for (unsigned i = 0; i < input.length(); i++) {
        counter++;
        if (input[i] != encapWord[i])
            return errorMessage;
    }
    
    for (unsigned i = (counter + 1); i < encapWord.length(); i++)
        newWord += encapWord[i];
    
    return newWord;
}

