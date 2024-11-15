#include <iostream>
#include <cassert>
#include <cstring>

using namespace std;

struct Element
{
	int key;
	char value;
};


void Print(Element *arr, int size)
{        
    for (int i = 0; i < size; i++)
    {
        cout << arr[i].key << " ";        
    }
    cout << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i].value << " ";        
    }
    cout << endl;

}

int main()
{   
    // 안전성 -> key와 value가 모두 정렬됐을 때 안전하다고하다.
    {
        Element arr[] = {{3, 'c'}, {3, 'b'}, {3, 'a'}, {2, 'c'}, {2, 'b'}, {2, 'a'}};
        int size = sizeof(arr) / sizeof(arr[0]);
        
        for (int i = 0; i < size-1; i++)
        {            
            for (int j = i+1; j < size; j++)
            {
                if (arr[j].key < arr[i].key)
                {
                    swap(arr[j], arr[i]);
                }
                else if(arr[j].key == arr[i].key && arr[j].value < arr[i].value)
                {
                    swap(arr[j], arr[i]);
                }                
            }            
        }
        Print(arr, size);
    }
    return 0;
}