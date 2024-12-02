#include "SparseMatrix.h"

#include <algorithm>
#include <cassert>
#include <iostream>

using namespace std;

// capacity는 자료형을 받으려는 배열의 크기, num_terms_는 실제 MatrixTerm의 개수
SparseMatrix::SparseMatrix(int num_rows, int num_cols, int capacity)
{
	MatrixTerm* terms_ = new MatrixTerm[capacity];
	num_rows_ = num_rows;
	num_cols_ = num_cols_;
	capacity_ = capacity;
	num_terms_ = 0;
}

// 복사 생성자 (b를 복사)
SparseMatrix::SparseMatrix(const SparseMatrix& b)
{
	if (b.capacity_ > 0)
	{
		MatrixTerm* terms_ = new MatrixTerm[b.capacity_];
		num_rows_ = b.num_rows_;
		num_cols_ = b.num_cols_;
		capacity_ = b.capacity_;
		num_terms_ = b.num_terms_;
	}

	memcpy(terms_, b.terms_, sizeof(MatrixTerm) * b. num_terms_);
}

SparseMatrix::~SparseMatrix()
{
	if  (terms_) delete[] terms_;
}

void SparseMatrix::SetValue(int row, int col, float value)
{
	if (value == 0.0f) return; // value가 0이 아닌 term만 저장

	// 정렬하지 않는 경우
	// assert(capacity_ > num_terms_);
	// terms_[num_terms_].row = row;
	// terms_[num_terms_].col = col;
	// terms_[num_terms_].value = value;
	// num_terms_++;

	// 정렬하는 경우(이미 정렬이 되어 있다고 가정)
	int key = col + num_cols_ * row;
	int i = 0;
	for (; i < num_terms_; i++)
	{
		int key_i = terms_[i].col + num_cols_ * terms_[i].row;
		if (key_i == key)
		{
			// 덮어쓰고 끝내기
			terms_[i].row = row;
			terms_[i].col = col;
			terms_[i].value = value;
			return;
		}
		else if (key_i > key)
			break;
		
		// 끝까지 하나씩 밀고 추가해야 하는 상황
		assert(capacity_ > num_terms_);
		num_terms_++;
	}


}

float SparseMatrix::GetValue(int row, int col) const // 맨 뒤의 const는 함수 안에서 멤버 변수의 값을 바꾸지 않겠다는 의미
{
	// TODO: key = col + num_cols * row;

	return 0.0f;
}

SparseMatrix SparseMatrix::Transpose()
{
	SparseMatrix temp(num_cols_, num_rows_, capacity_); // num_cols_, num_rows_ 순서 주의

	// TODO:

	return temp;
}

void SparseMatrix::PrintTerms()
{
	for (int i = 0; i < num_terms_; i++)
		cout << "(" << terms_[i].row
		<< ", " << terms_[i].col
		<< ", " << terms_[i].value
		<< ")" << endl;
}

void SparseMatrix::Print()
{
	for (int r = 0; r < num_rows_; r++)
	{
		for (int c = 0; c < num_cols_; c++)
			cout << GetValue(r, c) << " ";
		cout << endl;
	}
}