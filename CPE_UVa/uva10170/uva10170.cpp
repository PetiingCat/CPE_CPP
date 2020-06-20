#include <iostream>
using namespace std;

bool flag;
long long current_date, D, S;

int main()
{
    while (cin >> S >> D)
    {
        while (D > 0)
        {
            D -= S;
            S++;
        }
        cout << S - 1 << endl;
    }
}