//
//  p5x.cpp
//  wangv2_P5
//
//  Created by VeeVee Wang on 12/7/17.
//  Copyright © 2017 VeeVee Wang. All rights reserved.
//

#include <iostream>
#include <string>
#include "Sequence.h"
#include "SequenceEnum.h"
#include "SeqExtract.h"
#include "SpasEnum.h"

using namespace std;

void printTitle(int);

int main(int argc, const char * argv[]) {
    unsigned capacity = 3;
    string tooShort = "hi";
    string theWord = "hello";
    
    SequenceEnum sequence;
    SeqExtract extract;
    SpasEnum spas;
    
    Sequence * ptr[capacity];
    ptr[0] = &sequence;
    ptr[1] = &extract;
    ptr[2] = &spas;
    
    for (unsigned i = 0; i < capacity; i++) {
        printTitle(i);
        cout << "isActive()            " << ptr[i]->isActive() << endl;
        cout << "enterWord(\"hi\")       " << ptr[i]->EnterWord(tooShort) << endl;
        cout << "enterWord(\"hello\")    " << ptr[i]->EnterWord(theWord)<< endl;
        cout << "isActive()            " << ptr[i]->isActive() << endl;
        cout << "getInvertWord()       " << ptr[i]->getInvertWord() << endl;
        if (i == 1) {
            cout << "emit(\"hel\")           "
            << static_cast<SeqExtract*>(ptr[i])->emit("hel") << endl;
        }
        cout << "emit()                " << ptr[i]->emit() << endl;
        cout << "isWord(\"hello\")       " << ptr[i]->isWord(theWord) << endl;
    }
    
    cout << endl;
    return 0;
}

void printTitle(int i) {
    if (i == 0)
        cout << endl << "SequencEnum" << endl;
    else if (i == 1)
        cout << endl << "SeqExtract" << endl;
    else
        cout << endl << "SpasEnum" << endl;
}
