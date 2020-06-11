/*learning*/
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int testcase, m, n, error;
    int a[4][1001], temp;
    string s, s1 = "ACGT";

    cin >> testcase;
    while (testcase--)
    {
        cin >> m >> n;
        getchar();
        memset(a, 0, sizeof(a));
        for (int i = 0; i < m; i++)
        {
            cin >> s;
            for (int j = 0; j < n; j++)
            {
                for (int k = 0; k < 4; k++)
                {
                    if (s[j] == s1[k])
                    {
                        a[k][j]++;
                        break;
                    }
                }
            }
        }
        error = 0;
        for (int i = 0; i < n; i++)
        {
            temp = max(max(max(a[0][i], a[1][i]), a[2][i]), a[3][i]);
            error += (m - temp);
            for (int j = 0; j < 4; j++)
            {
                if (temp == a[j][i])
                {
                    cout << s1[j];
                    break;
                }
            }
        }
        cout << endl;
        cout << error << endl;
    }
    return 0;
}