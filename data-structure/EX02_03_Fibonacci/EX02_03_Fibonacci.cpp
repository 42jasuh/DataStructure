#include <iostream>

using namespace std;

int RecurFibonacci(int n)
{
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else        
        return RecurFibonacci(n-1) + RecurFibonacci(n-2);
}

int Fibonacci(int n)
{
    if (n==0)
        return 0;
    else if (n==1)
        return 1;
    else
    {
        int prev1 = 0;
        int prev2 = 1;
        int fn = 0;
        for (int i = 2; i < n+1; i++)
        {
            fn = prev1 + prev2;            
            prev1 = prev2;
            prev2 = fn;
        }
        return fn;
    }    
}

int main()
{
    cout << RecurFibonacci(10) << endl;
    cout << Fibonacci(10) << endl;
}