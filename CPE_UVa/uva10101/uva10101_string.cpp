// kuti (10000000), (8位數)
// lakh   (100000), (6位數)
// hajar    (1000), (4位數)
// shata     (100), (3位數)
// 9,99,9,99,|99,99,99,9,|99 (15位數)
#include <iostream>
#include <iomanip>
#include <queue>
using namespace std;

void print_Bangla(string &s, queue<string> &ans)
{

    if (!(s.length())) //該位數不存在
        return;

    if (s.length() > 7)
    {
        string temp = s.substr(0, s.length() - 7);
        if (stoi(temp))
        {
            //ans.push(temp);
            print_Bangla(temp, ans);
            ans.push(" kuti");
        }
        s = s.substr(s.length() - 7, 7);
    }

    if (s.length() > 5)
    {
        string temp = s.substr(0, s.length() - 5);
        if (stoi(temp))
        {
            print_Bangla(temp, ans);
            ans.push(" lakh");
        }
        s = s.substr(s.length() - 5, 5);
    }

    if (s.length() > 3)
    {
        string temp = s.substr(0, s.length() - 3);
        if (stoi(temp))
        {
            print_Bangla(temp, ans);
            ans.push(" hajar");
        }
        s = s.substr(s.length() - 3, 3);
    }

    if (s.length() > 2)
    {
        string temp = s.substr(0, s.length() - 2);
        if (stoi(temp))
        {
            print_Bangla(temp, ans);
            ans.push(" shata");
        }
        s = s.substr(s.length() - 2, 2);
    }

    if (s.length() <= 2)
    {
        int n = stoi(s);
        if (n)
        {
            s = " " + to_string(n);
            ans.push(s);
        }
    }
}

int main()
{
    string s;
    queue<string> ans;
    int count_order = 0;
    while (getline(cin, s))
    {
        cout << setw(4) << (++count_order) << ".";

        int strlen = s.length();
        if (strlen && s != "0")
        {
            print_Bangla(s, ans);
            while (!ans.empty())
            {
                cout << ans.front();
                ans.pop();
            }
        }
        else
            cout << (" 0");
        cout << endl;
    }
    return 0;
}