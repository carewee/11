// Carrie Hadley
// April 6, 2015

#include "varArray.h"
#include <iostream>

using std::cout; using std::cin; using std::endl;

void output(int *arrayPtr, int size) {
    // prints the values in "arrayPtr" of "size"
    
    for (int i = 0; i < size; ++i){
        cout << arrayPtr[i] << " " ;
    }
    
}


int varArray::check(int *arrayPtr, int number, int size){
    // returns the index of the element in "arrayPtr" of "size"
    // that corresponds to the element holding "number"
    // if number is not in the array, returns -1
    
    for (int i = 0; i < size; ++i) {
        if (arrayPtr[i] == number)
            return i;
    }
    return -1;
}



void varArray::addNumber(int *& arrayPtr, int number, int &size){
    // adds "number" to the array pointed to by "arrayPtr" of "size".
    // if the number is not already there, if "number" is there - no action
    // Note, the size of the array is thus increased.
    
    int *tmp = new int[size + 1];
    
    if (check(arrayPtr, number, size) == -1) {
        for (int i = 0; i < size; ++i) {
            tmp[i] = arrayPtr[i];
        }
        
    tmp[size] = number;
    delete [] arrayPtr;
    arrayPtr = tmp;
    size++;
    }

}

void varArray::removeNumber(int *& arrayPtr, int number, int &size){
    // removes a "number" from the "arrayPtr" of "size".
    // if "number" is not there -- no action
    // note, "size" changes
    
    int index = check(arrayPtr, number, size);
    int *tmp = new int[size - 1];
    
    if (index == -1)
        return;
    
    for (int i = 0; i < size; ++i) {
        if (i < index)
            tmp[i] = arrayPtr[i];

        else
            tmp[i] = arrayPtr[i + 1];
    }

    delete [] arrayPtr;
    arrayPtr = tmp;
    size--;
}