// AUTHOR: Vilia Wang
// FILENAME: p3.cpp
// DATE: Created on October 23, 2017, 12:47 PM
// VERSION: 1
// REVISION: None

/**
 * DESCRIPTION:
 * - main processes: This program welcomes the user, tests EncryptWord, tests
 * FindFault, and then says goodbye to the user. For the testing sections, the
 * program tests each of the classes's copy constructor, and overloaded
 * funtions. EncryptWord's overloaded methods include: assignment, +, -, <, >,
 * ==. and !=. FindFault's overloaded methods include: assignment, +, -, ==,
 * and !=. And the end of testing, the user will have the option to run the
 * program again or to quit. The program is mostly automatic, and the only
 * input is a "y" to repeat the program or a "n" to quit.
 *
 * - data structures: This program does not use any data structures.
 *
 * - functionality: The welcome function is used to welome the user and explain
 * the purpose of the program. The two testing functions create multiple
 * distinct EW and FF objects, which are used to test the copy ctor and
 * overloaded functions. These testing functions will print info about steps
 * taken, and expected outcomes, during the program. The user has the option to
 * repeat the program as desired or to quit. Finally, the goodbye
 * methods thanks the user for plays and says goodbye.
 *
 * - source of input: The user will be prompted if they would like to repeat
 * the program, or to quit. The source of input will be from the keyboard, and
 * "y" represents yes to repeat and, "n" represents no to quit.
 *
 * - format of output: Output is printed to the screen.
 *
 * - Design: This driver is designed as an semi-automatic test driver to test
 * the copy ctor and overloaded methods of the EW and FF classes. Each run will
 * show the shift sizes and corruption of the classes. The user should
 * repeat the program at least once, to see different randomized functionality
 * of each class.
 *
 * - Intent: This driver is intended to test and show the functionality of the
 * copy constructors and overloaded methods for EncrptWord and FindFault.
 *
 * ASSUMPTIONS:
 * - Restrictions on form and source of input: The only input should either be
 * a "y" for yes to repeat the program, or a "n" for no to quit the program.
 *
 * - Format restrictions: The program runs semi-automatically. It will pause
 * for input as to whether the user would like to repeat or quit the
 * program. The program will not resume until it recieves this input.
 *
 * - Value ranges: The input should either be a "y" or a "n".
 *
 * - Size of input: The input should either be a "y" or a "n".
 *
 * - Error handling: Erroneous input other than "y" or "n", will be treated as
 * a no and the program will quit. For example, when prompted to repeat the
 * program or not, an input of "hello" will result in the program quitting. The
 * only way to repeat the program is to type "y" and then hit enter.
 *
 * - Classes used: FindFault.h, EncryptWord.h
 * - Libraries used: iostream, chrono, thread
 */

#include "EncryptWord.h"
#include "FindFault.h"
#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

void welcome();
// description: Prints a welcome message to the user and explains the program.
// input: None.
// processing: None.
// output: Prints message.

void testEW(string);
// description: Tests EncryptWord's copy ctor, overloaded assingment, +, -, >,
// <, ==, and != operators.
// input: string input for the const word that is inputed into objects
// processing: string input inserted into the objects
// output: Prints data.


void testFF(string);
// description: Tests FindFault's copy ctor, overloaded assingment, +, -, ==,
// and != operators.
// input: string input for the const word that is inputed into objects
// processing: string input inserted into the objects
// output: Prints data.

void peaceOut();
// description: Prints a goodbye message to the user.
// input: None.
// processing: None.
// output: Prints message.

int main() {
    const string WORD = "hello";    // const input that is entered into objects
    string repeat = "";             // run again?
    
    welcome();
    
    do {
        cout << "TESTING ENCRYPTWORD CLASS" << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;
        testEW(WORD);
        
        cout << endl << endl << "TESTING FINDFAULT CLASS" << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;
        testFF(WORD);
        
        cout << "Would you like to run the program again? (y/n) ";
        cin >> repeat;
    } while (repeat == "y" || repeat == "Y");
    
    peaceOut();
    return 0;
}

void welcome() {
    cout << "\nWelcome to p3!\n" << endl;
    cout << "This is the driver file that tests methods from the EncryptWord\n"
         << "class and the FindFault class. It will test EncryptWord's copy\n"
         << "constructor, overloaded assignment, +, -, >, <, == and !=\n"
         << "operators. It will test FindFault's copy constructor,\n"
         << "overloaded assignment, +, -, == and != operators." << endl;
    cout << "This program is mostly automatic - the user has the choice\n"
            "to repeat the program as many times as desired or quit\n"<<endl;
}

