#include <iostream>
#include <iomanip>      // std::setw

#include <cassert>

using namespace std;

void InsertionSort(int* arr, int n)
{
	int i, key, j;
	for (i = 1; i < n; i++) {
		key = arr[i];
		j = i - 1;

		while (j >= 0 && arr[j] > key) // <- while 사용
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

void PrintHelper(int* arr, int n, int left, int right)
{
	cout << "[" << left << "," << right << "]" << endl;

	cout << "Indices: ";
	for (int i = left; i <= right; i++)
		cout << setw(2) << i << " ";
	cout << endl;

	cout << "Values : " << setw(2);
	for (int i = left; i <= right; i++)
		cout << setw(2) << arr[i] << " ";
	cout << endl;
}

int BinarySearch(int* arr, int n, int x) // 이진 탐색
{
	int left = 0;
	int right = n - 1;

	while (left <= right)
	{
		PrintHelper(arr, n, left, right);

        int middle = (int)(left+right)/2;		

		if (x > arr[middle])
		{			
            left = middle + 1;
			cout << "right " << right << endl;
		}
		else if (x < arr[middle])
		{
            right= middle-1;
			cout << "left " << left << endl;
		}
		else
		{
			cout << "Found " << middle << endl;
			return middle;
		}
		
	}

	cout << "Not found" << endl;
	return -1; // Not found
}

int main()
{	
	int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int n = sizeof(arr) / sizeof(arr[0]);

	assert(n > 0);
	
    InsertionSort(arr, n);
	int res = BinarySearch(arr, n, 10);
	
    cout << res << endl;

	return 0;
}