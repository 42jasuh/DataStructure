#include <iostream>

using namespace std;

int main()
{
    int i; // 변수 정의
    i = 123; // 변수에 값 지정 (객체 레퍼런스 아님)

    // sizeof 소개
    cout << i << " " << sizeof(i) << endl;

    // int 출력
    cout << sizeof(int) << endl;

    // 4byte
    float f = 123.456f; // 마지막 f 주의

    // 8byte
    double d = 123.456; // f 불필요
    
    // 문자
    char c = 'a';
    cout << c << " " << sizeof(c) << endl;

    // 문자열
    char str[] = "Hello, World!";
    cout << str << " " << sizeof(str) << endl;

    // 형변환
    i = 987.654;

    // double -> int 소수점 버림
    cout << "int from double " << i << endl; //

    // 형변환 float -> double
    f = 567.89;

    // 기본 연산자
    i += 100;
    i += 1;
    cout << i << endl; 

    // boolean
    bool is_good = true;

    cout << "is_good: " << is_good << endl;
    cout << boolalpha << true << endl;

    is_good = false;

    cout << "is_good " << is_good << endl;
    cout << boolalpha << false << endl;

    // 비교
    cout << (3==3) << endl;
    cout << ('a' != 'c') << endl;

    // 영역(scope)
    {
        int i = 345;
        cout << i << endl;
    }

    cout << i << endl;
    
    return 0;
}