void peaceOut() {
    cout << "\nThanks for visitng p3! Bye!\n" << endl;
}

void testEW(string WORD) {
    string encode1, encode2, encode3;
    
    // EW: copy ctor testing
    cout << "-------------------------" << endl;
    cout << "Testing copy constructor" << endl;
    cout << "-------------------------" << endl;
    
    EncryptWord ew1;
    cout << "- Creating an object called ew1 and inserting \"" << WORD
         << "\" into ew1." << endl << endl;
    
    encode1 = ew1.getEncryptWord(WORD);
    cout << "ew1 encodedWord: " << encode1 << endl;
    cout << "ew1 shift size:  " << ew1.testGetShift() << endl;
    
    cout << endl << "- Coping ew1 to ew2 via copy constructor" << endl;
    cout << "- Doing this operation: EncryptWord ew2 = ew1;" << endl;
    cout << "- ew1 and ew2 should be the same" <<endl << endl;
    
    EncryptWord ew2 = ew1;
    encode2 = ew2.getShiftWord();
    cout << "ew2 encodedWord: " << encode2 << endl;
    cout << "ew2 shift size:  " << ew2.testGetShift() << endl;
    
    cout << endl << "ew2 == ew1? ";
    if (ew2 == ew1)
        cout << "True" << endl;
    else
        cout << "False" << endl;
    
    chrono::seconds dura( 1);
    this_thread::sleep_for( dura );
    
    // EW: testing overloaded assignment operator
    cout << endl << "--------------------------------------" << endl;
    cout << endl << "Testing overloaded assignment operator" << endl;
    cout << "--------------------------------------" << endl;
    
    EncryptWord ew3;
    encode3 = ew3.getEncryptWord(WORD);
    
    cout << "ew2 encodedWord: " << encode2 << endl;
    cout << "ew2 shift size:  " << ew2.testGetShift() << endl << endl;
    cout << "ew3 encodedWord: " << encode3 << endl;
    cout << "ew3 shift size:  " << ew3.testGetShift() << endl;
    
    cout << endl <<"- Doing this operation: ew2 = ew3" << endl;
    cout << "- ew2 should be the same as ew3 from above" << endl << endl;
    
    ew2 = ew3;
    cout << "ew2 encodedWord: " << ew2.getShiftWord() << endl;
    cout << "ew2 shift size:  " << ew2.testGetShift() << endl;
    
    cout << endl << "ew2 == ew3? ";
    if (ew2 == ew3)
        cout << "True" << endl;
    else
        cout << "False" << endl;
    
    // EW: testing overloaded + operator
    cout << endl << "-----------------------------" << endl;
    cout << endl << "Testing overloaded + operator" << endl;
    cout << "-----------------------------" << endl;
    
    cout << "ew1 shift size:  " << ew1.testGetShift() << endl;
    cout << "ew2 shift size:  " << ew2.testGetShift() << endl << endl;
    cout << "- Doing the following operation: ew1 = ew1 + ew2" << endl;
    cout << "- ew1's shift size should equal ew1 + ew2" << endl;
    cout << "- The shift size will \"wrap around\" if it is " <<
            "greater than the max shift size of 25" << endl;
    cout << "  (ex: shift of 26 is equal to 1)" << endl << endl;
    
    ew1 = ew1 + ew2;
    cout << "ew1 shift size after operation:  " << ew1.testGetShift() << endl
         << endl;
    
    cout << "- Testing edge cases for addition" << endl << endl;
    
    // edge case 1
    cout << "- Edge case 1: 25 + 25 should equal 25" << endl;
    cout << "- Creating two objects, edge1a and edge1b, that each have a" <<
            " shift size of 25." << endl;
    cout << "- Doing this operation: edge1a = edge1a + edge1b" << endl << endl;

    EncryptWord edge1a(WORD, 25);
    EncryptWord edge1b(WORD, 25);

    cout << "edge1a shift size:   " << edge1a.testGetShift() << endl;
    cout << "edge1b shift size:   " << edge1b.testGetShift() << endl;
    
    edge1a = edge1a + edge1b;
    cout << "edge1a shift size after operation: " << edge1a.testGetShift()
         << endl << endl;
    
    // edge case 2
    cout << "- Edge case 2: 20 + 15 should equal 10" << endl;
    cout << "- Creating two objects, edge2a shift = 20 and edge2b shift = 15"
         << endl;
    cout << "- Doing this operation: edge2a = edge2a + edge2b" << endl << endl;
    
    EncryptWord edge2a(WORD, 20);
    EncryptWord edge2b(WORD, 15);
    
    cout << "edge2a shift size:   " << edge2a.testGetShift() << endl;
    cout << "edge2b shift size:   " << edge2b.testGetShift() << endl;
    
    edge2a = edge2a + edge2b;
    cout << "edge2a shift size after operation: " << edge2a.testGetShift()
         << endl << endl;
    
    // edge case 3
    cout << "- Edge case 3: 1 + 3 should equal 4" << endl;
    cout << "- Creating two objects, edge3a shift = 3 and edge3b shift = 1"
         << endl;
    cout << "- Doing this operation: edge3a = edge3a + edge3b" << endl << endl;
    
    EncryptWord edge3a(WORD, 3);
    EncryptWord edge3b(WORD, 1);
    
    cout << "edge3a shift size:   " << edge3a.testGetShift() << endl;
    cout << "edge3b shift size:   " << edge3b.testGetShift() << endl;
    
    edge3a = edge3a + edge3b;
    cout << "edge3a shift size after operation: " << edge3a.testGetShift()
         << endl;
    
    // EW: testing overloaded - operator
    cout << endl <<"-----------------------------" << endl;
    cout << endl << "Testing overloaded - operator" << endl;
    cout << "-----------------------------" << endl;
    
    cout << "ew1 shift size:  " << ew1.testGetShift() << endl;
    cout << "ew2 shift size:  " << ew2.testGetShift() << endl << endl;
    cout << "- Doing the following operation: ew1 = ew1 - ew2" << endl;
    cout << "- ew1 should equal ew1 - ew2 " << endl;
    cout << "- The shift size represents the positive shift (ex: shift " <<
            "of -1 is equal to a shift of 25)" << endl;
    cout << "- Shift subtraction that results in zero will be set to a " <<
            "shift of 1 to ensure the word is shifted" << endl;
    cout << endl;
    
    ew1 = ew1 - ew2;
    cout << "ew1 shift size:  " << ew1.testGetShift() << endl << endl;
    
    cout << "- Testing edge cases for subtraction" << endl << endl;

    // edge case 1
    cout << "- Edge case 1: 15 - 10 should equal 5" << endl;
    cout << "- Creating two objects, sub1a shift = 15 and sub1b shift = 10"
    << endl;
    cout << "- Doing this operation: sub1a = sub1a - sub1b" << endl << endl;
    
    EncryptWord sub1a(WORD, 15);
    EncryptWord sub1b(WORD, 10);
    
    cout << "sub1a shift size:   " << sub1a.testGetShift() << endl;
    cout << "sub1b shift size:   " << sub1b.testGetShift() << endl;
    
    sub1a = sub1a - sub1b;
    cout << "sub1a shift size after operation: " << sub1a.testGetShift()
    << endl << endl;
    
    // edge case 2
    cout << "- Edge case 2: 24 - 25 should equal 25" << endl;
    cout << "- Creating two objects, sub2a shift = 24 and sub2b shift = 25"
    << endl;
    cout << "- Doing this operation: sub2a = sub2a - sub2b" << endl << endl;
    
    EncryptWord sub2a(WORD, 24);
    EncryptWord sub2b(WORD, 25);
    
    cout << "sub2a shift size:   " << sub2a.testGetShift() << endl;
    cout << "sub2b shift size:   " << sub2b.testGetShift() << endl;
    
    sub2a = sub2a - sub2b;
    cout << "sub2a shift size after operation: " << sub2a.testGetShift()
    << endl << endl;
    
    // edge case 3
    cout << "- Edge case 3: 25 - 25 should equal 1" << endl;
    cout << "- Creating two objects, sub2a shift = 25 and sub3b shift = 25"
    << endl;
    cout << "- Doing this operation: sub3a = sub3a - sub3b" << endl << endl;
    
    EncryptWord sub3a(WORD, 25);
    EncryptWord sub3b(WORD, 25);
    
    cout << "sub3a shift size:   " << sub3a.testGetShift() << endl;
    cout << "sub3b shift size:   " << sub3b.testGetShift() << endl;
    
    sub3a = sub3a - sub3b;
    cout << "sub3a shift size after operation: " << sub3a.testGetShift()
    << endl << endl;
    
    // EW: testing overloaded >, <, ==, != operator
    cout << endl << "---------------------------------------------" << endl;
    cout << endl << "Testing overloaded >, <, ==, and != operators" << endl;
    cout << "---------------------------------------------" << endl;
    
    cout << "ew1 shift size:  " << ew1.testGetShift() << endl;
    cout << "ew2 shift size:  " << ew2.testGetShift() << endl << endl;
    cout << "- Testing the the <, >, == and != operators" << endl;
    cout << endl;
    
    cout << "ew1 > ew2 -->  ";
    if (ew1 > ew2)
        cout << "true";
    else
        cout << "false";
    cout << endl;
    
    cout << "ew1 < ew2 -->  ";
    if (ew1 < ew2)
        cout << "true";
    else
        cout << "false";
    cout << endl << endl;
    
    cout << "ew1 == ew3 -->  ";
    if (ew1 == ew2)
        cout << "true";
    else
        cout << "false";
    cout << endl;
    
    cout << "ew1 != ew3 -->  ";
    if (ew1 != ew2)
        cout << "true";
    else
        cout << "false";
    cout << endl;
}

