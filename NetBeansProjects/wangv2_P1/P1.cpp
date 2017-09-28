// AUTHOR: Vilia Wang
// FILENAME: p1.cpp
// DATE: Created on September 25, 2017, 12:47 PM
// REVISION HISTORY: None
//
// Description: The P1 driver is designed as a Caesar cipher shift game. It is 
//              also intended to test the EncryptWord class and its methods. 
//              The main processes are as follows: the user inputs a word, and 
//              the encrypted version is printed to screen. The user then 
//              will be promoted to enter guesses for the shift size until she 
//              is correct. Then, the player's game statistics will be printed 
//              to screen. Player can as many rounds as desired. 
//              The driver utilizes an i/o stream for input and output. The 
//              input source is from the keyboard and output prints to screen. 
//              No data structures are used. 
// 
// Assumptions: The input source of this program is through the keyboard and 
//              and all output is printed to the screen. 
//              The user can only enter one valid word per round of the game 
//              (one "round" is equal to one shift size - a new round means a  
//              new shift size).
//              A valid word is assumed to be at least 4 letters long, have no
//              spaces, and only contain lowercase, alphabet characters. 
//              If a space is entered, the program will behave unexpectedly. 
//              Words less than 4 letters, with capital letters or with symbols
//              will prompt the user to enter a valid word. 
//              When the user is prompted to enter the shift guess, the program 
//              assumes that only integers will be entered (no letters, spaces
//              or symbols allowed). If a non-integer value is entered at this
//              point, the program will behave unexpectedly and incorrectly. 
//              The player must correctly guess the shift size before he/she 
//              will be asked if he/she would like to play again or quit. 
//              The user must enter 'y' or 'Y' to repeat the game. 
//              Note: classes and libraries used include cstdlib, iostream, 
//                    string, "EncryptWord.h" and namespace std.

#include <cstdlib>
#include <iostream>
#include <string>
#include "EncryptWord.h"

using namespace std;

// description: Welcomes user to the program and briefly explains rules. 
void welcome();

// description: Prompts user to enter a word for encryption. Calls the 
//              validateWord word method for input validation. Takes minimum
//              word size as a parameter. 
string getUserWord(int);

// description: Validates user's input to ensure that the word is at least 
//              4 characters long and the word holds only lowercase alphabet 
//              letters. Returns true for valid words, and false otherwise.
//              Does not do validation for words with spaces. 
//              Takes the minimum word size and user's input as a parameters. 
bool validateWord(string, int);

// description: Prompts the user to enter a shift size guess. Calls 
//              EncryptWord's isShift method, which returns true if the guess
//              is correct and false if guess is wrong. Prints guessing 
//              results to the screen. Takes the EncryptWord object as a 
//              parameter.
bool userGuesses(EncryptWord&);

// description: Prints the game statistics, which includes: low guesses, 
//              high guesses, average guesses, and total guesses. 
void printStats(EncryptWord&);

// description: Asks the user if they would like to play again. 
string repeatGame();

// description: Thanks the user for playing and says goodbye. 
void farewell();

int main(int argc, char** argv) {
    string word = "";           // holds user's word input
    string repeat = "";         // play again? 
    bool correct;               // is correct guess of shift?
    const int MIN = 4;          // minimum word size 
    
    welcome();
    EncryptWord game; 
    
    do {
        correct = false;     // reset user's guessing status at start of game
        game.reset();             
        word = getUserWord(MIN);    
        cout << "Encrypted: " << game.getEncryptWord(word) << endl;

        if (game.isOn()) {
            while (!correct) {
                correct = userGuesses(game);
            }
        }

        if (game.isOff()) {
            printStats(game);
        }
        repeat = tolower(repeatGame().at(0));

    } while(repeat.compare("y") == 0);

    farewell(); 
    return 0;
}

string getUserWord(int MIN) { 
    string word;    // user's input word 
    
    do {
        cout << "\nPlease enter a word to encrypt." << endl; 
        cout << "Must be at least " << MIN << 
                " characters and only lowercase alphabet letters!\n" << endl; 
        cout << "Your word: ";
        cin >> word; 
    } while (!validateWord(word, MIN));
    return word; 
}

bool validateWord(string word, int MAX) {
    if (word.length() < MAX)
        return false; 
    for (unsigned i = 0; i < word.length(); i++) {
        if (!isalpha(word[i]))
            return false; 
        if ((int)word[i] < 97 || (int)word[i] > 122)
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

void printStats(EncryptWord& game) {
    cout << "Total:   " << game.getTotal() << endl; 
    cout << "Low:     " << game.getLow() << endl; 
    cout << "High:    " << game.getHigh() << endl; 
    cout << "Average: " << game.getAverage() << endl; 
    
}

void welcome() {
    cout << "Welcome to P1: The Caesar Cipher Shift Game!\n" << endl; 
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
