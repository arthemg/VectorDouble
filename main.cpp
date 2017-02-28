/**
 * CLion was used to compile
 * Artsem Holdvekht
 * CSC 340
 * Assignment 7
 * 18 November 2016
 */
#include <iostream>
#include "vector_double.h"

int main() {

    Vector_double vector1, vector2; //init 2 vectors

    cout<<"-----------------Setting Up Vector------------------"<<endl;
    vector1.generateVec();
    cout<<endl;

    cout<<"--------------Contents of Vector1------------------"<<endl;
    cout<<"The content of V1 is: "<<vector1<<" "<<endl;
    cout<<endl;

    cout<<"-------------- Capacity of Vector1-----------------"<<endl;
    cout<<"The capacity: "<<vector1.capacity()<<endl;
    cout<<endl;

    cout<<"-------------- Vector1 Size-------------------------"<<endl;
    cout<<"The actual size is: "<<vector1.size_Vector()<<endl;
    cout<<endl;

    cout<<"-------------- Check Vector1 empty?------------------"<<endl;
    cout<<vector1.empty()<<endl;
    cout<<endl;

    cout<<"--------------- Testing copy constructor--------------"<<endl;
    vector2 = vector1;
    cout<<"Vector 1: "<<vector1<<" "<<endl;
    cout<<"Vector 2: "<<vector2<<" "<<endl;
    cout<<endl;

    cout<<"--------------- Testing copy constructor 2--------------"<<endl;
    Vector_double vector3(vector1);
    cout<<"Vector 1: "<<vector1<<" "<<endl;
    cout<<"Vector 3: "<<vector3<<" "<<endl;
    cout<<endl;

    cout<<"---------------Inserting element into Vector 1--------"<<endl;
    cout<<"Old Capacity: "<<vector1.capacity()<<endl;
    cout<<"Old size: "<<vector1.size_Vector()<<endl;
    vector1.insert(5, 66.01);
    cout<<"Inserting 66.01 into the index 5( Our index starts from zero)"<<endl;
    cout<<"The new Vector 1 is: "<<vector1<<" "<<endl;
    cout<<"New Capacity: "<<vector1.capacity()<<endl;
    cout<<"New size: "<<vector1.size_Vector()<<endl;
    cout<<endl;

    cout<<"-------------- Pop Back from Vector 1 ----------------"<<endl;
    vector1.pop_back();
    cout<<"The new Vector 1 is: "<<vector1<<" "<<endl;
    cout<<"New Capacity: "<<vector1.capacity()<<endl;
    cout<<"New size: "<<vector1.size_Vector()<<endl;
    cout<<endl;

    cout<<"-------------- Push Back to Vector 1 ----------------"<<endl;
    vector1.push_back(99.99);
    vector1.push_back(100.01);
    cout<<"The new Vector 1 is: "<<vector1<<" "<<endl;
    cout<<"New Capacity: "<<vector1.capacity()<<endl;
    cout<<"New size: "<<vector1.size_Vector()<<endl;
    cout<<endl;

    cout<<"-------------- Resize to a smaller Vector 1 ----------------"<<endl;
    vector1.resize(4);
    cout<<"Resizing Vectro 1 to a capacity 4."<<endl;
    cout<<"The new Vector 1 is: "<<vector1<<" "<<endl;
    cout<<"New Capacity: "<<vector1.capacity()<<endl;
    cout<<"New size: "<<vector1.size_Vector()<<endl;
    cout<<endl;

    cout<<"-------------- Resize to a larger Vector 2 ----------------"<<endl;
    cout<<"Old Capacity: "<<vector2.capacity()<<endl;
    cout<<"Old size: "<<vector2.size_Vector()<<endl;
    vector2.resize(145);
    cout<<"Resizing Vectro 2 to a capacity 145."<<endl;
    cout<<"The new Vector 2 is: "<<vector2<<" "<<endl;
    cout<<"New Capacity: "<<vector2.capacity()<<endl;
    cout<<"New size: "<<vector2.size_Vector()<<endl;
    cout<<endl;

    cout<<"-------------- Shrink to fit Vector 2 ----------------"<<endl;
    cout<<"Old Capacity: "<<vector2.capacity()<<endl;
    cout<<"Old size: "<<vector2.size_Vector()<<endl;
    vector2.shrink_to_fit();
    cout<<"Vector 2 is: "<<vector2<<" "<<endl;
    cout<<"New Capacity: "<<vector2.capacity()<<endl;
    cout<<"New size: "<<vector2.size_Vector()<<endl;
    cout<<endl;

    return 0;
}
