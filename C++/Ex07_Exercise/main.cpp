#include <iostream>

using namespace std;

float f1()
{
    float answer;
    int scores[] = {20, 40, 80, 60, 99};
    int cnt = sizeof(scores)/sizeof(int);

    for(int i = 0; i < cnt; i++)
    {
        answer += (float)scores[i];
    }
    answer = answer/cnt;
    cout << answer << endl;
    return answer;    
}

int f2()
{   
    int answer = 0;
    for(int i = 1; i < 101; i++)
    {
        answer += (i*i);        
    }
    cout << answer;
    return answer;
}

int f3()
{
    int n;
    cin >> n;
    if (n==1 || n==2 || n==12)
        cout << "겨울\n";
    else if (n==9||n==10||n==11)
        cout << "가을\n";
    else if (n==6||n==7||n==8)
        cout << "여름\n";
    else if (n==3||n==4||n==5)
        cout << "봄\n";
    return 0;
}

int f4()
{
    int n;
    cin >> n;

    for(int i = 1; i < 10; i++)
    {
        cout << n << " * " << i << " = " << n*i << endl;
    }
    return 0;
}

bool f5()
{
    char str[100];
    cin >> str;

    int size=0;
    for (int i = 0; str[i] != '\0'; i++)
        size += 1;

    int half = size / 2;

    for(int i = 0; i < half; i++)
        if(str[i] != str[size-i-1])
            return false;
    return true;
}

void f6()
{
    int input, cur, target;
    cur = 0;
    target = 1;

    cin >> input;

    for(int i = 1; i < input+1; i++)
    {   
        if (i == input)
            cout << i;
        else if (cur != target)
        {
            cout << i << " ";
            cur += 1;
        }
        else if (cur == target)
        {
            cout << endl;
            target += 1;
            cur = 1;
            cout << i << " ";
        }
    }
}

int main()
{   
    return 0;
}