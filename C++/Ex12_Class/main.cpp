#include <iostream>
using namespace std;

class MyClass
{
public:
    MyClass()
    {
        cout << "MyClass()" << endl;
        cout << "this " << this << endl;
    }

    MyClass(int number)
    {
        cout << "MyClass(int number)" << endl;
        cout << "this " << this << endl;

        // ptr
        this->number_ = number;
    }

    ~MyClass()
    {
        cout << "~MyClass()" << endl;
    }

    void Print()
    {
        cout << number_ << endl;
    }

    void Increment(int a)
    {
        number_ += a;
    }

private:
    int number_ = 0;
};


int main()
{   
    MyClass my_class1;
    MyClass my_class2(123);

    cout << &my_class1 << endl;
    cout << &my_class2 << endl;;

    my_class1.Print();
    my_class2.Print();

    my_class1.Increment(1);

    // 배열 사용 가능
    // 포인터 사용 가능

    return 0;
}