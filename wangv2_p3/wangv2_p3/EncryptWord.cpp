// AUTHOR: Vilia Wang
// FILENAME: EncryptWord.cpp
// DATE: Created on September 25, 2017, 12:47 PM
// VERSION: 3
// REVISION HISTORY: Edited 5 September 2017, 23 October 2017
// 
// Description: Covered in the "EncryptWord.h" file. 
// Assumptions: - The no-arg constructor takes no arguments and initializes all
//                class fields for the start of a new game.
//              - The copy constructor takes an exisiting EW object as an
//                arugment and creates a new object as a copy of the argument.
//              - The testing constructor is used for testing purposes only in
//                in order to test the edge cases for addition and subtraction.
//                The AP should not use this method as it is only for the
//                program designer.
//              - The overloaded assigment operator take an existing EW object
//                as a parameter and sets the calling object equal to the
//                parameter object. This is a destructive method.
//              - The overloaded + and - operators add and subtract two
//                EW objects, respectively. The object's shift sizes are
//                manipulated during these operations. These functions are
//                non-destructive and return a new object with the appropriate
//                manipulaion.
//              - The overloaded >, <, ==, and != operators returns booleans
//                for their given comparison. These operators compare the shift
//                sizes of each object. These are non-destructive operators.
//              - The testGetShift() method is for testing purposes ONLY. Since
//                the overloaded operators manipulate shift size, this testing
//                method is to be used only test the overloaded methods and
//                their impact on shift size.
//              - getEncryptWord takes a valid word as a parameter in order 
//                to encrypt and return it. The state 'on' is true / 'off' is 
//                false once this method is called, signaling that a word has 
//                been encrypted.
//              - getDecryptWord returns the original word before encryption. 
//                Decoding is defined as returning the original word before 
//                encryption. 
//              - Once the game state 'on' is true and 'off' is false (meaning 
//                a word has been encrypted), the isShift method can be called.
//              - isShift takes a int as a parameter, which should represent 
//                a guess of the shift value. The parameter must be an int in 
//                order to compare it to the shift value.
//              - isOn and isOff check the state of the object. When 'on' is 
//                true and 'off' is false, this means a word has been encrypted 
//                and the user can begin to guess the shift size. These methods
//                ensure that the user does not start guessing the shift size 
//                before a word has been properly encrypted.
//              - The reset method resets the appropriate class fields for the
//                start of a new round in the game. It sets 'shift' to a new 
//                random value between 1-25 so the shift is at least 1 and not
//                greater than or equal to the size of the entire alphabet. 
//                Reset() also sets the legal states 'on' to false, and 'off' 
//                to true. 
//              - getTotal, getLow, getHigh, getReset, and getAverage are 
//                implemented so statistics from each round can be retrieved. 
// implementation 
// invariants:  - isOn and isOff exists to check state of object before and 
//                after a word is encrypted. 
//              - Doesn't perform input validation for parameters
//              - Private methods for cipher shift and shift size generator for
//                abstraction purposes. 
//              - ownerships of statistics belongs to the EncryptWord class 
//              - legal string values must not have spaces, uppercase letters, 
//                or symbols
//              - legal int values must not be non-integer values

#include "EncryptWord.h"

EncryptWord::EncryptWord() {
    this->shift = calculateShift();
    this->total = 0; 
    this->low = 0; 
    this->high = 0;
    this->average = 0;
    this->originalWord = "";
    this->shiftWord = "";
}

string EncryptWord::getEncryptWord(string s) {
    this->originalWord = s; 
    this->shiftWord = cipherShift(s);
    return shiftWord;
}

bool EncryptWord::isShift(int guess) {
    updateStats(guess);
    return guess == shift; 
}

bool EncryptWord::isOn() const {
    return originalWord != "";
}

bool EncryptWord::isOff() const {
    return originalWord == "";
}

void EncryptWord::reset() {
    this->shift = calculateShift();
    this->total = 0; 
    this->low = 0; 
    this->high = 0;
    this->average = 0;
    this->originalWord = "";
    this->shiftWord = "";
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
    if (total == 0)
        return 0;
    return average / total;
}

string EncryptWord::getDecryptWord() {
    return originalWord; 
}

string EncryptWord::getShiftWord() const {
    return shiftWord; 
}

// copy constructor
EncryptWord::EncryptWord(const EncryptWord& object) {
    shift = object.shift;
    total = object.total;
    low = object.low;
    high = object.high;
    average = object.average;
    originalWord = object.originalWord;
    shiftWord = object.shiftWord;
}

// overloaded assignment operator
EncryptWord& EncryptWord:: operator= (const EncryptWord& object) {
    if (this != &object) {
        shift = object.shift;
        total = object.total;
        low = object.low;
        high = object.high;
        average = object.average;
        originalWord = object.originalWord;
        shiftWord = object.shiftWord;
    }
    return *this;
}

// overloaded + operator
EncryptWord EncryptWord:: operator+ (const EncryptWord& object) {
    EncryptWord temp;
    temp.shift = shift + object.shift;
 
    if (temp.shift > 25 && temp.shift < 50)
        temp.shift = temp.shift % MAX_RAND;
    
    else if (temp.shift == 50)
        temp.shift = 25;
    
    
    return temp;
}

// overloaded - operator
EncryptWord EncryptWord:: operator- (const EncryptWord& object) {
    EncryptWord temp;
    temp.shift = shift - object.shift;
    
    if (temp.shift < 0 || temp.shift == 0)
        temp.shift = (temp.shift + MAX_RAND) % MAX_RAND + MIN_RAND;
    return temp;
}

// overloaded > operatorz
bool EncryptWord::operator> (const EncryptWord& object) {
    if (shift > object.shift)
        return true;
    return false;
}

// overloaded < operator
bool EncryptWord::operator< (const EncryptWord& object) {
    if (shift < object.shift)
        return true;
    return false;
}

// overloaded == operator
bool EncryptWord::operator== (const EncryptWord& object) {
    if (shift == object.shift)
        return true;
    return false;
}

// overloaded != operator
bool EncryptWord::operator!=(const EncryptWord& object) {
    if (shift != object.shift)
        return true;
    return false;
}

// FOR TESTING PURPOSES ONLY
int EncryptWord::testGetShift() {
    return shift;
}

// FOR TESTING PURPOSES ONLY
EncryptWord::EncryptWord(string word, int shiftSize) {
    shift = shiftSize;
    total = 0;
    low = 0;
    high = 0;
    average = 0;
    originalWord = word;
    shiftWord = getEncryptWord(originalWord);
}

// private methods 
string EncryptWord::cipherShift(string s) {
    for (unsigned i = 0; i < s.size(); i++) {
        int code = (int)s[i];
        //shift = calculateShift();
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

int EncryptWord::calculateShift() {
    srand((int) time(NULL));
    return (rand() % MAX_RAND) + MIN_RAND;
}
