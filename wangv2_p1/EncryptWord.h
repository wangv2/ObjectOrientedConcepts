// AUTHOR: Vilia Wang
// FILENAME: p1.cpp
// DATE: Created on September 25, 2017, 12:47 PM
// VERSION: 2
// REVISION HISTORY: Edited 5 September 2017. 
//
// Description: 
// - overview: This class provides methods for a Caesar cipher shift game. 
// - functionality: The ctor and reset methods initialize class fields for the 
//   start of a new game. Reset must be used at the beginning of new rounds.
//   Failure to reset rounds will result in inaccurate statistics, state and no 
//   change in the shift size. The class accepts a word as a string input and 
//   encrypts it. The encryption is executed by shifting each character's ASCII 
//   value by a random shift size, assigned by a random number generator. The 
//   encrypted word is then returned as a string. The isShift method can be 
//   used to query shift. isShift will return true if the guess is correct, 
//   and false if guess if incorrect. The getDecryptedWord method, returns a
//   original word as a string. Finally, the class tracks statistics for each 
//   round of the game played. The statistics can be retrieved through the 
//   getters for statistic variables.
// - legal states: The object can be 'on' and 'off'.
// - Dependencies: The 'on' and 'off' states are dependant on the 
//   getEncryptedWord method. The game state 'on' is true / 'off' is false once 
//   getEncryptedWord is called. Statistics are also dependant on the isShift 
//   method and are updated each time isShift is called.
// - Anticipated use: Anticipated to be used for a Caesar shift game. The game
//   will run as intended if methods are used in the following order: reset()
//   -> getEncryptWord(string) -> isOn() or isOff() -> getDecryptWord() -> 
//   isShift(int) -> getTotal(), getLow(), getHigh(), getAverage(). 
// - Data processed: String data that represents a word to encrypt is 
//   encrypted with the getEncryptWord method, and then assigned to a class 
//   field. Int data represents the guess value which is used in the isShift() 
//   method to update statistics.
// - legal input: String input must have at least 4 all-lowercase characters, 
//   and no spaces, symbols or capital letters. Shift size input must be an 
//   integer (no spaces, symbols, or characters).
// - illegal input: Illegal for string input to be less than 4 characters. 
//   Strings cannot have spaces, uppercase letters, or symbols. Illegal input 
//   for an int is anything that is not an int. 
// - output given: output is either void, int, string or bool. 

// Assumptions: - There is only one constructor and it takes no arguments. 
//              - The reset method must be called at the beginning of each new 
//                game round in order to properly initialize fields. 
//              - The getEncryptWord method assumes the string input holds
//                only lowercase, alphabet letters with no spaces. This method  
//                also changes the state 'on' to true, and 'off' to false. 
//              - Decoding a word is defined as returning the word as a string 
//                before encryption. The getDecryptWord method does this by
//                by returning the original word as a string. This method 
//                should only be called when 'on' is true/'off' is false, 
//                meaning a word has been encrypted. 
//              - The isShift method can only be called after a word has been 
//                encrypted with the getEncryptWord method (when 'on' is true
//                and 'off' is false). 
//              - To check whether a word has been encrypted/state object, 
//                users should use the isOn method, or isOff method. 
//              - isOn means that a word has been encrypted and a user can now
//                call the isShift method to guess the shift value. 
//              - isOff means that a word has not been encrypted. A word should
//                be encrypted before the isShit method is used for guessing. 
// Interface 
// invariants:  - valid types and formats (string and int) must be passed
//              - Call by value not supported 
//              - Copying suppressed
//              - reset must be called at beginning of new game rounds 
//              - getEncryptWord must be called before isShift
//              - isOn and isOff should be used to check state before using 
//                getDecryptWordWord and isShift methods. 

#ifndef NEWENCRYPTWORD_H
#define NEWENCRYPTWORD_H

#include <string>
#include <cstdlib>

using namespace std;

class EncryptWord {
public:
    EncryptWord();  
    // description: The no-argument constructor that initializes class fields 
    // for the start of a new game. 
    // precondition: None.
    // postcondition: Creates an initial valid state for the start of new game. 
    // 'on' is false and 'off' is true (actual state change).
    
    string getEncryptWord(string);
    // description: Takes a valid word as a string parameter to encrypt. 
    // Returns an encrypted word. Game state 'on' is true and 'off' is false 
    // once this method is called, meaning a word is encrypted. 
    // precondition: String parameter must only have lowercase, alphabet 
    // characters (no symbols, spaces or capitals). 
    // postcondition: Game state 'on' is true and 'off' is false (actual state 
    // change). 
    
    bool isShift(int);
    // description: Takes a valid guess as an int parameter. Returns true if 
    // guess correctly matches the shift size and false if guess is incorrect. 
    // This method also updates statistics.
    // precondition: The state 'on' should be true ('off' should be false), in 
    // order to call this method to guess shift size (user should only guess
    // shift size after a word has been encrypted).
    // postcondition: Updates statistic variables low, high, total, and 
    // average.
    
    bool isOn() const;
    // description: Checks state of object. Returns true if game is 'on' and 
    // false if game is not 'on'. 'On' means that a word has been encrypted.
    // precondition: None.
    // postcondition: None. 
    
    bool isOff() const;
    // description: Checks state of object. Returns true if game is 'off' and 
    // false if game is not 'off'. 'Off' means a word has not been encrypted. 
    // precondition: None. 
    // postcondition: None.
    
    void reset();
    // description: Resets class fields to a valid state for the start of a new 
    // round in a game.
    // precondition: None.
    // postcondition: Creates a valid state for the start of a new game. Game
    // state 'on' is false, and 'off' is true (actual state change). 
     
    int getTotal() const;
    // description: A getter for the 'total' variable. Returns the number of
    // total guesses in one round it took to correctly guess shift size. 
    // precondition: None.
    // postcondition: None.
    
    int getLow() const;
    // description: A getter for the 'low' variable. Returns the number of 
    // times the guess was lower than the correct shift value. 
    // precondition: None.
    // postcondition: None.
    
    int getHigh() const;
    // description: A getter for the 'high' variable. Returns the number of 
    // times the guess was higher than the correct shift value. 
    // precondition: None.
    // postcondition: None. 
    
    double getAverage() const;
    // description: A getter for the 'average' variable. Returns the average
    // guess value entered by the user per round. 
    // precondition: None.
    // postcondition: None. 
    
    string getDecryptWord(); 
    // description: A getter for the 'originalWord' variable. Returns the 
    // decoded word as a string. 
    // precondition: 'On' must be true / 'off' must be false.
    // postcondition: None. 

private:
    int shift, total, low, high;    // describes the shift size and statistics
    double average;                 // describes the average guess value 
    string originalWord, shiftWord; // describes the decoded and encrypted word
    const int MIN_RAND = 1;         // minimum random number 
    const int MAX_RAND = 25;        // maximum random number
    const int MIN_LETTERS = 97;     // minimum ASCII value 
    const int TOTAL_LETTERS = 26;   // total letters of alphabet
    
    string cipherShift(string);     // returns encrypted word
    void updateStats(int);          // updates statistics 
    int calculateShift();           // returns shift size 
};

#endif /* ENCRYPTWORD_H */
