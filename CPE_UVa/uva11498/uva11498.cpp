#include <iostream>
using namespace std;

int main()
{
    int testcase, n, m, x, y;

    while (cin >> testcase && testcase)
    {
        cin >> n >> m;
        for (int i = 0; i < testcase; i++)
        {
            cin >> x >> y;
            if (x == n || y == m)
                cout << "divisa" << endl;
            else
            {
                if (y > m)
                {
                    cout << "N";
                }
                else if (y < m)
                {
                    cout << "S";
                }

                if (x > n)
                {
                    cout << "E";
                }
                else if (x < n)
                {
                    cout << "O";
                }
                cout << endl;
            }
        }
    }
    return 0;
}