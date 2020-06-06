#include <iostream>
using namespace std;

int main()
{
    string s;
    int count = 0;
    while (getline(cin, s))
    {
        for (char c : s)
        {
            if (c == '"')
            {
                count++;
                if (count & 1) //odd
                    cout << "``";
                else //if(count | 0)//even
                {
                    cout << "''";
                }
            }
            else
            {
                cout << c;
            }
        }
        cout << endl;
    }
}