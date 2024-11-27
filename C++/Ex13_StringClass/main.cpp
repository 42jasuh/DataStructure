#include <iostream>
#include <cstring>

using namespace std;

class MyString
{
public:
    MyString(const char* str)
    {   
        int i = 0;
        while(str[i] != 0)
        {
            i++;
        }
        length_ = i;
        str_ = new char[length_+1];
        
        for(int i = 0; i < length_; i++)
        {
            str_[i] = str[i];
        }
        str_[length_] = 0;
    }

    void Print()
    {
        for (int i = 0; i < length_; i++)
        {
            cout << str_[i];
        }
        cout << endl;
    }

    void Resize(char* str)
    {   
        int i = 0;
        while(str[i] != '\0')
        {
            i++;
        }

        char* new_str = new char[i+length_+1];
        for (int j = 0; j < length_; j++)
        {
            new_str[j] = str_[j];
        }
        delete[] str_;
        str_ = new_str;
        length_ = i+length_+1;
    }

    void Append(MyString app_str)
    {   
        int old_length = length_;
        Resize(app_str.str_);
        int i = 0;
        for(int j = old_length; j < length_; j++)
        {
            str_[j] = app_str.str_[i++];
        }        
    }

private:
    char* str_;
    int leftength_;
};

int main()
{   
    MyString my_string1("apple");
    MyString my_string2("banana");

    my_string1.Append(my_string2);
    my_string1.Print();
    return 0;
}