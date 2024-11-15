#include "PhoneBook.h"

#include <cassert>
#include <iostream>
#include <cstring>

using namespace std;

PhoneBook::PhoneBook()
{
    contacts_ = new Contact[capacity];
}

PhoneBook::~PhoneBook()
{
    if (contacts_)
        delete[] contacts_;
}

void PhoneBook::PrintAll()
{
    for (int i = 0; i < num_contacts_; i++)
    {
        cout << i << " " << contacts_[i].name << ", " << contacts_[i].phone << endl;
    }
}

bool PhoneBook::IsEmpty()
{
    assert(num_contacts_ >= 0);
    if(num_contacts_ == 0)
        return true;
    else
        return false;
}

bool PhoneBook::IsFull()
{
    return true;
}

void PhoneBook::PrintContact(int index)
{
    char search_name[kMaxStr];

    cout << "검색 할 이름을 입력해주세요 : ";

}

void PhoneBook::AddContact(const char name[], const char phone[])
{
    if (IsFull())
    {
        cout << "더 이상 추가할 수 없습니다." << endl;
        return;
    }

    // 동적 메모리 사용
    if (IsFull())
    {
        cout << "메모리를 추가합니다." << endl;
        
    }
    char new_name[kMaxStr];
    char new_phone[kMaxStr];

    cout << "이름을 입력해주세요 : ";
    cin.getline(new_name, sizeof(new_name));

    cout << "전화번호를 입력해주세요 : ";
    cin.getline(new_phone, sizeof(new_phone));

    AddContact(new_name, new_phone);
}

void PhoneBook::AddContact()
{

}

void PhoneBook::DeleteByName()
{
    //삭제 시 메모리 줄이지 않음
    int index = FindByName();

    if (index >= 0)
    {
        // ToDo: 중간에서 삭제했을 경우

        // ToDo: num_contacts_ 하나 감소

        num_contacts_ -= 1;
    }
}

int PhoneBook::FindByName()
{
    char search_name[kMaxStr];

    cout << "검색할 이름을 입력해주세요: ";
    cin.getline(search_name, sizeof(search_name));

    // TODO: IsEqual(), PrintContact(i), return i;
    cout << search_name << "님을 찾지 못했습니다." << endl;
    return -1;
}

bool PhoneBook::IsEqual(const char str1[], const char str2[])
{
    for (int i = 0; i < kMaxStr; i++)
    {
        if (str1[i] != str2[i])
            return false;
        if (str1[i] == '\0')
            return true;
    }
    return true;
}