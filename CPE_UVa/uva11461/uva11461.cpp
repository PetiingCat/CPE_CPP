#include <iostream>
using namespace std;

int main()
{
    int a, b;
    while (cin >> a >> b && (a || b))
    {
        int count = 0;
        for (int k = a; k <= b; k++)
        {
            for (int i = 0; i * i <= k; i++)
            {
                if (i * i == k)
                {
                    count++;
                    break;
                }
            }
        }
        cout << count << endl;
    }
}
