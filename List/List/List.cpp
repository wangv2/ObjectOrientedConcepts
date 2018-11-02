//
//  List.cpp
//  List
//
//  Created by VeeVee Wang on 10/23/17.
//  Copyright © 2017 VeeVee Wang. All rights reserved.
//

#include <stdio.h>
#include "List.h"

// PUBLIC METHODS

// constructor
List::List(int cap) {
    this->capacity = cap;
    this->numElements = 0;
    array = new int[capacity];
}

// desctructor
List::~List() {
    delete [] array;
}

// copy constructor
List::List(const List& obj) {
    capacity = obj.capacity;
    numElements = obj.numElements;
    
    array = new int(capacity);
    
    for (int i = 0; i < numElements; i++) {
        array[i] = obj.array[i];
    }
}

// overloaded assingment operator
List& List:: operator = (const List& obj) {
    if (this != &obj) {
        capacity = obj.capacity;
        numElements = obj.numElements;
        
        delete[] array;
        
        array = new int(capacity);
        
        for (int i = 0; i < numElements; i++) {
            array[i] = obj.array[i];
        }
    }
    return *this;
}

// adding an element
void List::addElement(int el) {
    if (numElements < capacity) {
        array[numElements] = el;
        numElements++;
    }
}


// private methods
int *array;
int capacity;
int numElements;
void resize();
