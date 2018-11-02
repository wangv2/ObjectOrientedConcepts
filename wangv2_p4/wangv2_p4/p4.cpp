/**
 AUTHOR: Vilia Wang
 FILENAME: p4.cpp
 DATE: Created by VeeVee Wang on 11/5/17
 VERSION: 1
 REVISION: None
 
 DESCRIPTION:
 - Main processes:
 The driver test SequenceEnum, SeqExtract and SpasEnum. Each object is created
 and tested twice. The object is first created, the state is checked, a
 too-short word is entered, then a appropriately-sized word is entered. The
 state the checked again, and then the word variant is emitted. Finally, the
 user can enter their guesses of the encapsulated word. The user will be
 prompted to enter their guess of the encapsulated word until it is correct.
 
 - Data structures: None
 
 - Functionality:
 welcome() welcomes the user to the program, explains the program, and gives
 the grader hints for guessing.
 testSeqEnum, testSeqExtract, and testSpasEnum test functions for each
 respective object.
 bye() thanks the user for play and says goodbye.
 
 - Source of input:
 From the keyboard
 
 - Format of output:
 Printed to the screen
 
 - Design:
 This driver is designed to test all functions within SequenceEnum, SeqExtract
 and SpasEnum. It is designed as a partical guessing guess. Two "mystery" words
 will be set into each class and the user will guess the word. However, the
 welcome message offers hints to the grader so he does not actually need to
 guess.
 
 - Intent:
 This driver is intended to test SequeneEnum, SeqExtract, and SpasEnum and to
 show each class' functionality.

 ASSUMPTIONS:
 Restriction on use for:
 - Source of input:
 Input should be english characers and should not include spaces or tabs.
 
 - Format restrictions:
 The user does not choose what the encapsulated word will be set to. The
 encapsulated words are set by the driver designer and the user can only
 "guess" what the encap word is.
 
 - Value ranges:
 Input value ranges should be a-z, and A-Z.
 
 - Size of input:
 The largest encapsulated words range from 7 to 8 characters.
 
 - Error handling:
 If the user inputs an incorrect guess, the program will prompt the user to
 continue guessing until he is correct. In SeqExtract, the proffer word must
 match the beginning of the encapsulated word. If the proffer word does not
 match the beginning, the message "Proffer does not match" will be printed, and
 the user will be prompted to enter a proper proffer word again.
 
 - Classes used: SequenceEnum, SeqExtract, SpasEnum
 
 - Libraries used: iostream, string
 */

#include <iostream>
#include <string>
#include "SequenceEnum.h"
#include "SeqExtract.h"
#include "SpasEnum.h"

using namespace std;

void welcome();
// description: Welcomes user to the program
// input: None
// processing: None
// output: Prints to screen

void testSeqEnum(string, string[]);
// description: Test the SequenceEnum class
// input: string and array of strings are input parameters. The string holds a
// too-short word and the string array holds two words that will be
// encapsulated in to each object.
// processing: Uses the too-short word to try and set the encapWord, the string
// array holds two words, which are used as the encapsulated word in each class
// output: Prints to screen

void testSeqExtract(string, string[]);
// description: Test the SeqExtract class
// input: string and array of strings are input parameters. The string holds a
// too-short word and the string array holds two words that will be
// encapsulated in to each object.
// processing: Uses the too-short word to try and set the encapWord, the string
// array holds two words, which are used as the encapsulated word in each class
// output: Prints to screen

void testSpasEnum(string, string[]);
// description: Test the SpasEnum class
// input: string and array of strings are input parameters. The string holds a
// too-short word and the string array holds two words that will be
// encapsulated in to each object.
// processing: Uses the too-short word to try and set the encapWord, the string
// array holds two words, which are used as the encapsulated word in each class
// output: Prints to screen

void bye();
// description: Says goodbye to the user
// input: None
// processing: None
// output: prints to screen

