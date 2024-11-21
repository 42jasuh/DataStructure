#include <iostream>

using namespace std;

void PrintArray(char *arr, int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void RecurPermutations(char *arr, int left, int right)
{
    if (left == right)
    {
        for (int i = 0; i <= right; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    else
    {
        for (int i = left; i <= right; i++)
        {
            swap(arr[left], arr[i]);
            RecurPermutations(arr, left+1, right);
            swap(arr[left], arr[i]);
        }
    }
}

int main()
{   
    char arr[] = {'a', 'b', 'c', 'd'};
    int size = sizeof(arr)/sizeof(arr[0]);
    RecurPermutations(arr, 0, size-1);
 
}