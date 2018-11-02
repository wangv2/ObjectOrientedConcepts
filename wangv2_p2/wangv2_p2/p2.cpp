/* 
 * AUTHOR: Vilia Wang
 * FILENAME: p2.cpp
 * DATE: Created on October 6, 2017, 2:07 PM
 * REVISiON HISTORY: None. 
 * REFERENCES: None. 
 */

/*
 * Description: 
 * - Main processes: The driver simulates several rounds of a FindFault game.
 * FindFault has a set capacity of 5, which means for each game, 5 words can
 * be inserted into the FindFault object. After the words are inserted, the
 * simulator will retrieve and print the encoded word and the decoded word.
 * Then, users will guess if a word is corrupt or not. The user will enter "y"
 * if they think the word is corrupted, and "n" for if they think the word is
 * not corrupted. Statistics of how many words were corrupted, how many were
 * encrypted, and how many correct queries will be printed at the end of each
 * game.
 * 
 * - Data structures: 
 * The driver class contains a string array of words that is used to insert
 * into FindFault.
 * 
 * - Functionality exercised: 
 * The p2 driver class utilizes all of FindFault's methods in the form of a 
 * find fault guessing game simulator.
 * 
 * - Source of input: 
 * The i/o stream is used for input and its source is the keyboard. 
 * 
 * - Format of output: 
 * The i/o stream is used for output and its format of output is printing to 
 * the screen. 
 * 
 * - Design:
 * The driver is designed to play 3 rounds of the find fault game, which tests
 * the FindFault class and creates three distinct FindFault objects. For each
 * game, 5 words are inserted into FindFault. The encoded and decoded versions
 * are printed to the screen. The user will guess if they think a word is
 * corrupted or not corrupted. At the end of each game, statistics will be
 * printed to the screen.
 * 
 * - Intent: 
 * The driver is intended to test each method in FindFault at least once for 
 * functionality.
 * 
 * Assumptions: 
 * - Restrictions on form and source of input:
 * The driver asks the user if they believe a word is corrupted or not.
 * The user will input either a lowercase "y" for yes or a lowercase "n" for no
 * to answer the question. The string input should only be "y" or "n" and may
 * not include other letters, symbols or numbers. "y" is the only input that
 * means an answer of yes. If the user enters anything but a "y", that
 * input will be considered an "n" for no to the question.
 * 
 * - Format restrictions: 
 * This driver does not support user interactions for inserting words or
 * for choosing FindFault's capacity. However, the user will input a guess of
 * whether a word is corrupt or not. The rest of the game simulations are
 * automatic.
 * 
 * - Value ranges: 
 * The string input must either be a "y" or a "n". No spaces, symbols,
 * numbers, capital letters, or lowercase letters besides "y" and "n".
 * 
 * - Size of input: 
 * There is one string input per round of the game it must either be a "y" for
 * yes or a "n" for no.
 * 
 * - Error handling: 
 * Errors are handled defensively.
 * 
 * - Classes used: FindFault.h
 * - Libraries used: cstdlib, iostream, limits
 */

#include <cstdlib>
#include <iostream>
#include <limits>
#include "FindFault.h"

using namespace std;

void welcome(); 
// description: Welcomes user to the program and explains the game. 
// input: None. 
// processing: None. 
// output: None.

void findCorruption(FindFault&, int);
// description: Checks if a word is corrupted.
// input: FindFault object, EncryptWord object index 
// processing: Uses FindFault's methods and accesses EncryptWord's word
// output: Prints to screen. 

void printStats(FindFault&);
// description: Prints statistics for each round of the game. 
// input: FindFault object.
// processing: Uses FindFault's methods to print statistics.
// output: prints to screen. 

void farewell(); 
// description: Thanks the user for playing and says goodbye. 
// input: None.
// processing: None.
// output: Prints to screen. 

int main(int argc, char** argv) {
    const int TOTAL_GAMES = 3;      // holds the index of total games
    string words[] = { "hello", "seattle",
                       "university", "sushi",
                       "coffee" };          // string of words to encrypt
    
    welcome();
    
    // playing 3 total games
    for (int j = 0; j < TOTAL_GAMES; j++) {

        cout << "GAME " << j + 1 << " of " << TOTAL_GAMES << endl;
        FindFault game;
        
        // loop through full capacity of the array
        for (int i = 0; i < game.getCapacity(); i ++) {

            // if the array is NOT full, insert word and play a round
            if  (game.getSize() < game.getCapacity()) {
                cout << endl << "WORD " << i + 1 << " of "
                     << game.getCapacity() << ":" << endl;
                cout << "-----------------" << endl;
                
                cout << "Inserting \"" << words[i] << "\"" << endl;
                game.insert(words[i]);

                cout << "Decoded word: " << game.getDecodedWord(i) << endl;
                cout << "Encoded word: " << game.getEncodedWord(i) << endl;

                findCorruption(game, i);
            }
        }
        printStats(game);
    }
    
    farewell(); 
    return 0;
}

void welcome() {
    cout << "Welcome to p2!" << endl << endl;
    
    cout << "This is the driver file that tests the FindFault class." << endl;
    cout << "It will run through 3 game simulations. For each game, " << endl;
    cout << "5 words will be inserted into FindFault. The decoded and " <<endl;
    cout << "encoded versions of each string will be printed. For " << endl;
    cout << "each word, you will guess \"y\" for yes or \"n\" for" << endl;
    cout << "no for whether you think the encoded word is corrupted" << endl;
    cout << "or not. Statistics will print to screen at the end of each game."
         << endl;
    cout << "Enjoy!" << endl << endl;
}

void findCorruption(FindFault& game, int index) {
    string guess = "";               // guess for corrupt or not?

    cout << "Is the encoded word corrupt? (y/n): ";
    cin >> guess;

    if (guess == "y") {
        if (game.isCorrupt(index, true)) {
            cout << "You are CORRECT! The word is corrupt." << endl;
            game.incrementTotalCorrect();
        }
        else {
            cout << "You are INCORRECT! The word is not corrupt." << endl;
        }
    }
    
    else {
        if (game.isCorrupt(index, false)) {
            cout << "You are CORRECT! The word is not corrupt." << endl;
            game.incrementTotalCorrect();
        }
        else {
            cout << "You are INCORRECT! The word is corrupt." << endl;
        }
    }
}

void printStats(FindFault& game) {
    cout << endl << "GAME STATS: " << endl;
    cout << "----------------------" << endl;
    cout << "Total Correct Queries: " << game.getTotalCorrectQueries() << endl;
    cout << "Total Encrypted:       " << game.getTotalEncrypted() << endl;
    cout << "Total Corrupted:       " << game.getTotalCorrupt() << endl<< endl;
    cout << endl;
}

void farewell() {
    cout << "Thanks for visting p2! Bye!" << endl << endl;
}
