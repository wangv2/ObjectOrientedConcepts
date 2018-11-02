//
//  List.h
//  List
//
//  Created by VeeVee Wang on 10/23/17.
//  Copyright © 2017 VeeVee Wang. All rights reserved.
//

#ifndef List_h
#define List_h

class List {
public:
    List(int);
    ~List();
    List(const List&);
    List& operator = (const List&);
    void addElement(int);
    
private:
    int *array;
    int capacity;
    int numElements;
    void resize();
    
} ;

#endif /* List_h */
