// AUTHOR: Vilia Wang
// FILENAME: FindFault.h
// DATE: Created on October 6, 2017, 2:07 PM
// VERSION: 1
// REVISION HISTORY: None.

/*
 * DESCRIPTION:  
 * - Class overview: 
 * The FindFault class is a wrapper class that encapsulates and has-an array 
 * of EncryptWord classes. FindFault calls on EncryptWord's public methods to 
 * encrypt words and check the state. Words that are inserted, can be retrieved 
 * and will randomly return either correctly encrypted or corrupted. The 
 * FindFault class adds the notion of corruption by taking a correctly 
 * encrypted word and shifting one of its letters incorrectly. Users can use 
 * methods to find corrupt encryptions and to track statistics.
 * 
 * - Functionality: 
 * The no- arg constructor initializes class vairables into a valid state.
 * The insert method takes a string parameter. The result of a coin flip will 
 * determine if the string is only encrypted or encrypted and corrupted. Heads
 * means the word is encrypted only and the totalEncrypted variable is
 * incremented. Tails means the word is encrypted and corrupted, and the
 * totalCorrupted variable is incremented.
 * The getWord method takes an integer as a parameter which represents the 
 * index of the word that will be returned. 
 * isCorrupt allows the user to find corrupt words and takes an integer 
 * parameter (representing an index) and a bool (which represents the guess of 
 * if a word is corrupt or not). isCorrupt returns true is the guess is correct 
 * and false if incorrect. 
 * isOccupied checks the state of the EncryptWord object to see if it holds an
 * encrypted/corrupted word or not. It will return true if it holds a word
 * and false if it does not hold a word.
 * getCapacity and getSize can be used to check the state of the object. When
 * used together, these methods can check the fullness of the object.
 * incrementTotalCorrect is used when isCorrupt is true, in order to track
 * statistics.
 * getDecodedWord, getTotalCorrupt, getTotalEncrypted, and getTotalCorrect are
 * getters for statistics and the decoded word. 
 * 
 * - Legal states: 
 * The object's "size" can be retrieved with the getSize() function. And it
 * describes the current occupancy size in the array of EncryptWords.
 * The object's "capacity" can be retrieved with the getCapacity() function.
 * This represents the total number of EncryptWord objects.
 * The object can be "occupied" if it holds an encrypted word or not occupied
 * if has yet to hold an encrypted word. That is, when EncryptWord's state is
 * "on", meaning a word has been encrypted, that given EncryptWord is occupied.
 * However, if the EncryptWord's state is !on, it is considered not occupied.
 * The state of "fullness" can be checked with the getSize() and getCapacity() 
 * methods. If the size is less than the capacity than the array is not full. 
 * But if the size is greater than or equal to the capacity, it is full. 
 * 
 * - Dependencies: 
 * The FindFault class has-an EnryptWord object and is therefore dependent on
 * EncryptWord and its methods. The state of the internal object (EncryptWord)
 * affects the state of the external object (FindFault).
 * The insert method can only be called if the size is less than the capacity, 
 * meaning that the array in not full. Insert(string) is therefore dependent
 * on getSize() and getCapacity() to check the fullness of the array.
 * getWord can only be called with an integer parameter that has had a word 
 * passed into it. getWord is dependent on isOccupied() to check this state.
 * isCorrupt must have a valid integer parameter of an index that has had a 
 * word passed into it. isCorrupt is dependent on isOccupied() to check this
 * state.
 * getDecodedWord is dependant on isOccupied to check if there is word in the 
 * object to decode.
 * incrementTotalCorrect() and getTotalCorrectQueries() are dependant on the
 * isCorrupt(int, bool) method. When isCorrupt returns true,
 * incrementTotalCorrect() must be called in order to properly track
 * statistics.
 * 
 * - Anticipated use:
 * The class methods are intended to be used in the general following flow: 
 * FindFault() -> getSize() and getCapacity() -> if size is less than
 * capacity then -> insert(string) -> isOccupied(int) -> if a word is occupied
 * at the given index -> getWord(int) -> getDecodedWord(int) ->
 * isCorrupt(int, bool) -> if isCorrupt returns true -> incrementTotalCorrect()
 * -> call the getters for statistics
 * 
 * - Data processed: 
 * The insert method's string input is encrypted and possibly courrpted.
 * getWord and getDecodedWord integer parameters are processed to
 * retrieve a word at that given index. isCorrupt's integer parameter is used
 * to retrieve a specific EncryptWord object and the boolean parameter is
 * compared with a FindFault variable.
 * 
 * - Legal input: 
 * String input must have lowercase, alphabet characters only. 
 * Integer input that represents index, must be a valid index in the array. The
 * integer input must also represent an index that is occupied.
 * 
 * - Illegal input: 
 * String input cannot contain spaces, uppercase letters or symbols. 
 * Integer input cannot represent an invalid array index or an index that is 
 * not occupied (For isOccupied(), the integer does not need to be occupied).
 * 
 * - Output: 
 * Output is either void or an integer, boolean, or String type. 
 * 
 * 
 * ASSUMPTIONS: 
 * - Interface: FindFault is the public interface that has-an array of 
 * EncryptWord objects. EncryptWord's methods are not accessible by the user. 
 * Instead, the EncryptWord its methods are encapsulated, and called from
 * FindFault. Only FindFault's public methods are accessible to users.
 * 
 * - Constructor(s): 
 * There is only one constructor and it takes no arguments.
 * The constructor initializes class fields for the start of a new game
 * and allocates memory in the heap.
 * 
 * - State transitions:
 * the "size" starts at zero and is incremented each time a word is inserted. 
 * The state of "not full" (when size is less than capacity) transitions to 
 * "full" when the size becomes equal to the capacity, at which new words 
 * cannot be inserted in the array. 
 * A "not occupied" index does not contain an encrypted word (meaning 
 * insert(string) has not been used to fill that given space). This state 
 * transitions to "occupied" as soon as it contains an encrypted word. 
 * 
 * - Interface invariants: 
 * Only valid integer and string types must be passed into methods. 
 * Call by value not supported. 
 * Copying suppressed.
 * Overloaded assingment operator surpressed.
 * isOccupied() must be used to check the state of the object before calling 
 * isCorrupt(int, bool), getDecodedWord(int), and getWord(int). 
 * getSize() and getCapacity() must be used to check fullness of an object
 * before calling the insert(string) function. 
 */

