#include <iostream>
#include <sstream>
#include <map>
using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        string s;
        map<string, int> country_count;
        cin.ignore();
        while (n--)
        {
            getline(cin, s);
            istringstream sin(s);
            string country_name;
            sin >> country_name;

            country_count[country_name]++;
        }

        for (map<string, int>::iterator it = country_count.begin(); it != country_count.end(); it++)
        {
            cout << it->first << " ";
            cout << it->second << endl;
        }
    }
    return 0;
}