int main() {
    static const int CAPACITY = 2;                  // Capacity of string arr
    string tooShort = "hi";                         // word less than 3 chars
    string stringArr[CAPACITY] = { "seattle",       // string array of words
                                   "redhawks" };
    
    welcome();
    
    cout << "TESTING SEQUENCE ENUM" << endl;
    cout << "After the creation of each SequenceEnum object, a word" << endl
         << "will be encapsulted. You must guess the correct word to" << endl
         << "continue." << endl << endl;
    testSeqEnum(tooShort, stringArr);
    
    cout << "TESTING SEQ EXTRACT" << endl;
    cout << "After the creation of each SeqExtract object, a word will" << endl
         << "be encapsulated. You will enter a proffer word that must" << endl
         << "match the beginning of the encapsulated word. If the" << endl
         << "proffer word does not match the beginning, an error" << endl
         << "message will print, and you must try again until it" << endl
         << "matches. Once the proffer word matches the beignning, a" << endl
         << "word will be emitted. Then you will guess the encapsulated" <<endl
         << "until you are correct." << endl << endl;
    testSeqExtract(tooShort, stringArr);
    
    cout << "TESTING SPAS ENUM" << endl;
    cout << "After the creation of each SpasEnum object, a word will" << endl
         << "be encapsulated. You must guess the correct word to continue";
    cout << endl << endl; 
    testSpasEnum(tooShort, stringArr);
    
    bye();
    return 0;
}

void welcome() {
    cout << endl << "Welcome to p4!" << endl << endl;
    cout << "This is the test driver for the SequenceEnum, SeqExtract" << endl;
    cout << "and SpasEnum classes. The driver will create and test" << endl;
    cout << "two of each class. Each test will test all of the the" << endl;
    cout << "classes methods including: constructor, state, entering" << endl;
    cout << "a word, emitting word variant and guessing the word.\n" << endl;

    cout << "For the grader's convenience: " << endl;
    cout << "- 0 means FALSE\n- 1 means TRUE" << endl;
    cout << "- word 1 = \"seattle\"" << endl;
    cout << "- word 2 = \"redhawks\"" << endl;
    cout << endl;
}

void testSeqEnum(string tooShort, string arr []) {
    string input = "";          // Holds user's guess input
    
    for (int i = 0; i < 2; i++) {
        SequenceEnum seq;
        cout << "Creating a SequenceEnum object." << endl;
        cout << "Active? (expecting 0)      " << seq.isActive() << endl;
    
        cout << "Able to enter \"hi\"?        " << seq.enterWord(tooShort)
             << endl;
        cout << "Able to enter word " << (i+1) << "?      "
             << seq.enterWord(arr[i]) << endl;
    
        cout << "Active? (expecting 1)      " << seq.isActive() << endl;
    
        cout << "Emit word variant:         " << seq.emit() << endl;
        
        do {
            cout << "Guess word " << (i+1) << ":              ";
            cin >> input;
        } while (!seq.isWord(input));
        cout << "Correct guess - good job!" << endl << endl;
    }
}


void testSeqExtract(string tooShort, string arr []) {
    string proffer = "";        // Holds user's proffer input
    string input = "";          // Holds user's guess input
    
    for (int i = 0; i < 2; i++) {
        SeqExtract ext;
        cout << "Creating a SeqExtract object." << endl;
        cout << "Active? (expecting 0)      " << ext.isActive() << endl;
        
        cout << "Able to enter \"hi\"?        " << ext.enterWord(tooShort)
             << endl;
        cout << "Able to enter word " << (i+1) << "?      "
             << ext.enterWord(arr[i]) << endl;
        
        cout << "Active? (expecting 1)      " << ext.isActive() << endl;
        
        do {
            cout << "Enter a proffer word:      ";
            cin >> proffer;
            cout << "Result:                    " << ext.emit(proffer) << endl;
        } while (ext.emit(proffer) == "Proffer does not match");
        
        do {
            cout << "Guess word " << (i+1) << ":              ";
            cin >> input;
        } while (!ext.isWord(input));
        cout << "Correct guess - good job!" << endl << endl;
    }
}

void testSpasEnum(string tooShort, string arr []) {
    string input = "";          // Holds user's guess input
    
    for (int i = 0; i < 2; i++) {
        SpasEnum spas;
        cout << "Creating a SpasEnum object." << endl;
        cout << "Active? (expecting 0)      " << spas.isActive() << endl;
        
        cout << "Able to enter \"hi\"?        " << spas.enterWord(tooShort)
             << endl;
        cout << "Able to enter word " << (i+1) << "?      "
             << spas.enterWord(arr[i]) << endl;
        
        cout << "Active? (expecting 1)      " << spas.isActive() << endl;
        
        cout << "Emit word variant:         " << spas.emit() << endl;
        
        do {
            cout << "Guess word " << (i+1) << ":              ";
            cin >> input;
        } while (!spas.isWord(input));
        cout << "Correct guess - good job!" << endl << endl;
    }
}

void bye() {
    cout << endl << "Thanks for visitng p4. Bye!" << endl << endl;
}
