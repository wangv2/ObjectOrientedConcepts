/**
 AUTHOR: Vilia Wang
 FILENAME: SeqExtract.cpp
 DATE: Created by VeeVee Wang on 11/5/17
 VERSION: 1
 REVISION: None
 
 DESCRIPTION:
 - Covered in .h file
 
 ASSUMPTIONS:
 - Interface:
 The user must check the state before using all methods to ensure pre and
 post conditions are met. State must be checked before calling
 enterWord(string), emit(string), and isWord(string).
 
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
 SeqExtract suppresses the inherieted emit() function. SeqExtract uses
 extension to create a new function called emit(string). emit(string) takes a
 string input, and if the input matches the beinning of the encapsulated word
 the remainder is returned. For example, if "evening" is encapsulated, and
 "eve" is inputted, then "ning" will be returned. If the entire encapsulated
 word is inputted, an empty string will be returned. If the input does not
 match the beginning of the word then the error message, "Proffer does not
 match" will be returned as a string.
 
 */

#include "SeqExtract.h"

SeqExtract::SeqExtract() {
    // ctor
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
