#include <iostream>
#include <random>

using namespace std;

int main()
{   

    random_device rd;
    mt19937 gen(rd());

    uniform_int_distribution<int> distrib(0, 99);

    int number = distrib(gen);

    while(1)
    {   
        int guess;
        cout << "입력: ";
        cin >> guess;

        if(guess == number)
        {
            cout << "정답: " << number << endl;
            break;
        }
        else if (guess > number)
            cout << "입력값이 크다\n";
        else
            cout << "입력값이 작다\n";
    }
    return 0;
}