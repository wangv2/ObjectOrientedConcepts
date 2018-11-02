/* 
 * AUTHOR: Vilia Wang
 * FILENAME: FindFault.cpp
 * DATE: Created on October 6, 2017, 2:07 PM
 * REVISON HISTORY: Edited 23 October 2017
 * REFERENCES: None. 
 */

/*
 * DESCRIPTION: 
 * - Covered in the "FindFault.h" file.
 *
 * 
 * ASSUMPTIONS: 
 * - The constructor takes no arguments. The ctor holds several, distinct
 * EncryptWord objects. The array size is arbitrarily and statically
 * set to 5 for testing purposes.
 * 
 * - getSize() and getCapacity() should be used to check "fullness" of the 
 * array before the insert(string) method is called. This check is intended to
 * make sure that no additional words are inserted once the array is full. If
 * the size is less than the capacity, the insert method can be used. If the
 * size is greater than or equal to capacity, no more words can be inserted.
 * 
 * - The insert(string) function takes a valid string as input. insert(string) 
 * calls a private flipCoin() method to determine the result of the string. 
 * Heads indicates a regularly encrypted word and tails indicates a corrupted 
 * word. Once this method is called, the index at which the string was inserted
 * is considered "occupied".
 * 
 * - isOccupied should be used for all methods that have an integer parameter 
 * that represents an index in the array. This method is designed to check 
 * the state of the EncryptedWord object to see if it contains an encrypted 
 * word. getWord(int), getDecodedWord(int) and isCorrupt(int, bool) methods 
 * should be preceeded with isOccupted() to check state. This methods returns
 * true if it is occupied and false if it is unoccupied.
 * 
 * - getWord(int) will either return an regularly encrypted word or a corrupted 
 * word.
 * 
 * - getDecodedWord(int) is a getter for the decoded word, which is defined as 
 * the original word before encryption or corruption. The word is returned as 
 * a string. 
 * 
 * - isCorrupt(int, bool) is used to query if a word is corrupt or not. 
 * isOccupied must be called before using this method to determine if the 
 * index is in fact occupied (because a guess cannot be made unless a word
 * has been inserted).
 *
 * - getWord(int), getDecodedWord(int), and isCorrupt(int, bool) should all
 * have matching integer arguments when they are called. The integer argument
 * must start at zero and for each word that is inserted, the value will
 * increment until the capacity is reached. For example, the when the first
 * word is inserted, these 3 methods should be called with zero as the
 * integer argument. When the second word is inserted, these three methods,
 * should be called with 1 as the arguement, and so on until the capacity is
 * reached, meaning no more words can be inserted.
 *
 * - The copy constructor takes an exisiting FF object as a parameter and
 * creates a new FF object that is identical to the parameter object. The
 * parameter object's fields are copied into the new object.
 *
 * - The overloaded assigment operator takes an existing FF object as a
 * parameter and makes the calling object identical to the parameter object.
 * The parameter's object's fields are copied into the calling object's fields.
 *
 * - testGetShiftCode(int) is to be used for testing purposes only. This method
 * is for the programmer design to check that shift codes are properly
 * manipulated after addition and subtraction.
 * 
 * - Implementation invariants: 
 * getSize(), getCapacity, and isOccupied() exist to check the state of the 
 * object at any given time. These methods are important when state must be 
 * checked before another function is used. 
 * This class does not perform input validation that checks if an index 
 * represents a valid index in the arrays. 
 * Private flipCoin() and corruptWord(string) methods exist to produce random 
 * outputs for their given purpose. 
 * Ownership of statistics belong to the FindFault class. 
 * FindFault encapsulates EncryptWord objects and they have a has-a 
 * relationship. EncryptWord's internal state affects FindFault.
 * legal string values must not have spaces, uppercase letters or symbols, or 
 * else the program will behave unexpectedly.  
 */

#include "EncryptWord.h"
#include "FindFault.h"

FindFault::FindFault() {
    this->size = 0;
    this->totalCorrupt = 0; 
    this->totalEncrypted = 0;
    this->totalCorrect = 0;
}

bool FindFault::insert(string word) {
    // if the array is full, return false
    if (size >= CAPACITY)
        return false;
    
    // when the array in not full, return true
    // first, get encrypted word from EncryptWord object
    string encryptedWord = array[size].getEncryptWord(word);
    
    // second, flip the coin to determine corruption or not
    // heads means do NOT corrupt word 
    if (flipCoin() == "heads") {
        totalEncrypted++;
        encodedWord = encryptedWord;
        stringArr[size] = encodedWord;
    }
    
    // tails means DO corrupt the word 
    else {
        totalCorrupt++;
        encodedWord = corruptWord(encryptedWord, size);
        stringArr[size] = encodedWord;
    }
    
    // third, increment size and return true
    size++;           
    return true; 
}

