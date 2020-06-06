// 1. input n
// 2. print n
// 3. if n = 1 then STOP
// 4. if n is odd then n ←− 3n + 1
// 5. else n ←− n/2
// 6. GOTO 2
#include <iostream>
#include <algorithm>
using namespace std;

void sort_increasing(int &a, int &b)
{
    if (a > b)
    {
        swap(a, b);
    }
}

int max_cycle_of_uva100_algo(int &i, int &j)
{
    sort_increasing(i, j);
    int max = 0;
    for (int k = i; k <= j; k++)
    {
        int n = k;
        int cycle = 1;
        do
        {
            //print n
            cycle++;

            if (n & 1)
            {
                n = 3 * n + 1;
            }
            else if (n | 0)
            {
                n /= 2;
            }
            else
            {
                cout << "there is some problem! :(";
            }
        } while (n != 1);

        if (cycle > max)
        {
            max = cycle;
        }
    }
    return max;
}

int main()
{
    int i, j;
    while (cin >> i >> j)
    {
        cout << i << " " << j << " " << max_cycle_of_uva100_algo(i, j) << endl;
    }
}