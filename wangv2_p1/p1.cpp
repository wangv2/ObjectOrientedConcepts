// AUTHOR: Vilia Wang
// FILENAME: p1.cpp
// DATE: Created on September 25, 2017, 12:47 PM
// VERSION: 2
// REVISION HISTORY: Edited 5 September 2017.
//
// Description: 
// - Design: The driver file is designed in two parts, automatic and manual
//   game play. Part 1 runs through one round of the game automatically, and 
//   part 2, allows the user to play rounds manually as many times as desired.
// - Intent: Part 1 is intended to test EncryptWord's method all at least 
//   once for one round of the game. Part 1, also serves as a model for how
//   to play the game and test in part 2. Part 2, is intended for the user to
//   play the game and do further testing, if desired. Part 2 also demonstrates  
//   the creation of a new distinct object. 
// - main processes: Part 1, runs through the game automatically. In part 2, 
//   the user inputs a word, and the encrypted and decrypted versions are 
//   printed to screen. The  user then will be promoted to enter guesses for 
//   the shift size until he/she is correct. The player's game statistics will 
//   be printed to screen. Players can play as many rounds as desired. 
// - data structures: None.
// - functionality: All EncryptWord's methods are tested in the form of a 
//   Caesar Cipher shift game.
// - input/output: The driver utilizes an i/o stream for input and output. 
//   Input is from the keyboard and output prints to screen.
// 
// Assumptions: - The input source of this program is through the keyboard and 
//                and all output is printed to the screen. 
//              - The user can only enter one valid word to encrypt per round 
//                of the game (one "round" is equal to one shift size - a new
//                round means a new shift size).
//              - When prompted to enter a word, the word is assumed to be at 
//                least 4 letters long, have no spaces, and only contain 
//                lowercase, alphabet characters. If a space is entered, the 
//                program will behave unexpectedly. Word input less than 4 
//                letters, with capital letters or with symbols will prompt
//                the user to enter a new valid word. 
//              - A word should be encrypted ('on' is true, 'off' is false), 
//                before shift size queries begin. 
//              - When the user is prompted to enter the shift guess, it is
//                assumed that only integers will be entered (letters, spaces
//                and symbols not allowed). If a non-integer value is entered 
//                at this point, the program will behave unexpectedly. 
//              - The player must correctly guess shift size before he/she 
//                will be asked if he/she would like to play again or quit. 
//              - The user must enter 'y' or 'Y' to repeat the game.
//              - Note: classes and libraries used include cstdlib, iostream, 
//                      string, "EncryptWord.h" and namespace std.

#include <cstdlib>
#include <iostream>
#include <string>
#include "EncryptWord.h"

using namespace std;

void welcome();
// description: Welcomes user to the program and briefly explains rules. 
// input: None
// processing: None.
// output: None.


string getUserWord(int);
// description: Prompts user to enter a word for encryption. Calls the 
// validateWord word method for input validation.  
// input: Minimum word size as an int.
// processing: None 
// output: Returns a valid word as a string. 

bool validateWord(string, int);
// description: Validates user's input to ensure that the word is at least 
// 4 characters long and the word holds only lowercase alphabet letters. 
// Does not do validation for words with spaces.
// input: user's input word as a string and minimum word size as an int. 
// processing: Validates string input. 
// output: Returns true if word is valid, false if invalid.

bool userGuesses(EncryptWord&);
// description: Prompts the user to enter a shift size guess. Calls 
// EncryptWord's isShift method, which returns true if the guess is correct and
// false if guess is wrong. 
// input: EncryptWord object.
// processing: Gets shift guess from user, and checks if it is correct. 
// output: Returns true if guess is correct and false if incorrect. 

void printStats(EncryptWord&);
// description: Prints the game statistics, which includes: low guesses, 
// high guesses, average guesses, and total guesses. 
// input: EncryptWord object. 
// processing: Retrieves statistics from the object.
// output: None. 

string repeatGame();
// description: Asks the user if they would like to play again. 
// input: None.
// processing: None. 
// output: Result of whether they want to play again as a string.

void farewell();
// description: Thanks the user for playing and says goodbye. 
// input: None.
// processing: None. 
// output: None. 

void runAutoProgram();
// description: Runs the automatic portion of the game, by creating a new 
// object in order to test EncryptWord's functionality. 
// input: None
// processing: None.
// output: None.

int main() {
    string word = "";          // holds user's word input
    string repeat = "";        // play again? 
    bool correct;              // is correct guess of shift?
    const int MIN = 4;         // minimum word size 
    
    welcome();
    cout << "\nPART 1: AUTOMATIC ROUND" << endl;
    runAutoProgram();

    cout << "\nPART 2: MANUAL PLAY" << endl;
    cout << "\nThe first 7 random shift sizes in part 2 are: ";
    cout << "25, 24, 9, 6, 23, 20, 4" << endl;
    
    EncryptWord game; 
    do {
        correct = false; // reset guessing status at start of game
        game.reset();             
        word = getUserWord(MIN); 
        cout << "Encrypted: " << game.getEncryptWord(word) << endl;
        cout << "Original:  " << game.getDecryptWord() << endl; 

        // game is on (not off) only after a word has been encrypted 
        if (game.isOn() && !game.isOff()) {
            while (!correct) {
                correct = userGuesses(game);
            }
        }
        printStats(game);
        repeat = tolower(repeatGame().at(0));
    } while(repeat.compare("y") == 0);
  
    farewell(); 
    return 0;
}

