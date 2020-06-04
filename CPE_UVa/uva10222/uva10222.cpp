#include <iostream>
#include <string>
using namespace std;

int main()
{
    string StanderKeyBoard = "  `1234567890-=qwertyuiop[]asdfghjkl;'zxcvbnm,./";
    char table[128] = {0};
    /*使用O(1)的table取代O(m)的線性查找*/
    for (int i = 2; i < StanderKeyBoard.length(); i++)
    {
        table[StanderKeyBoard[i]] = StanderKeyBoard[i - 2];
    }

    string codemsg;
    while (getline(cin, codemsg)) //getline()讀一整行但沒有讀換行符號
    {
        for (int i = 0; i < codemsg.length(); i++)
        {
            if (codemsg[i] == ' ')
            {
                cout << " ";
            }
            else
            {
                cout << table[tolower(codemsg[i])];
            }
        }
        cout << endl;
    }
    return 0;
}