#include <iostream>
#include <algorithm>
using namespace std;

int N, M;

int isOdd(int num)
{
    //num &= 1; // num = abs(num % 2);
    return (num &= 1);
}

bool cmp(int a, int b)
{
    if (a % M != b % M)
        return a % M < b % M;
    if (isOdd(a) != isOdd(b))
        return isOdd(a);
    if (isOdd(a))
        return a > b;
    return a < b;
}

int main()
{

    int a[10001];
    while (cin >> N >> M)
    {
        cout << N << " " << M << endl;
        if (!(N || M))
        {
            break;
        }

        for (int i = 0; i < N; i++)
            cin >> a[i];

        sort(a, a + N, cmp);

        for (int i = 0; i < N; i++)
            cout << a[i] << endl;
    }

    return 0;
}