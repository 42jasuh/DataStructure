#include <iostream>
#include <string> 

#include "PhoneBook.h"

using namespace std;

int main()
{   
    PhoneBook my_phonebook;
    my_phonebook.AddContact("사람1", "1234-1234");
    my_phonebook.AddContact("사람2", "2345-2345");
    my_phonebook.AddContact("사람3", "3456-3456");

    my_phonebook.PrintAll();

    // int menu_number;
    // while (true)
    // {
    //     cout << "1. 모두 출력\n";
    //     cout << "2. 검색\n";
    //     cout << "3. 추가\n";
    //     cout << "4. 삭제\n";
    //     cout << "5. 종료\n";
    //     cout << "메뉴를 선택해주세요: ";

    //     cin >> menu_number;
    //     cin.ignore();

    //     if (menu_number == 1)
    //     {
    //         my_phonebook.PrintAll();
    //     }
    //     else if (menu_number == 2)
    //     {
    //         my_phonebook.FindByName();
    //     }
    //     else if (menu_number == 3)
    //     {
    //         my_phonebook.AddContact();
    //     }
    //     else if (menu_number == 4)
    //     {
    //         my_phonebook.DeleteByName();
    //     }
    //     else if (menu_number == 5)
    //     {
    //         cout << "종료합니다." << endl;
    //         break;
    //     }
    // }
    // return 0;
}