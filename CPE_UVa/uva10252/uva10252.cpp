#include <iostream>
using namespace std;

int main()
{
    string s1, s2;
    while (getline(cin, s1) && getline(cin, s2))
    {
        int alphabats1[26] = {0};
        int alphabats2[26] = {0};
        for (char c : s1)
        {
            if (c != ' ')
                alphabats1[c - 'a']++;
        }
        for (char c : s2)
        {
            if (c != ' ')
                alphabats2[c - 'a']++;
        }
        for (int i = 0; i < 26; i++)
        {
            for (int j = min(alphabats1[i], alphabats2[i]); j > 0; j--)
            {
                cout << (char)(i + 'a');
            }
        }
        cout << endl;
    }
}
