#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    int dictionary[91][1] = {0};
    string s;
    int n;
    cin >> n >> ws; //ws=whitespace用來清除stream buffer中的空白，它清除直到遇到下一個非空白字元就結束
    while (n--)
    {
        getline(cin, s);
        for (int i = 0; i < s.size(); i++)
            dictionary[(int)(toupper(s[i]))][0]++;
    }

    int max = 0; //找出字典中出現次數最大值
    for (int i = 65; i <= 90; i++)
    {
        if (dictionary[i][0] > max)
            max = dictionary[i][0];
    }

    for (int i = max; i > 0; i--)
    {
        for (int j = 65; j <= 90; j++) //ascii A = 65 ~ Z = 90
        {
            if (dictionary[j][0] == i)
                cout << char(j) << " " << i << endl;
        }
    }
}