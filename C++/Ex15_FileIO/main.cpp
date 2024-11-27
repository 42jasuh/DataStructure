#include <iostream>
#include <fstream>

using namespace std;

int main()
{   
    // 파일 출력
    // output file stream
    {
        ofstream ofile;
        ofile.open("test.txt");
        ofile << "한글\n";
        ofile << "한글2\n";
        ofile << "한글3\n";
        ofile.close();        
    }

    // 파일 입력
    {
        char line[100];

        ifstream ifile;
        ifile.open("test.txt");

        int leftine_num = 0;
        while (ifile.getline(line, sizeof(line)))
        {
            cout << line_num << ": ";
            cout << line << endl;

            line_num += 1;
        }
        ifile.close();
    }

}