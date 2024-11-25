#include "MyString.h"

using namespace std;

// 비어 있는 MyString() 생성
MyString::MyString()
{
	str_ = nullptr;
	size_ = 0;
}

// 맨 뒤에 널 캐릭터'\0'가 들어 있는 문자열로부터 초기화
MyString::MyString(const char* init)
{
	// 크기(size_) 결정
    size_ = strlen(init) + 1;

	// 메모리 할당
    str_ = (char*)malloc(size_+1);

	// 데이터 복사
	int i = 0;
	for(; i < size_; i++)
		str_[i] = init[i];
	str_[i] = '\0';
}

// MyString의 다른 instance로부터 초기화
MyString::MyString(const MyString& str)
{
    str_ = str.str_;
    size_ = str.size_;
}

MyString::~MyString()
{
}

bool MyString::IsEmpty()
{
	return Length() == 0;
}

bool MyString::IsEqual(const MyString& str) // 편의상 참조& 사용
{
	// 힌트: str.str_, str.size_ 가능
	int i = 0;
	int j = 0;

	while (str.str_[i] != '\0' && str_[j] != '\0')
	{		
		if (str.str_[i] == str_[j])
		{
			i++;
			j++;
		}
		else
			return false;
	}
	if (str.str_[i] == '\0' && str_[j] == '\0')
		return true;
	return false;
}

int MyString::Length()
{
	return size_;
}

void MyString::Resize(int new_size)
{
	// 메모리 재할당과 원래 갖고 있던 내용 복사
}

// 인덱스 start위치의 글자부터 num개의 글자로 새로운 문자열 만들기
MyString MyString::Substr(int start, int num)
{
	// 복사할 인덱스: start, start + 1, ... , start + num - 1
	assert(start + num - 1 < this->size_); // 문제를 단순하게 만들기 위해 가정

	MyString temp;
	temp.size_ = num - start + 1;
	temp.str_ = (char*)malloc(temp.size_);

	int i = 0;
	int j = start;

	while(i < temp.size_)
	{
		temp.str_[i] = this->str_[j];
		i++;
		j++;
	}
	temp.str_[i]='\0';
	return temp;
}

MyString MyString::Concat(MyString app_str)
{
	MyString temp;

	temp.size_ = this->size_ + app_str.size_ - 1;
	temp.str_ = (char*)malloc(temp.size_);

	int i = 0;
	int j = 0;
	for(; i < this->size_; i++)
		temp.str_[i] = this->str_[i];
	for(; i < temp.size_; i++)
	{
		temp.str_[i] = app_str.str_[j];
		j++;
	}
	temp.str_[i] = '\0';
	return temp;
}

MyString MyString::Insert(MyString t, int start)
{
	assert(start >= 0);
	assert(start <= this->size_);

	MyString temp;

	// TODO:
	temp.size_ = size_ + t.size_ -1;
	char* m = (char*)malloc(temp.size_);
	temp.str_ = m;

	int i = 0;
	int j = 0;
	int k = 0;
	for (; i < start; i++)
	{
		m[i] = str_[i];
		j++;
	}
	for(; i < start+t.size_; i++)
	{
		m[i] = t.str_[k];
		k++;
	}
	for(; i < t.size_ + size_; i++)
		m[i] = str_[j++];
	m[i] = '\0';

	return temp;
} 

int MyString::Find(MyString pat)
{
	//TODO:
	int i = 0;
	int j = 0;
	int s = -1;

	while(str_[j] != '\0')
	{
		if (pat.str_[i] == '\0')
			return s;
		if (pat.str_[i] == str_[j] && s == -1)
			s = j;
		if (pat.str_[i] == str_[j])
		{
			j++;
			i++;
		}
		else if (pat.str_[i] != str_[j])
		{
			i = 0;
			j++;
			s = -1;
		}
	}
	if (pat.str_[i] == '\0')
		return s;
	return -1;
}

void MyString::Print()
{	
	for (int i = 0; i < size_; i++)
		cout << str_[i];
	cout << endl;
}
