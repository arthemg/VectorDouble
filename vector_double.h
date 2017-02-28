/**
 * CLion was used to compile
 * Artsem Holdvekht
 * CSC 340
 * Assignment 7
 * 18 November 2016
 */

#include <iostream>
#include <exception>
#include <stdlib.h>

using namespace std;

#ifndef _VECTOR_DOUBLE_H_
#define _VECTOR_DOUBLE_H_

const int DEF_CAPACITY = 20; //default constant capacity for a default constructor

class Vector_double
{

private:

    int cap;        //total capacity of a vector
    int size;       //actual number of values in the vector
    double *vector; // pointer to a vector

public:

    //destructor: to release any memory used by the object
    ~Vector_double();

    //default constructor
    Vector_double();

    //explicit constructor with the specific initial capacity
    explicit Vector_double(int len);

    //copy constructor
    Vector_double(const Vector_double &vec);

    //overloaded assignment operator
    Vector_double operator=(const Vector_double &vec);

    //return capacity
    int capacity();

    //return the size of the vector
    int size_Vector();

    //check if the vector is empty
    bool empty();

    //insert an element to a specific position
    void insert(int idx, double val);

    //remove last element from vector
    void pop_back();

    //adds an element to the end
    void push_back(double val);

    //resize the given vector
    void resize(int newCap);

    //shrink to fit (capacity of vector = its actual length)
    void shrink_to_fit();

    //Generating a vector of a specific size and populating it with random double values
    void generateVec();

    //overloading ostream operator to print out the vector
    friend ostream &operator <<(ostream &out, Vector_double &vec);

};

#endif

