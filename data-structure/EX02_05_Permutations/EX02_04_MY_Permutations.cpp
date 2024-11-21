#include <iostream>

#define ARRAY_SIZE 3

using namespace std;

void ShiftArrayLeft(char *arr, int n)
{
    char temp = arr[0];
    for (int i=1; i < n; i++)
        arr[i-1] = arr[i];
    arr[n-1] = temp;
}

void PrintArray(char *arr, int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;    
}

void GeneratePermutations(char *tempArr, char *inputArr, int left, int right)
{
    if (left==right)
    {
        PrintArray(inputArr, ARRAY_SIZE);
        swap(inputArr[1], inputArr[2]);
        PrintArray(inputArr, ARRAY_SIZE);
        swap(inputArr[1], inputArr[2]);
        return;
    }
    tempArr[left] = inputArr[left];
    GeneratePermutations(tempArr, inputArr, left+1, right);    
}

void final(char *temp, char *input, int left, int right)
{
   GeneratePermutations(temp, input, 0, 3);   
   for (int i = 0; i < 2; i++)
   {
      ShiftArrayLeft(input, 3);
      GeneratePermutations(temp, input, 0, 3);
   }  
}

void CustomPermutation(char *inputArr, int n)
{
    for (int i = 0; i < n-2; i++)
    {
        char tempArr[3] = {'0'};
        char input_arr[3] = {'0'};
        int j = i;
        for (int k = 0; k < 3; k++)
            input_arr[k] = inputArr[j++];
        final(tempArr, input_arr, 0, 3);
    }
}



int main()
{
   char input[] = {'a', 'b', 'c', 'd', 'e', 'f'};
   CustomPermutation(input, 6);
   return 0;
}