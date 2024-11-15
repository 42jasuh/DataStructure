#include <iostream>
#include <cassert>

using namespace std;

void InsertionSort(char* arr, int n)
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

int Count(char* arr, int n, char x)
{
	int count = 0;
	for (int i = 0; i < n; i++) // start index 사용
	{
		if (arr[i] == x)
			count++;
	}
	return count;
}


// 문제
// - 어떤 알파벳에 몇 번 나오는지로 출력
// - 예시) aaabbccdddeeeff -> a3b2c2d3e3f2
// - 알파벳은 총 26 글자	
int main()
{

	char arr[] = "ababcdfdceeedag";
	int n = sizeof(arr) - 1; // 마지막 안보이는 '\0' 제외

	// 글자가 하나이상이라고 가정
	assert(n >= 1);

	cout << arr << endl;

	// 풀이 1. 모든 알파벳에 대해서 Count()
	// 힌트: 소문자 알파벳 'a'~'z'는 int로는 97~122에 대응
	// 단점: 없는 알파벳도 세야 한다.

	// 표를 사용할 수도 있고 사용하지 않을 수도 있음
	int table[26] = { 0 }; // 모든 값을 0으로 초기화

	for (int i = 0; i < 26; i++)
	{   
        table[i] = Count(arr, n, char(i+97));
	}
	cout << endl;

	for (int i = 0; i < 26 && table[i] > 0; i++)
	{
		cout << char(i+97) << table[i];
	}
	cout << endl << endl;

	// 풀이 2. 정렬 후 찾기
	InsertionSort(arr, n);

	cout << arr << endl;

	char c = arr[0];
	int count = 1;

	cout << c;

	for (int i = 1; i < n; i++)
	{
		if (arr[i] == c)
		{
			count++;
		}
		else
		{
            cout << count;
            c = arr[i];
            count = 1;
            cout << c;
            
		}
	}
	cout << count << endl; // 마지막 count 출력
	return 0;
}