/**
 AUTHOR: Vilia Wang
 FILENAME: SequenceEnum.cpp
 DATE: Created by VeeVee Wang on 11/5/17
 VERSION: 1
 REVISION: None
 
 DESCRIPTION:
- Covered in .h file
 
 ASSUMPTIONS:
 - Interface:
 The user must check the state before using all methods to ensure pre and
 post conditions are met. State must be checked before calling
 enterWord(string), emit(), and isWord(string).
 
 - Constructors:
 The no-arg constructor takes no arguments and puts the object in a valid
 initial state where isActive is false - meaning the encapsulated word has not
 been set yet.
 
 - State transitions:
 The constructor sets the state to inactive. Once a word is successfully set
 to the encapsulted word, the state is active. In order to successfully
 set the encapsulted word, the input must be at least 3 characters long. The
 state will transition to inactive, once the encapsulated word is guessed
 correctly.
 
 - Implementation invariants:
 emit() emits a variant of the encapsulated word. The variant returnted is the
 encapsulated word plus the last letter. (For example, rad -> radd).
 enterWord(string) only returns true and sets the encapsulated word if the
 input is at least 3 characters long.
 
 */

#include "SequenceEnum.h"

SequenceEnum::SequenceEnum() {
    encapWord = "";
}

bool SequenceEnum::isActive() {
    return encapWord != "";
}

bool SequenceEnum::enterWord(string input) {
    if (input.length() < MIN_WORD_SIZE)
        return false;
    
    encapWord = input;
    return true;
}

string SequenceEnum::emit() {
    return (encapWord + encapWord[encapWord.length() - 1]);
}

bool SequenceEnum::isWord(string input) {
    if (input == encapWord) {
        encapWord = "";     // resets state when word is guessed correctly
        return true;
    }
    return false;
}
