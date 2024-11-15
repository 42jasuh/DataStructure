#include <iostream>

using namespace std;

bool CheckSorted(int* arr, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		if (arr[i] > arr[i + 1])
			return false;
	}

	return true;
}

void Print(int* arr, int size)
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

int main()
{
	// 오른쪽으로 하나씩 밀기
	{
		int arr[] = {6, 5, 4, 3, 2, 1};
		int n = sizeof(arr) / sizeof(arr[0]);		

        for (int i = 1; i < n; i ++)
        {
        int j = i;
        int key = arr[i];
            for (; 0 < j && arr[j-1] > key; j--)
            {               
                if (key < arr[j-1])
                {
                    arr[j] = arr[j-1];
                    cout << "Inner ";
                    Print(arr, n);
                }
            }
            arr[j] = key;            
            cout << "Outer ";
            Print(arr, n);
        }
	}
}