/**
 AUTHOR: Vilia Wang
 FILENAME: SpasEnum.h
 DATE: Created by VeeVee Wang on 11/5/17
 VERSION: 1
 REVISION: None
 
 DESCRIPTION:
 - Overview of class:
 SpasEnum is a child class of the SequenceEnum class. SpasEnum inherits
 methods that allow it to: encapsulated a word, check the state of the object,
 set the encapsulated word, and guess the encapsulated word. SpasEnum
 overrides SequenceEnum's emit() method and implements a specialized version of
 the emit funtion that returns a variant of the encapsulted word.
 
 - Functionality:
 The ctor puts the object in a valid initial state where isActive is false.
 isActive() should be used to check the state of the object (whether a word
 is encapsulated or not encapsulated)
 enterWord(string) should be used to set the encapsulated word. The method will
 return true if the word was set and or false if word was not set.
 emit() returns a variant of the encapsulated word.
 isWord(string) should be used to guess the encapsulated word. Returns true if
 the guess is correct, and false for incorrect guesses. 
 
 - Legal states
 The object can either be active or not active. Active means that a word is
 encapsulated. Not active means that a word is not encapsulated yet.
 
 - Dependencies:
 enterWord(string), emit() and isWord(string) depend on the object's state.
 isActive must be false in order to use enterWord(string).
 isActive must be true in order to use emit().
 isActive must be true in order to use isWord(string).
 
 - Anticipated use:
 The class methods are meant to be used in the following flow:
 constructor -> isActive (will be false) -> enterWord(string) ->
 (if enterWord(string) returns false, keep using enterWord(string) until it
 returns true) -> isActive (check state, must be true to proceed) -> emit() ->
 isWord(string)
 
 - Data processed:
 enterWord(string) and isWord(string) take in string inputs.
 enterWord(string) take the input and sets it to the encapsulated word if the
 input has at least 3 characters. If the input has less than 3 characters,
 the method does not set the encapsulated word.
 isWord(string) compares the string input to the encapsulated word to check if
 they are the same of different.
 
 - Legal input:
 String input must be english, alphabet characters.
 
 - Illegal input:
 String input should not include spaces, tabs, numbers, symbols, or non-english
 characters.
 
 - Output:
 The output will either be void, boolean, or string.
 
 
 ASSUMPTIONS:
 - Interface:
 The user should check the state of the object (isActive) before using methods.
 
 - Constructors:
 The constructor takes no arugments and set the object to a valid intital state
 where isActive is false - meaning a word is not encapsulated.
 
 - State transitions:
 The state will transition between active and not active. Once the object is
 created isActive is false. Once a word is successfully encapsulated, isActive
 is true. Once the user correctly guesses the encapsulatd word, isActive
 becomes false.
 
 - Interface invariants:
 State must be checked before using anything methods.
 isActive should be false before using enterWord(string).
 isActive sould be true before using emit() and isWord(string).
 A word will only be encapsulated if it is at least three characters long.
 Once the word is guessed correctly, the encapsulated word resets and the
 object is inactive.
 Copy constructor and overloaded assignment operator suppressed.
 
 - Class invariants:
 SeqExtract is a child class of SequenceEnum.
 Proper usage of class depends on state of object.
 
 */

#ifndef SpasEnum_h
#define SpasEnum_h

#include <stdio.h>
#include <string>
#include "SequenceEnum.h"

using namespace std;

class SpasEnum: public SequenceEnum {
    
public:
    SpasEnum();
    // description: The constructor
    // precondition: None
    // postcondition: Puts objects in a valid initial state
    
    string emit();
    // description: Returns a variant of encapWord. If encapWord has an odd
    // number of characters, a trucated version of encapWord will be returned.
    // If encapWord has an even number of characters, encapWord + truncated
    // encapWord will be returned.
    // precondition: isActive must be true
    // postcondition: isActive is true
    
private:
    SpasEnum(const SpasEnum&);             // suppress copy ctor
    SpasEnum& operator= (const SpasEnum&); // suppress overloaded =
};

#endif /* SpasEnum_h */
