#include <iostream>

using namespace std;

int MySwapValue(int i, int j)
{
    int temp = i;
    i = j;
    j = temp;

    return 0;
}

void MySwapPtr(int *i, int *j)
{
    int temp;
    temp = *i;
    *i = *j;
    *j = temp;
}


void MySwapRef(int &i, int &j)
{
    int temp;
    temp = i;
    i = j;
    j = temp;
}

void SwapWithoutTemp(int &i, int &j)
{
    i = i + j;
    j = i - j;
    i = i - j;
}

void PrintIsAscend()
{
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            cout << i << " " << j << " ";
            if (i <= j)
                cout << boolalpha << true << endl;
            else
                cout << boolalpha << false << endl;
        }
    }
}

void AscendingSort(int i=5)
{   
    int arr[2];
    for(int j = 0; j < i+1; j++)
    {
        for(int k = 0; k < i+1; k++)
        {   
            arr[0] = j;
            arr[1] = k;
            if (j > k)
            {
                swap(arr[0], arr[1]);
                cout << j << " " << k << " ";
                
            }
            else{
                cout << j << " " << k << " ";
            }
            cout << boolalpha << true << endl;

        }
    }
}

int main()
{
    {
        int a = 3;
        int b = 2;

        // cout << a << " " << b << endl;        
        // TODO:
        // MySwapRef(a, b);
        // cout << a << " " << b << endl;

        // int arr[] = {3, 2};
        // cout << arr[0] << " " << arr[1] << endl;
        // TODO:
        // MySwapRef(arr[0], arr[1]);
        // cout << arr[0] << " " << arr[1] << endl;

        // cout << a << " " << b << endl;
        // PrintIsAscend();
        // cout << a << " " << b << endl;

        // cout << a << " " << b << endl;
        // AscendingSort();
        // cout << a << " " << b << endl;

        // cout << a << " " << b << endl;
        // SwapWithoutTemp(a, b);
        // cout << a << " " << b << endl;

    }
    return 0;
}