#include <iostream>

using namespace std;

bool isEqual(const char str1[], const char str2[])
{   
    if (str1[0] == '\0' || str2[0] == '\0')
        return false;
    
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0')
    {
        if(str1[i] != str2[i])
            return false;
        i++;
    }
    if (str1[i] == str2[i])
        return true;
    return false;
}

int main()
{   
    const int kMaxStr = 100; // 전역 상수 소개

    while(1)
    {
        char string[kMaxStr];
        cin >> string;

        bool answer = isEqual("apples", string);
        if(answer)
        {
            cout << "종료\n";
            break;
        }
        else
        {   
            cout << "계속\n";
            main();
        }
    }
    return 0;
}