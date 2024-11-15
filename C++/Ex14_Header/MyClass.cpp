#include "MyClass.h"

#include <iostream>

using namespace std;

MyClass::MyClass()
{
    cout << "MyClass()" << endl;
}

MyClass::MyClass(int number)
{
    cout << "MyClass(int number)" << endl;
    this->number_ = number;
}

MyClass::~MyClass()
{
    cout << "~MyClass()" << endl;
}

void MyClass::Increment(int a)
{
    number_ += a;
}

