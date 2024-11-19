#include <iostream>

using namespace std;

int Sum(int *arr, int n)
{   
    int res = 0;
    for (int i = 0; i < n; i++)
        res += arr[i];
    return res;
}

// 시간 O(n) 공간 O(n)
int RecurSum(int *arr, int n)
{    
    if (n <= 0)
        return 0;
    else
        return RecurSum(arr, n-1) + arr[n-1];
}

int main()
{
    // Sum vs RecurSum

    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << Sum(arr, n) << endl;
    cout << RecurSum(arr, n) << endl;

    return 0;
}