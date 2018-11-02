/**
 AUTHOR: Vilia Wang
 FILENAME: SpasEnum.cpp
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
 emit() emits a variant of the encapsulated word. The variant returnted
 depends on the number of characters in the encapsulated word. If the
 encapsulated word is odd, then a truncated version of the encapword is
 emitted, by returning the first half of the encapsulated word. If the
 encapsulated word is even, then then encapsulated word plus the truncated
 version are contatenated and returned. For example, if encapWord is "hello"
 then "hellohel" will be returned.
 
 */

#include "SpasEnum.h"

SpasEnum::SpasEnum() {
    // ctor
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
