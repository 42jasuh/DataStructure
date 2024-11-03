#include <iostream>

using namespace std;

int main()
{   
    int number;

    cin >> number;

    // if (number % 2 ==0)
    // {
    //     cout << "짝수입니다.\n";
    // }
    // else
    //     cout << "홀수입니다.\n";
    // return 0;

    // cout << (number%2 == 0 ? "짝수입니다" : "홀수입니다.") << endl;

    switch (number)
    {
        case 0:
            cout << "0 입니다." << endl;
            break;
        default:
            cout << "그 외 숫자입니다." << endl;
            break;
    }
    return 0;

}