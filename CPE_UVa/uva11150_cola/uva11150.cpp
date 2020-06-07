#include <iostream>
using namespace std;

int Method(int fill, int empty)
{
    int bottle = fill;
    empty += fill;

    if (empty >= 3)
        bottle += Method((empty / 3), (empty % 3));

    return bottle;
}

int CompareTwoMethod(int n)
{
    int bottols = max(Method(n, 0), Method(n, 1));
    return bottols;
}

int main()
{
    int N;
    while (cin >> N)
    {
        cout << CompareTwoMethod(N) << endl;
    }
    return 0;
}
