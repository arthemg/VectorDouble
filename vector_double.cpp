/**
 * CLion was used to compile
 * Artsem Holdvekht
 * CSC 340
 * Assignment 7
 * 18 November 2016
 */

#include "vector_double.h"

/**
 * Destructor to remove any allocated memory
 */
Vector_double::~Vector_double()
{
    if(vector != NULL)
    {
        delete [] vector;
        vector = NULL;
        size = 0;
    }
}

/**
 * Default constructor with the initial capacity as DEF_CAPACITY
 * @return object of type Vector_double with default capacity
 */
Vector_double::Vector_double()
{
    cap = DEF_CAPACITY;
    size = 0;
    try
    {
        vector = new double[cap];
    }
    catch (bad_alloc &ba)
    {
        cerr<<"Vector_double::Vector_double(): "<<ba.what()<<endl;
    }


}

/**
 * Constructor with the specific capacity of the vector
 * @return object of type Vector_double with specific capacity
 */
Vector_double::Vector_double(int len)
{
    cap = len;
    size = 0;
    try
    {
        vector = new double[cap];
    }
    catch (bad_alloc &ba)
    {
        cerr<<"Vector_double::Vector_double(int len): "<<ba.what()<<endl;
    }
}

/**
 * Copy constructor for Vector_double object
 * @param vec Vector_double object to be copied
 * @return copy of &vec of Vector_double object
 */
Vector_double::Vector_double(const Vector_double &vec)
{
    cap = vec.cap;
    size = vec.size;

    try
    {
        vector = new double[cap];
    }
    catch (bad_alloc &ba)
    {
        cerr<<"Vector_double::Vector_double(const Vector_double &vec): "<<ba.what()<<endl;
    }

    for(int i = 0; i < size; i++)
    {
        vector[i] = vec.vector[i];
    }

}

/**
 * Overloading = operator
 * @param rhs Vector_double object to be assigned to the left side
 * @return new Vector_double object that is a copy of &rhs
 */
Vector_double Vector_double::operator=(const Vector_double &rhs)
{
    cap = rhs.cap;

    if(size > 0)
    {
        delete [] vector; //release old memory
    }

    size = rhs.size; //set new size for the vector

    if(size <= 0)
    {
        vector = NULL;
    }
    else
    {
        try
        {
            vector = new double[cap];
        }
        catch (bad_alloc &ba)
        {
            cerr<<"Vector_double Vector_double::operator=(const Vector_double &vec): "<<ba.what()<<endl;
        }

        for(int i = 0; i < size; i++)
        {
            vector[i] = rhs.vector[i];
        }
    }
    return (*this);
}

/**
 *
 * @return the total capacity of the vector
 */
int Vector_double::capacity()
{
    return cap;
}

/**
 *
 * @return the length of the vector
 */
int Vector_double::size_Vector()
{
    return size;
}

/**
 *
 * @return boolean after checking if the vector is empty
 */
bool Vector_double::empty()
{
    if(size == 0)
    {
        cout<<"Vector is empty."<<endl;
        return true;
    }
    else
    {
        cout<<"Vector is NOT empty."<<endl;
        return false;
    }

}

/**
 * Resize vector to a new capacity, can be larger or smaller than original
 * @param newCap new capacity of the vector
 */
void Vector_double::resize(int newCap)
{
    cap = newCap;

    //change size in case we are shrinking the vector
    if(size > cap)
    {
        size = cap;
    }

    double *tmpVec = new double[cap];

    for(int i = 0; i < size; i++)
    {
        tmpVec[i] = vector[i];
    }

    delete[] vector; //release old memory
    vector = tmpVec; //assign new pointer

}

/**
 * inserting a value to a specific point in the vector
 * @param idx position where to insert new value
 * @param val value to be inserted
 */

void Vector_double::insert(int idx, double val)
{
    if(size == cap)
    {
        resize(cap*2);
    }


    for(int i = size; i > idx; i--)
    {
        vector[i] = vector[i-1];
    }

    vector[idx] = val;
    size++;
}

/**
 * Removes the last element from the vector
 */
void Vector_double::pop_back()
{
    double *tmpVec = NULL;

    if(vector != NULL)
    {
         tmpVec = new double[cap];
        for(int i = 0; i < (size -1); i++)
        {
            tmpVec[i] = vector[i];
        }

        delete[] vector; //release old memory
        vector = tmpVec; //new pointer
        size--;         //decrease size
    }
}

/**
 * Adds value to the end of the vector
 * @param val value to be added to the end of the vector
 */
void Vector_double::push_back(double val)
{
    if(size == cap)
    {
        resize(cap*2);
    }

    vector[size] = val; //add value at the end
    size++;             // increase size
}

/**
 * Shrink the size of the vector to the actual number of the lements
 */
void Vector_double::shrink_to_fit()
{
    resize(size);
}

/**
 * Overloading cout>> to print the contentof the vecto
 * @param out ostream
 * @param vec vectro to be printed
 * @return retuns ostream of vector
 */
ostream &operator <<(ostream &out, Vector_double &vec)
{
    for(int i = 0; i < vec.size; i++)
    {
        out<< vec.vector[i]<<" ";
    }

    return out;
}

/**
 * Creates a vector of specified legth and populates it with random double values
 */
void Vector_double::generateVec()
{
    int capacity;
    double random;
    cout << "Please enter the total capacity for your vector: ";
    cin >> capacity;

    (*this).resize(capacity);
    (*this).cap = capacity;
    (*this).size = capacity;

    for(int i = 0; i < cap; i++)
    {
        //generate random double number from 1 -25
        random = (1.0 + ((double)rand()/(RAND_MAX/100)));

        //round of the random to only 2 decimal places
        double scale = 0.01;
        random = (int)(random/scale)* scale;

        //populate vector with random values.
        (*this).vector[i] =random;
    }

}