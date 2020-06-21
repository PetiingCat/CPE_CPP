#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

long long K_Pow(long long x, int y)
{
    if (y == 0)
        return 1;
    long long porduct = 1;
    for (int i = 0; i < y; i++)
    {
        porduct *= x;
    }
    return porduct;
}

long long a[1000000];
int main()
{
    long long x;
    string s;
    while (cin >> x)
    {
        cin.ignore();
        getline(cin, s);
        stringstream sin(s);
        int n = 0;
        while (sin >> a[n])
        {
            n++;
        }
        n--;

        long long ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans += a[i] * (n - i) * K_Pow(x, n - 1 - i);
        }
        cout << ans << endl;
    }
    return 0;
}