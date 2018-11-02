/**
 AUTHOR: Vilia Wang
 FILENAME: SequenceEnum.h
 DATE: Created by VeeVee Wang on 11/5/17
 VERSION: 1
 REVISION: None
 
 DESCRIPTION:
 - Overview of class:
 SequenceEnum encapsulates a word that is at least 3 letters long. Users can
 check the state of the class to see if a word is encapsulated or not. Users
 may also set the encapsulated word, retrieve a variant of the word, and guess
 the encapsulated word.
 
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
 Proper usage of class depends on state of object.

*/

#ifndef SequenceEnum_h
#define SequenceEnum_h

#include <stdio.h>
#include <string>

using namespace std;

class SequenceEnum {
public:
    SequenceEnum();
    // description: The constructor
    // precondition: None
    // postcondition: Object in valid initial state where isActive is false
    
    bool isActive();
    // description: To check the state of the object. Returns true if isActive
    // is true (encapWord != "") and returns false if isActive is false
    // (encapWord == "").
    // precondition: None
    // postcondition: None
    
    bool enterWord(string);
    // description: If the string input is at least 3 characters long, this
    // setter will set encapWord and return true. But if the string input is
    // less than 3 characters, encapWord will not be set, and returns false.
    // precondition: isActive must be false
    // postcondition: isActive may be true or may be false (depending on input
    // length)
    
    string emit();
    // description: Returns a variant of encapWord. encapWord is returned with
    // an extra letter tacked to the end of the word.
    // precondition: isActive is true
    // postcondition: isActive is true
    
    bool isWord(string);
    // description: Guessing method takes a string input as a guess and returns
    // true if guess matches encapWord. Return false if guess does not match
    // encapWord. Once the guess matches encapWord, state is reset so that
    // isActive is false
    // precondition: isActive is true
    // postcondition: isActive may be true or may be false
    
protected: 
    string encapWord;                       // encapsulated word
    static const int MIN_WORD_SIZE = 3;     // minimum input word size
    
private:
    SequenceEnum(const SequenceEnum&);             // suppress copy ctor
    SequenceEnum& operator= (const SequenceEnum&); // suppress overloaded =
};

#endif /* SequenceEnum_h */
