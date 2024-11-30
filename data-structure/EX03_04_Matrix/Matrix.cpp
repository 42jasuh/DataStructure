#include "Matrix.h"

#include <algorithm>
#include <cassert>
#include <iostream>

using namespace std;

Matrix::Matrix(int num_rows, int num_cols)
{	    
    values_ = new float[num_rows * num_cols];
    
    num_rows_ = num_rows;
    num_cols_ = num_cols;

    for (int i = 0; i < num_rows * num_cols; i++)
        values_[i] = 0.0f;
}

// 복사 생성자의 핵심은 인자로 받은 클래스를 참조하는 타입을 본떠서 모든 값을 복사하는 것
Matrix::Matrix(const Matrix& b)
{
    num_rows_ = b.num_rows_;
    num_cols_ = b.num_cols_;

    values_ = new float[num_rows_ * num_cols_];

    for (int i = 0; i < num_rows_ * num_cols_; i++)
        values_[i] = b.values_[i];
}

Matrix::~Matrix()
{
    if (values_) delete[] values_;
    values_ = nullptr;
}

void Matrix::SetValue(int row, int col, float value)
{
	int index = num_cols_ * row + col;
    values_[index] = value;    
}

float Matrix::GetValue(int row, int col) const // 맨 뒤의 const는 함수 안에서 멤버 변수의 값을 바꾸지 않겠다는 의미
{    
    int index = num_cols_ * row + col;    
	return values_[index];
}

Matrix Matrix::Transpose()
{    

	float* temp_values_ = new float[num_rows_ * num_cols_];

    for (int i = 0; i < num_rows_; i++)
        for (int j = 0; j < num_cols_; j++)
        {            
            int index = (num_rows_* j) + i;
            temp_values_[index] = GetValue(i, j);
        }    

    Matrix temp(num_cols_, num_rows_);
    
    temp.values_ = temp_values_;

    for (int i = 0; i < num_rows_*num_cols_; i++)
        temp.values_[i] = temp_values_[i];

	return temp;
}

Matrix Matrix::Add(const Matrix& b)
{
	assert(b.num_cols_ == num_cols_);
	assert(b.num_rows_ == num_rows_);

	Matrix temp(num_rows_, num_cols_);

	for (int i = 0; i < num_cols_ * num_rows_; i++)
    {
        temp.values_[i] = values_[i] + b.values_[i];
    }

    return temp;
}

void Matrix::Print()
{       
	for (int r = 0; r < num_rows_; r++)
	{
		for (int c = 0; c < num_cols_; c++)
			cout << GetValue(r, c) << " ";
		cout << endl;
	}
}