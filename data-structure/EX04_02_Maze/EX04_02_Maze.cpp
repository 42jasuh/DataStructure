#include <iostream>

#include "Stack.h"

using namespace std;

constexpr int kNumRows = 10;
constexpr int kNumCols = 9;

char maze[kNumRows][kNumCols] =
{
	{'1', '1', '1', '1', '1', '1', '1', '1', '1'},
	{'1', 'S', '0', '0', '0', '0', '0', '0', '1'},
	{'1', '1', '1', '1', '0', '1', '0', '1', '1'},
	{'1', '0', '0', '0', '0', '0', '0', '0', '1'},
	{'1', '0', '1', '1', '1', '1', '1', '1', '1'},
	{'1', '0', '0', '0', '0', '0', '0', '0', '1'},
	{'1', '1', '1', '1', '1', '0', '1', '1', '1'},
	{'1', '1', '1', '0', '0', '0', '1', '0', '1'},
	{'1', '0', '0', '0', '0', '0', '0', 'G', '1'}, // <- 'G'를 만나면 종료
	{'1', '1', '1', '1', '1', '1', '1', '1', '1'},
};

void PrintMaze()
{
	for (int j = 0; j < kNumRows; j++)
	{
		for (int i = 0; i < kNumCols; i++)
			cout << maze[j][i] << " ";
		cout << endl;
	}
}

struct Pos
{
	int row;
	int col;

	// 디버깅을 위한 편의 기능
	friend ostream& operator<<(ostream& os, const Pos& pos)
	{
		cout << "(" << pos.row << ", " << pos.col << ")" << flush;
		return os;
	}
};

// 모두 순회
void RecurMaze(Pos p)
{
	const char mark = maze[p.row][p.col];

	if (mark == '1')
		return;

	if (mark == 'G')
	{
		cout << "Found!" << endl;
		return;
	}

	if (mark == 'S' || mark =='0')
	{
		maze[p.row][p.col] = 'X';
		RecurMaze({ p.row - 1, p.col });
		RecurMaze({ p.row + 1, p.col });
		RecurMaze({ p.row, p.col - 1});
		RecurMaze({ p.row, p.col + 1});
	}
}

// 조기 종료 가능
int EarlyRecurMaze(Pos p)
{
	const char mark = maze[p.row][p.col];

	if (mark == 'G')
	{
		cout << "Found!" << endl;
		return 1;
	}

	if (mark != 'X' && mark != '1')
	{
		maze[p.row][p.col] = 'X';
		if (EarlyRecurMaze({ p.row - 1, p.col })) return 1;
		if (EarlyRecurMaze({ p.row + 1, p.col })) return 1;
		if (EarlyRecurMaze({ p.row, p.col - 1})) return 1;
		if (EarlyRecurMaze({ p.row, p.col + 1})) return 1;
	}
	return 0;
}

void StackMaze()
{
	Stack<Pos> s;

	Pos start = { 1, 1 }; // i = 1, j = 1  시작 지점
	//Pos start;
	//start.row = 1;
	//start.col = 1;

	s.Push(start); // s.Push({1, 1});	

	while (!s.IsEmpty())
	{
		Pos p = s.Top();
		s.Pop();

		cout << p << " "; // 디버깅 출력

		const char mark = maze[p.row][p.col];

		if (mark == 'G')
		{
			cout << "Found!" << endl;
			return;
		}
		if (mark != '1' && mark != 'X')
		{
			maze[p.row][p.col] = 'X';
			s.Push({ p.row - 1, p.col });
			s.Push({ p.row + 1, p.col });
			s.Push({ p.row, p.col - 1 });
			s.Push({ p.row, p.col + 1 });
		}
	}
}

int main()
{
	PrintMaze();

	/*RecurMaze({ 1, 1 });*/
	/*StackMaze();*/

	/*EarlyRecurMaze({1,1});*/

	cout << endl;	

	PrintMaze();

	return 0;
}
