#include <iostream>
using namespace std;

int main()
{
    int T;
    while (cin >> T)
    {
        for (int case_order = 1; case_order <= T; case_order++)
        {
            int a, b, sum = 0;
            cin >> a >> b;
            for (int i = a; i <= b; i++)
            {
                if (i & 1)
                    sum += i;
            }
            cout << "Case " << case_order << ": " << sum << endl;
        }
    }
}