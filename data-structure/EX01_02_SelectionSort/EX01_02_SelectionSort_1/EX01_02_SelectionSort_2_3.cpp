#include <iostream>
#include <cassert>
#include <cstring>

using namespace std;

void Print(int *arr, int size)
{        
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";        
    }
    cout << endl;
}

int main()
{
	// 5 개 정렬
	{
		int arr[] = {5, 4, 3, 2, 1};
		int size = sizeof(arr) / sizeof(arr[0]);
		assert(size > 0); // size가 1이상이라고 가정

		// TODO:
        for (int i = 0; i < size-1; i++)
        {               
            int index = i;
            int min = arr[i];
            for (int j = i+1; j < size; j++)
            {
                if (arr[j] < min)
                {
                    min = arr[j];
                    index = j;
                }
            }
            swap(arr[i], arr[index]);            
        }        
        Print(arr, size);
	}    
    return 0;
}