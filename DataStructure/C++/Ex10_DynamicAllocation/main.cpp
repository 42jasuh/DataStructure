#include <iostream>
#include <string.h>

using namespace std;

int Min(int a, int b)
{
    return a < b ? a : b;
}

const int kMaxStr = 100;

int main()
{   
    char str1[] = "Hello, World!";
    char str2[kMaxStr];

    memcpy(str2, str1, Min(sizeof(str1), sizeof(str2)));
    cout << str2 << endl;

    // 동적 할당
    char *dynamic_array = new char[kMaxStr];

    // 주의: 동적할당 메모리는 변수 사이즈가 포인터 사이즈
    memcpy(dynamic_array, str1, kMaxStr);
    cout << dynamic_array << endl;

    cout << str1 << " " << str2 << " " << dynamic_array << endl;
    cout << size_t(str1) << " " << size_t(str2) << " " << size_t(dynamic_array) << endl;

    delete[] dynamic_array;
    return 0;
}