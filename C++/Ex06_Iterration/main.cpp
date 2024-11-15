#include <iostream>

using namespace std;

int main()
{   
    // 반복 출력
    for (int i = 0; i < 10; i++)
    {
        cout << i << " ";
    }
    cout << endl;

    int my_array[] = {1, 2, 3, 4, 5, 4, 3, 2, 1};

    // 배열 출력
    for (int i = 0; i < sizeof(my_array) / sizeof(int); i++)
    {
        cout << my_array[i] << " ";
    }
    cout << endl;

    // 문자열 출력
    char my_string[] = "Hello\0, World!";
    for (int i = 0; my_string[i] != '\0'; i++)
        cout << my_string[i];
    cout << endl;    

    // while 기본 예제
    int i = 0;
    while (true)
    {
        cout << i << " ";
        i++;
        if (i==10)
            break;
    }
    cout << endl;
    //

    i = 0;
    while (true)
    {        
        if (my_string[i] == '\0')
            break;
        cout << my_string[i];
        i++;
    }
    cout << endl;
    return 0;
}