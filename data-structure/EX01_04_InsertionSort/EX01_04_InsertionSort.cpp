#include <iostream>

using namespace std;

void Print(int *arr, int size)
{        
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";        
    }
    cout << endl;
}

void InsertionSort(int *arr, int size)
{    
    for (int i = 1; i < size; i++)
    {   
        int key = arr[i];
        for (int j = i-1; 0 <= j; j--)
        {
            if(arr[j] > arr[j+1])
            {
                arr[j+1] = arr[j];
                arr[j] = key;
            }
            else
            {                
                break;
            }
        }
        
        Print(arr, size);
    }
}

int main()
{   
    int arr[] = {5, 4, 3, 2, 1};

    InsertionSort(arr, 5);

    return 0;
}