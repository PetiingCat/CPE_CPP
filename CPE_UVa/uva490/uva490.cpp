#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    string s;
    vector<string> sentences;
    int max_length = 0;
    while (getline(cin, s))
    {
        if (s.length() > max_length)
        {
            max_length = s.length();
        }

        sentences.push_back(s);
    }

    for (int i = 0; i < max_length; i++)
    {
        for (int j = sentences.size() - 1; j >= 0; j--)
        {
            if (i < sentences[j].length())
                cout << sentences[j][i];
            else if (j != 0)
                cout << " ";
        }
        cout << endl;
    }
}