#ifndef FINDFAULT_H
#define FINDFAULT_H

#include <string>
#include <cstdlib>
#include "EncryptWord.h"
#include <iostream> // delete later

using namespace std;

class FindFault {
public:
    FindFault();
    // description: The no-arg ctor creates an array of 5 EncryptWord
    // objects. The ctor also initializes class fields for that start of a new
    // game.
    // precondition: None. 
    // postcondition: The array is not full and no indexes are occupied. The
    // size is zero and the capacity is the equal to 5.

    bool insert(string);
    // description: Takes a string input which represents a word. It calls a 
    // private flipCoin() method that determines the word's encoding. The word
    // is encrypted and possibly corrupted. If heads is flipped the word is
    // encrypted only and the totalEncrypted variable is incremented. If tails
    // is flipped, the word is encrypted and corrupted, and the
    // totalCorrupt variable is incremented. The method will return true if the
    // word was successfully inserted, and false otherwise.
    // precondition: The object must NOT be full (size must be less than the 
    // capacity).
    // postcondition: The array size will increment if the word was 
    // successfully inserted. Either totalEncrypted or totalCorrupt will be
    // incremented for statistically purposes. The index at which the word
    // was inserted will be occupied if the word was successfully inserted.
    // The array may or may not be full.
    
    string getEncodedWord(int);
    // description: Takes an integer as a parameter and retrieves the 
    // corresponding encoded word in that array index. If the index is
    // not occupied, the function returns an empty string. 
    // precondition: The integer parameter must represent a valid array index
    // and that object should be occupied at the given index (isOccupied
    // must return true at the given index).
    // postcondition: None.
    
    string getDecodedWord(int);
    // description: A getter for the decoded word as a string (the word before
    // encryption or corruption). The integer parameter represents the index at
    // which the word will be returned. If that index does not contain a word,
    // an empty string will be returned.
    // precondition: The given index in the array must be occupied with an
    // encrypted word (isOccupied must return true at the given index).
    // postcondition: None.
    
    int getSize() const;
    // description: A getter for the current occupancy size in the array.
    // Represents the number of words that have been inserted into the array
    // at a given point in the time. When used with getCapacity(), it can
    // determine the object state of fullness.
    // precondition: None.
    // postcondition: None.
    
    int getCapacity() const;
    // description: A getter for the capacity of the array. Represents the
    // number of words that can be inserted into the array. When used with
    // getSize(), it can determine the object's state of fullness.
    // precondition: None.
    // postcondition: None.
    
    bool isOccupied(int);
    // description: Checks the state of an EncryptWord object at the integer
    // parameter index for occupation. If the EncryptWord object has an
    // encrypted word, this function returns true and, it returns false if it
    // doesn't have an encrypted word. This methods checks EncrptWord's state.
    // precondition: The integer parameter must represent a valid array index.
    // postcondition: None.
    
    bool isCorrupt(int, bool);
    // description: This method is used to find corrupted words. It takes an 
    // integer and boolean as parameters. The integer represents the index of 
    // the array for a specific word, and the boolean represents a guess of 
    // whether that word is corrupt or not. The method will return true if the
    // guess is correct and returns false is the guess is incorrect. 
    // precondition: The integer parameter must represent a valid array index
    // and that object should be occupied (isOccupied should be true).
    // postcondition: None.
    
    int getTotalCorrupt() const;
    // description: A getter for the total number of words that were corrupted. 
    // precondition: None. 
    // postcondition: None. 
    
    int getTotalEncrypted() const;
    // description: A getter for the total number of words there were not 
    // corrupted. 
    // precondition: None. 
    // postcondition: None.
    
    int getTotalCorrectQueries() const;
    // description: A getter for the total number of corrects queries made.
    // precondition: None.
    // postcondition: None.
    
    void incrementTotalCorrect();
    // description: Used to increment the statistic for total correct quereies.
    // This methods should be called each time a word is correctly identified
    // as corrupt or not corrupt.
    // precondition: The isCorrupt method must return true, and then this
    // method must be called in order to correctly track statisitics.
    // postcondition: totalCorrect variable is incremented.
    
private:
    int totalCorrupt, totalEncrypted, totalCorrect, capacity, size;  // stats
    static const int CAPACITY = 5;// Holds the static array size of EW objects
    EncryptWord array[CAPACITY];
    //EncryptWord * array;           // Holds distinct EncrptWord objects
    string encodedWord;           // holds the current encodedWord
    string flipCoin();            // randomly generates a heads or tails value
    string corruptWord(string, int); // corrupts a word & returns it as string

    FindFault(const FindFault& orig);       // surpress copy ctor
    FindFault& operator=(const FindFault &);// surpress overloaded assignment
};

#endif /* FINDFAULT_H */
