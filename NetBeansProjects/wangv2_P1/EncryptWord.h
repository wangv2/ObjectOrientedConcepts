// AUTHOR: Vilia Wang
// FILENAME: p1.cpp
// DATE: Created on September 25, 2017, 12:47 PM
// REVISION HISTORY: None
//
// Description: This class provides methods for a Caesar cipher shift game,
//              that includes the following public methods: 
//              EncryptWord() is the no-arg constructor that initializes all 
//              class fields for the start of a new game.
//
//              getEncryptWord(string) turns the game 'on' and returns an 
//              encrypted word. Has a string parameter whose legal input must 
//              only include lowercase, alphabet characters with no spaces.
//
//              isShift() checks if the parameter guess value matches the 
//              shift size and is turned 'off' when guess is correct. This
//              method can only be called after getEncryptWord has been called 
//              correctly. Has an int parameter for a shift guess. 
//
//              isOn() checks the state of the 'on' object. Is dependent on the 
//              getEncryptWord method and is only true after this method is
//              called. 
//
//              isOff() checks the state of the 'off' object. Is dependent on 
//              the isShift method and is only true after this method is called
//
//              reset() properly resets appropriate fields for a new game. Must
//              be called at the beginning of new games and rounds. 
//
//              getTotal(), getLow(), getHigh(), and getAverage()  are getters 
//              that return game statistics. All these functions return ints, 
//              except getAverage() which returns a double.
//
// Assumptions: There is only one constructor and it takes no arguments. 
//              The reset method must be called at the beginning of each new 
//              game round in order to properly set fields. 
//              The getEncryptWord method assumes the string input consists of
//              only lowercase, alphabet letters with no spaces. This method  
//              also changes the state of the program to 'on'.
//              The isShift method can only be called after a word has been 
//              encrypted with the getEncryptWord method. To check whether
//              a word has been encrypted, users should use the isOn method.
//              This method also changes the state of the program to 'off'
//              once the correct shift value is guessed. 
//              isOn means that a word has been encrypted and a user can now
//              call the isShift method to guess the shift value. 
//              isOff means that the encrypted word's shift value has been 
//              guessed correctly. 

#ifndef NEWENCRYPTWORD_H
#define NEWENCRYPTWORD_H

#include <string>
#include <cstdlib>
#include <iostream>

using namespace std;

class EncryptWord {
public:
    // description: The no-argument constructor for new EncryptWord objects 
    //              that initializes class fields for the start of game. 
    EncryptWord();  
    
    // description: Takes a valid word(string) to encrypt as an argument. Turns 
    //              the game on and returns an encrypted word as a string. 
    string getEncryptWord(string);
    
    // description: Should only be called if game is on (word is encrypted).
    //              Takes a shift guess(int) as an argument. Updates statistics 
    //              and returns true if guess is correct, and false otherwise. 
    //              If the guess is correct, the game is turned off. 
    bool isShift(int);
    
    // description: Checks state of the object. Returns true if it is on, and
    //              false otherwise. The game is on, once a word is encrypted.
    bool isOn() const;
    
    // description: Checks state of the object. Returns true if it is off, and
    //              false otherwise. The game turns off when the correct shift
    //              size is guessed. 
    bool isOff() const;
    
    // description: Resets the object for a new round of the game, by 
    //              initializing variables for the start.
    void reset();
    
    // description: A getter for the 'total' variable. Describes the number of
    //              guesses it took to correctly guess a cipher shift. 
    int getTotal() const;
    
    // description: A getter for the 'low' variable. Describes the number of 
    //              times the guess was lower than the shift value. 
    int getLow() const;
    
    // description: A getter for the 'high' variable. Describes the number of 
    //              times the guess was higher than the shift value. 
    int getHigh() const;
    
    // description: A getter for the 'average' variable. Describes the 
    //              average guess value per round. 
    double getAverage() const;

private:
    int shift, total, low, high;    // describes the shift size and statistics
    double average;                 // describes the average guess value 
    bool on, off;                   // describes the state of the object 
    const int MIN_RAND = 1;         // minimum random number 
    const int MAX_RAND = 25;        // maximum random number
    const int MIN_LETTERS = 97;     // minimum ASCII value 
    const int TOTAL_LETTERS = 26;   // total letters of alphabet
    
    string cipherShift(string);     // returns encrypted word
    void updateStats(int);          // updates statistics 
};

#endif /* ENCRYPTWORD_H */




