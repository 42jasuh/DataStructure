#pragma once
#pragma once

#include <cassert>
#include <iostream>

using namespace std;

template<typename T> // 템플릿 사용
class Stack
{
public:
	Stack(int capacity = 1)
	{
		assert(capacity > 0);
		Resize(capacity);
	}

	~Stack()
	{
		if (stack_) delete[] stack_;
	}

	void Resize(int new_capacity)
	{
		T* new_stack = new T[new_capacity];
		memcpy(new_stack, stack_, sizeof(T) * Size());
		if (stack_) delete[] stack_;
		stack_ = new_stack;
		capacity_ = new_capacity;
	}

	bool IsEmpty() const
	{
		return top_ == -1;
	}

	int Size() const
	{
		return top_ + 1;
	}

	void Print()
	{
		using namespace std;

		for (int i = 0; i < Size(); i++)
			cout << stack_[i] << " ";
		cout << endl;
	}

	// Returns TOP element of stack.
	T& Top() const
	{
		assert(!IsEmpty());

		return stack_[top_];
	}

	// Insert item into the TOP of the stack
	void Push(const T& item)
	{
		// TODO: 필요하면 리사이즈
		if (top_ == capacity_ - 1)
			Resize(capacity_ * 2);
		stack_[++top_] = item;		
	}

	// Delete the TOP element of the stack
	void Pop()
	{
		assert(!IsEmpty());
		top_--;
	}

protected: // 뒤에서 상속해서 사용
	T* stack_ = nullptr;

	// 가장 마지막에 추가된 아이템의 인덱스. 아무 것도 없을 때는 -1. 하나만 추가 했을 때는 0
	int top_ = -1; // 0 아님
	int capacity_ = 0;
};