string FindFault::getEncodedWord(int index) {
    return stringArr[index];
}

string FindFault::getDecodedWord(int index) {
    // when the index is NOT occupied, return an empty string
    if (!isOccupied(index))
        return "";
    // when the index IS occupied, return the decoded word
    return array[index].getDecryptWord();
}

int FindFault::getSize() const {
    return size;
}

int FindFault::getCapacity() const {
    return CAPACITY;
}

bool FindFault::isOccupied(int index) {
    if (array[index].isOn())
        return true; 
    return false; 
}

bool FindFault::isCorrupt(int index, bool corruptGuess) {
    // if word is NOT corrupt
    if (encodedWord == array[index].getShiftWord()) {
        // the user guesses that the word IS corrupt, they are incorrect
        if (corruptGuess == true)
            return false;
        // the user guesses that the word is NOT corrupt, they are correct
        return true;
    }
    
    // if the word is corrupt
    else {
        // the user guesses that the word IS corrupt, they are correct
        if (corruptGuess == true)
            return true;
        // the user guesses that the word is NOT corrupt, they are incorrect
        return false;
    }
}

int FindFault::getTotalCorrupt() const {
    return totalCorrupt;
}

int FindFault::getTotalEncrypted() const {
    return totalEncrypted; 
}

int FindFault::getTotalCorrectQueries() const {
    return totalCorrect;
}

void FindFault::incrementTotalCorrect() {
    totalCorrect++;
}

// for testing purposes only
int FindFault::testGetShiftCode(int index) {
    return array[index].testGetShift();
}

// copy constructor
FindFault::FindFault(const FindFault& obj) {
    size = obj.size;
    totalCorrupt = obj.totalCorrupt;
    totalEncrypted = obj.totalEncrypted;
    totalCorrect = obj.totalCorrect;
    
    for (int i = 0; i < CAPACITY; i++) {
        array[i] = obj.array[i];
        stringArr[i] = obj.stringArr[i];
    }
}

// overloaded assignemnt operator
FindFault& FindFault::operator= (const FindFault& obj) {
    if (this != &obj) {
        size = obj.size;
        totalCorrupt = obj.totalCorrupt;
        totalEncrypted = obj.totalEncrypted;
        totalCorrect = obj.totalCorrect;
        for (int i = 0; i < CAPACITY; i++) {
            array[i] = obj.array[i];
            stringArr[i] = obj.stringArr[i];
        }
    }
    return *this;
}

// overloaded + operator
FindFault FindFault::operator+ (const FindFault& obj) {
    FindFault temp;
    for (int i = 0; i < CAPACITY; i++) {
        temp.array[i] = array[i] + obj.array[i];
    }
    return temp;
}

// overloaded - operator
FindFault FindFault::operator- (const FindFault& obj) {
    FindFault temp;
    for (int i = 0; i < CAPACITY; i++) {
        temp.array[i] = array[i] - obj.array[i];
    }
    return temp;
}

// overloaded == operator
bool FindFault::operator== (const FindFault& object) {
    for (int i = 0; i < CAPACITY; i++) {
        if (array[i].getShiftWord() != object.array[i].getShiftWord()) {
            return false;
        }
    }
    return true;
}

// overloaded != operator
bool FindFault::operator!= (const FindFault& object) {
    for (int i = 0; i < CAPACITY; i++) {
        if (array[i].getShiftWord() != object.array[i].getShiftWord()) {
            return true;
        }
    }
    return false;
}

// private methods
string FindFault::flipCoin() {
    int totalSizeOnCoin = 2;        // represents number of sides on a coin
    
    int num = rand() % totalSizeOnCoin;
    if (num == 0)
        return "heads";
    return "tails";
}

string FindFault::corruptWord(string word, int index) {
    int newCode = 120;                         // holds the new ascii value of
                                               // the corruption
    
    string corruptWord = word;                 // holds new corrupt word
    
    int location = rand() % word.length() - 1; // location in corruptWord that
                                               // will be corrupted
    
    corruptWord[location] = (char)newCode;     // insert corruption
    return corruptWord;
}
