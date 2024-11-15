#include <iostream>
#include <cstring>

using namespace std;

struct MyStruct
{
    int first;
    int second;

    int Sum()
    {
        return first+second;
    }
};

int main()
{   
    MyStruct a;
    a.first = 123;
    a.second = 456;

    cout << sizeof(a) << endl;
    cout << a.first << " " << a.second << " " << a.Sum() << endl;

    MyStruct *ptr_a = &a;
    cout << ptr_a->first << " " << ptr_a->second << " " << ptr_a->Sum() << endl;

    return 0;
}