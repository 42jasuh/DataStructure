#include <iostream>
#include <cassert>

using namespace std;

void Print(int *arr, int size)
{        
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";        
    }
    cout << endl;
}

// 정렬이 잘 되어 있다면 O(n)으로 끝낼 수 있는 알고리즘이다.
void BubbleSort(int *arr, int size)
{
    for (int i = 0; i < size-1; i++)
    {   
        bool swapped = false;
        for (int j = 0; j < size-i-1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
            Print(arr, size);
        }
        if (swapped == false)
            break;
    }
}

int main()
{   
    int arr[] = {1, 2, 3, 4, 5};
    BubbleSort(arr, 5);
    Print(arr, 5);
    return 0;
}