void testFF(string WORD) {
    // FF: copy ctor testing
    cout << endl << "-------------------------" << endl;
    cout << "Testing copy constructor" << endl;
    cout << "-------------------------" << endl;

    cout << "- Creating an object called ff1" << endl;
    cout << "- Inserting \"" << WORD << "\" into all ff1's indices" << endl;
    cout << "- Printing ff1's data\n" << endl;
    
    FindFault ff1;
    for (int i = 0; i < ff1.getCapacity(); i++) {
        ff1.insert(WORD);
        cout << "ff1[" << i << "]:  " << ff1.testGetShiftCode(i) << endl;
        chrono::seconds dura( 1);
        this_thread::sleep_for( dura );
    }
    
    cout << "ff1 total corrupt:   " << ff1.getTotalCorrupt() << endl;
    cout << "ff1 total encrypted: " << ff1.getTotalEncrypted() << endl;
    
    cout << endl << "- Using the copy ctor to create an object called ff2"
         << endl;
    cout << "- Doing this operation: FindFault ff2(ff1);" << endl;
    cout << "- ff2 should be the same as ff1 from above"<< endl << endl;
    
    FindFault ff2(ff1);
    
    for (int i = 0; i < ff1.getCapacity(); i++) {
        cout << "ff2[" << i << "]:  " << ff2.testGetShiftCode(i) << endl;
    }
    cout << "ff2 total corrupt:   " << ff2.getTotalCorrupt() << endl;
    cout << "ff2 total encrypted: " << ff2.getTotalEncrypted() << endl;
    
    
    // FF: testing overloaded assignment operator
    cout << endl << "--------------------------------------" << endl;
    cout << endl << "Testing overloaded assignment operator" << endl;
    cout << "--------------------------------------" << endl;
    cout << "- Printing ff1's data" << endl;
    cout << "- Creating an object called ff3 and populating each index with \""
         << WORD << "\"" << endl;
    cout << "- Printing ff3's data" << endl << endl;
    
    // printing ff1
    for (int i = 0; i < ff1.getCapacity(); i++) {
        cout << "ff1[" << i << "]:  " << ff1.testGetShiftCode(i) << endl;
    }
    cout << "ff1 total corrupt:   " << ff1.getTotalCorrupt() << endl;
    cout << "ff1 total encrypted: " << ff1.getTotalEncrypted() << endl << endl;
    
    // printing ff3
    FindFault ff3;
    for (int i = 0; i < ff3.getCapacity(); i++) {
        ff3.insert(WORD);
        cout << "ff3[" << i << "]:  " << ff3.testGetShiftCode(i) << endl;
        chrono::seconds dura( 1);
        this_thread::sleep_for( dura );
    }
    cout << "ff3 total corrupt:   " << ff3.getTotalCorrupt() << endl;
    cout << "ff3 total encrypted: " << ff3.getTotalEncrypted() << endl << endl;
    
    cout << "- Coping ff1 to ff3 via the overloaded assigment operator"<< endl;
    cout << "- Doing this operation: ff3 = ff1;" << endl;
    cout << "- ff3 should be the same as ff1 from above" << endl << endl;
    ff3 = ff1;
    
    // ff3 = ff1
    for (int i = 0; i < ff1.getCapacity(); i++) {
        cout << "ff3[" << i << "]:  " << ff3.testGetShiftCode(i) << endl;
    }
    cout << "ff3 total corrupt:   " << ff3.getTotalCorrupt() << endl;
    cout << "ff3 total encrypted: " << ff3.getTotalEncrypted() << endl << endl;
    
    
    // FF: testing overloaded + operator
    cout << endl << "-----------------------------" << endl;
    cout << endl << "Testing overloaded + operator" << endl;
    cout << "-----------------------------" << endl;
    cout << "- Creating an object called ff4 and populating each index with \""
         << WORD << "\"" << endl;
    cout << "- Printing data for ff4 and ff3" << endl << endl;
    
    // ff4
    FindFault ff4;
    for (int i = 0; i < ff4.getCapacity(); i++) {
        ff4.insert(WORD);
        cout << "ff4[" << i << "] shift size: ";
        cout << ff4.testGetShiftCode(i) << endl;
        chrono::seconds dura( 1);
        this_thread::sleep_for( dura );
    }
    cout << endl;
    
    // ff3
    for (int i = 0; i < ff1.getCapacity(); i++) {
        cout << "ff3[" << i << "] Shift size: "
        << ff3.testGetShiftCode(i) << endl;
    }
    
    cout << "\n- Doing the following operation at each index: ff3 = ff3 + ff4"
         << endl;
    cout << "- ff3's shift size should equal ff3 + ff4 for each index" << endl;
    cout << "- The shift size will \"wrap around\" if it is " <<
            "greater than the max shift size of 25" << endl;
    cout << "  (ex: shift of 26 is equal to 1)" << endl;
    cout << "- A shift sum of 50 will be set to a shift of 1 to ensure" <<
            " the shift is at least 1\n" << endl;
    
    ff3 = ff3 + ff4;
    // print ff3 again
    for (int i = 0; i < ff1.getCapacity(); i++) {
        cout << "ff3[" << i << "] Shift size: "
        << ff3.testGetShiftCode(i) << endl;
    }
    
    // FF: testing overloaded - operator
    cout << endl << "Testing overloaded - operator" << endl;
    cout << "-----------------------------" << endl;
    cout << "Printing data for ff4 and ff3\n" << endl;
    
    // ff4
    for (int i = 0; i < ff4.getCapacity(); i++) {
        cout << "ff4[" << i << "] shift size:  ";
        cout << ff4.testGetShiftCode(i) << endl;
    }
    cout << endl;
    
    // ff3
    for (int i = 0; i < ff1.getCapacity(); i++) {
        cout << "ff3[" << i << "] Shift size: "
        << ff3.testGetShiftCode(i) << endl;
    }
    
    cout << "\n- Doing the following operation at each index: ff3 = ff3 - ff4"
         << endl << endl;
    cout << "- ff3 should equal ff3 - ff4 for each index" << endl;
    cout << "- The shift size represents the positive shift (ex: shift " <<
    "of -1 is equal to a shift of 25)" << endl;
    cout << "- Shift subtraction that results in zero will be set to a " <<
    "shift of 1 to ensure the word is shifted" << endl;
    cout << endl;
    
    ff3 = ff3 - ff4;
    // print ff3 again
    for (int i = 0; i < ff1.getCapacity(); i++) {
        cout << "ff3[" << i << "] Shift size: "
        << ff3.testGetShiftCode(i) << endl;
    }
    
    // FF: testing overloaded ==  and != operator
    cout << endl << "Testing overloaded  == and != operators" << endl;
    cout << "---------------------------------------" << endl;
    cout << "- Printing data for ff3 and ff4" << endl;
    cout << "- Comparing shift sizes between ff3 and ff4" << endl;
    cout << "- Testing the == and != operators" << endl;
    cout << "- Returns true if ALL shift sizes are the same, and false if" <<
            " there are any difference in shift size" << endl << endl;
    
    // ff3
    for (int i = 0; i < ff1.getCapacity(); i++) {
        cout << "ff3[" << i << "] Shift size: "
        << ff3.testGetShiftCode(i) << endl;
    }
    cout << endl;
    
    // ff4
    for (int i = 0; i < ff4.getCapacity(); i++) {
        cout << "ff4[" << i << "] shift size:  ";
        cout << ff4.testGetShiftCode(i) << endl;
    }
    cout << endl;
    
    cout << "ff3 == ff4 -->  ";
    if (ff3 == ff4)
        cout << "true" << endl;
    else
        cout << "false" << endl;
    
    cout << "ff3 != ff4 -->  ";
    if (ff3 != ff4)
        cout << "true" << endl;
    else
        cout << "false" << endl;
    cout << endl;
}
