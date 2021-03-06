// Carrie Hadley
// April 6, 2015

#include "varArray.h"
#include <iostream>

using std::cout; using std::cin; using std::endl;

varArray::varArray() { // constructor
    size = 0;

}


varArray::varArray(const varArray& origin) { // copy constructor
    dArray = new int[origin.size];
    this->size = origin.size;
    for(int i =0; i < size; ++i)
        dArray[i] = origin.dArray[i];
}


varArray& varArray::operator=(const varArray& origin){ // overloaded assignment
    dArray = new int[origin.size];
    this->size = origin.size;
    for(int i =0; i < size; ++i)
        dArray[i] = origin.dArray[i];
    return *this;
}


varArray::~varArray() { // deconstructor
    delete[] dArray;
}


void varArray::output() {
    // prints the values in "dArray" of "size"
    
    for (int i = 0; i < size; ++i){
        cout << dArray[i] << " " ;
    }
    cout << endl;
}


int varArray::check(int number){
    // returns the index of the element in "dArray" of "size"
    // that corresponds to the element holding "number"
    // if number is not in the array, returns -1
    
    for (int i = 0; i < size; ++i) {
        if (dArray[i] == number)
            return i;
    }
    return -1;
}


void varArray::addNumber(int number){
    // adds "number" to the array pointed to by "dArray" of "size".
    // if the number is not already there, if "number" is there - no action
    // Note, the size of the array is thus increased.
    
    int *tmp = new int[size + 1];
    
    if (check(number) == -1) {
        for (int i = 0; i < size; ++i) {
            tmp[i] = dArray[i];
        }
        
    tmp[size-1] = number;
    delete [] dArray;
    dArray = tmp;
    size++;
    }

}


void varArray::removeNumber(int number){
    // removes a "number" from the "dArray" of "size".
    // if "number" is not there -- no action
    // note, "size" changes
    
    int index = check(number);
    int *tmp = new int[size - 1];
    
    if (index == -1)
        return;
    
    for (int i = 0; i < size; ++i) {
        if (i < index)
            tmp[i] = dArray[i];

        else
            tmp[i] = dArray[i + 1];
    }

    delete [] dArray;
    dArray = tmp;
    size--;
}