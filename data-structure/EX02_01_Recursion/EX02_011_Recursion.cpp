#include <iostream>

using namespace std;

void RecurFunc1(int count)
{
    if (count == 0)
        return;
    cout << count << endl;
    RecurFunc1(count-1);
}

void RecurFunc2(int count)
{
    if (count == 0)
        return;    
    RecurFunc2(count-1);
    cout << count << endl;
}

int main()
{   
    // RecurFunc1과 RecurFunc2 차이 이해하기
    RecurFunc1(5);
    RecurFunc2(5);
    return 0;
}