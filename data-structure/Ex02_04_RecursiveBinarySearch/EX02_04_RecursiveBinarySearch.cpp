#include <iostream>

using namespace std;

int RecurBinarySearch(int *arr, int left, int right, int x)
{
    if (left <= right)
    {
        int mid = (left+right)/2;

        if (arr[mid] == x)
            return mid;
        if (left == right && arr[mid] != x)
            return -1;
        if (arr[mid] < x)
            left = mid+1;
        else if (arr[mid] > x)
            right = mid-1;
        RecurBinarySearch(arr, left, right, x);
    }
}

int main()
{
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout << RecurBinarySearch(arr, 0, size-1, 10);
    return 0;
}