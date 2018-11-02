/**
 AUTHOR: Vilia Wang
 FILENAME: SeqExtract.h
 DATE: Created by VeeVee Wang on 11/5/17
 VERSION: 1
 REVISION: None
 
 DESCRIPTION:
 - Overview of class:
 SeqExtract is a child class of the SequenceEnum class. SeqExtact inherits
 methods that allow it to: encapsulated a word, check the state of the object,
 set the encapsulated word, and guess the encapsulated word. SeqExtact
 suppresses SequenceEnum's emit() method and uses entension to create a method
 for the user to input a proffer word, and returns a variant.
 
 - Functionality:
 The ctor puts the object in a valid initial state where isActive is false.
 isActive() should be used to check the state of the object (whether a word
 is encapsulated or not encapsulated)
 enterWord(string) should be used to set the encapsulated word. The method will
 return true if the word was set and or false if word was not set.
 emit(string) takes a proffer word as string input. The input must match the
 beginning of the encapsulated word in order to return a proper string. If the
 input does not match beginning of the encapsulated word, an error message will
 be returned instead.
 isWord(string) should be used to guess the encapsulated word. Returns true if
 the guess is correct, and false for incorrect guesses. 
 
 - Legal states:
 The object can either be active or not active. Active means that a word is
 encapsulated. Not active means that a word is not encapsulated yet.
 
 - Dependencies:
 enterWord(string), emit(string) and isWord(string) depend on object's state.
 isActive must be false in order to use enterWord(string).
 isActive must be true in order to use emit(string).
 isActive must be true in order to use isWord(string).
 
 - Anticipated use:
 The class methods are meant to be used in the following flow:
 constructor -> isActive (will be false) -> enterWord(string) ->
 (if enterWord(string) returns false, keep using enterWord(string) until it
 returns true) -> isActive (check state, must be true to proceed) ->
 emit(string) -> isWord(string)
 
 - Data processed:
 enterWord(string), isWord(string), and emit(string) take in string inputs.
 enterWord(string) take the input and sets it to the encapsulated word if the
 input has at least 3 characters. If the input has less than 3 characters,
 the method does not set the encapsulated word.
 isWord(string) compares the string input to the encapsulated word to check if
 they are the same of different.
 emit(string) takes the input and compares it to the encapsulated word. If the
 input matches the beginning of the encapsulated word, a subsequent is
 returned. If the input does not match the beginning of the word, an error
 message is returned.
 
 - Legal input:
 String input must be english, alphabet characters. For emit(string), the
 string input must match the beginning of the encapsulated word. For example,
 if "evening" is encapsulated, input can be "e", "ev", "eve", "evening", etc.
 
 - Illegal input:
 String input should not include spaces, tabs, numbers, symbols, or non-english
 characters. For emit(string), illegal input does not match the beginning of
 the encapsulated word. For example, if "evening" is encapsulated, illegal
 input would include, "ning", "a", "zevening", "3242", etc.
 
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
 isActive sould be true before using emit(string) and isWord(string).
 A word will only be encapsulated if it is at least three characters long.
 Once the word is guessed correctly, the encapsulated word resets and the
 object is inactive.
 Copy constructor and overloaded assignment operator suppressed.
 
 - Class invariants:
  SeqExtract is a child class of SequenceEnum.
  Proper usage of class depends on state of object.
 */

#ifndef SeqExtract_h
#define SeqExtract_h

#include <stdio.h>
#include <string>
#include "SequenceEnum.h"

using namespace std;

class SeqExtract : public SequenceEnum {
public:
    SeqExtract();
    // description: The constructor
    // precondition: None
    // postcondition: Puts objects in a valid initial state, where isActive
    // is false.
    
    string emit(string);
    // description: Returns a variant of encapWord. Accepts a proffer word and
    // returns the encapWord minus proffer word (ex: encapWord = evening, and
    // "eve" is proffered, "ning" will be returned). If the input is equal to
    // encapWord, an empty string will be returned. The proffer word must match
    // the beginning of the encapWord. If the proffer word does not match the
    // beginning of encapWord, the error message "Proffer does not match" will
    // be returned.
    // precondition: isActive must be true
    // postcondition: isActive is true

private:
    string emit();                      // suppress SequenceEnum emit() method
    SeqExtract(const SeqExtract&);             // suppress copy ctor
    SeqExtract& operator= (const SeqExtract&); // suppress overloaded =
};

#endif /* SeqExtract_h */