void runAutoProgram() {
    int shiftGuess = 0; 
    bool correctShift = false; 
    
    // create a new object 
    cout << "\nCreating a new EncryptWord Object...\n" << endl; 
    EncryptWord autoGame; 
    
    // checking object's state after it is created 
    cout << "Checking object state after constructor is called:" << endl;
    cout << "   autoGame.isOn() (expecting false/0) " << autoGame.isOn() 
         << endl; 
    cout << "   autoGame.isOff() (expecting true/1) " << autoGame.isOff() 
         << endl; 
    
    // encrypting a word, getting encrypted word and decoded word
    cout << "\nEntering the word \"hello\" to encrypt." << endl;
    cout << "Encrypted word: " << autoGame.getEncryptWord("hello") << endl;
    cout << "Decoded word: " << autoGame.getDecryptWord() << endl;
    
    // checking state of object after a word is encrypted 
    cout << "\nChecking object state after a word has been encrypted:" << endl;
    cout << "   autoGame.isOn() (expecting true/1) " << autoGame.isOn() 
         << endl; 
    cout << "   autoGame.isOff() (expecting false/0) " << autoGame.isOff() 
         << endl; 
    
    // testing isShift method to guess shift size
    cout << "\nTesting autoGame.isShift method to guess shift size. " << endl; 
    while (correctShift == false) {
        shiftGuess++;
        cout << "Guessing: " << shiftGuess << endl;
        if (autoGame.isShift(shiftGuess)) {
            correctShift = true;
        }         
    }
    
    // testing statistics retrieval methods 
    cout << "\nCorrect shift size of " << correctShift << " guessed! " << endl; 
    cout << "Printing statistics: "  << endl; 
    printStats(autoGame); 
    
    // testing reset method 
    cout << "\nReseting game..." << endl; 
    autoGame.reset(); 
    
    // testing object's state after it is reset 
    cout << "Checking object state after object is reset:" << endl;
    cout << "   autoGame.isOn() (expecting false/0) " << autoGame.isOn() 
         << endl; 
    cout << "   autoGame.isOff() (expecting true/1) " << autoGame.isOff() 
         << endl; 
}

string getUserWord(int MIN) { 
    string word;    // user's input word 
    
    do {
        cout << "\nPlease enter a word to encrypt." << endl; 
        cout << "Must be at least " << MIN << " characters," << endl;
        cout << "and only lowercase alphabet letters" << endl;
        cout << "with no spaces:  "; 
        cin >> word; 
        cout << endl; 
    } while (!validateWord(word, MIN));
    return word; 
}

bool validateWord(string word, int MIN) {
    const int ASCII_LOW = 97;       // minimum valid ascii number 
    const int ASCII_HIGH = 122;     // maximum valid ascii number 
    
    if (word.length() < MIN)
        return false; 
    for (unsigned i = 0; i < word.length(); i++) {
        if (!isalpha(word[i]))
            return false; 
        if ((int)word[i] < ASCII_LOW || (int)word[i] > ASCII_HIGH)
            return false;
    }
    return true;
}

bool userGuesses(EncryptWord& game) {
    int shift;  // user's shift guess 
    
    cout << "\nGuess shift size: ";
    cin >> shift; 
    if (game.isShift(shift)) {
        cout << "\nYou got the correct shift size!" << endl; 
        return 1;
    }
    else {
        cout << "Wrong! Try again." << endl; 
        return 0;
    }
}

void printStats(EncryptWord &game) {
    cout << "Round total: " << game.getTotal() << endl; 
    cout << "Low:         " << game.getLow() << endl; 
    cout << "High:        " << game.getHigh() << endl; 
    cout << "Average:     " << game.getAverage() << endl;    
}

void welcome() {
    cout << "Welcome to P1: The Caesar Cipher Shift Game!\n" << endl; 
    
    cout << "There are two parts to this program: automatic and manual."<<endl;
    cout << "Automatic: tests all EncryptWord methods for one round of the "
            "game." << endl;
    cout << "Manual: User can play normally/manually to further test "
            "functions. " << endl; 
            
    cout << "\nRULES: " << endl; 
    cout << "In this guessing game, you will first enter a word." << endl; 
    cout << "Your word will be encrypted with a random shift size" << endl;
    cout << "between 1 and 25. Then, you will guess the shift size," << endl;
    cout << "which must be an integer. You win the round once you"  << endl;
    cout << "guess the correct shift size. You can repeat the game as" << endl;
    cout << "many times as desired. Good luck!" << endl; 
}

string repeatGame() {
    string r; 
    cout << "\nPlay again? (y/n)  ";
    cin >> r;
    return r; 
}

void farewell() {
    cout << "\nThanks for playing. Bye!" << endl; 
}
