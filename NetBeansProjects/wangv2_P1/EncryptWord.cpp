// AUTHOR: Vilia Wang
// FILENAME: p1.cpp
// DATE: Created on September 25, 2017, 12:47 PM
// REVISION HISTORY: None
// 
// Assumptions: The constructor initializes all class fields for the start of
//              a new game.
//              getEncryptWord takes a valid word as a parameter in order 
//              to encrypt and return it. The game is turned 'on' once this 
//              method is called because the user can start guessing shift 
//              values once a word has been encrypted.  
//              isShift takes a int as a parameter, which should represent the
//              user's guessed shift value. The parameter must be an int in 
//              order to compare it to the shift value. This method can only be
//              called when the game is 'on'/after getEncryptWord is called, 
//              because a word must be encrypted before one can guess the shift
//              value. 
//              isOn checks the state of the object. When the object is 'on'
//              this means a word has been an encrypted and the user can 
//              begin to guess the shift size. This method is to ensure that 
//              the user does not start guessing before a word has been 
//              encrypted.
//              isOff also checks the state of the object. When the object is
//              'off' this means the correct shift value has been guessed. 
//              This allows one to know when a round is over. 
//              The reset method resets the appropriate class fields for the
//              start of a new round in the game. 
//              getTotal, getLow, getHigh, getReset, and getAverage are 
//              implemented so statistics from each round can be retrieved. 

#include "EncryptWord.h"

EncryptWord::EncryptWord() {
    this->shift = 0;
    this->total = 0; 
    this->low = 0; 
    this->high = 0;
    this->average = 0;
    this->on = false; 
    this->off = true; 
}

string EncryptWord::getEncryptWord(string s) {
    on = true; 
    return cipherShift(s);
}

bool EncryptWord::isShift(int guess) {
    updateStats(guess);
    if (guess == shift)
        off = true; 
    return guess == shift; 
}

bool EncryptWord::isOn() const {
    return on; 
}

bool EncryptWord::isOff() const {
    return off; 
}

void EncryptWord::reset() {
    shift = (rand() % MAX_RAND) + MIN_RAND;
    this->total = 0; 
    on = false; 
    off = true; 
}

int EncryptWord::getTotal() const { 
    return total; 
}

int EncryptWord::getLow() const {
    return low; 
}

int EncryptWord::getHigh() const {
    return high; 
}

double EncryptWord::getAverage() const {
    return average / total;
}


// PRIVATE 
string EncryptWord::cipherShift(string s) {
    for (unsigned i = 0; i < s.size(); i++) {
        int code = (int)s[i];
        int newUnicode = (code + shift - MIN_LETTERS) 
                       % TOTAL_LETTERS + MIN_LETTERS;
        s[i] = (char)newUnicode;
    }
    return s;
}

void EncryptWord::updateStats(int guess) {
    this->total++; 
    if (guess < shift)
        this->low++;
    if (guess > shift)
        this->high++;
    this->average = (average + guess); 
}


