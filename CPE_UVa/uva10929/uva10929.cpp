//11的倍數：n的(奇數位數字和)與(偶數位數字和)之差為11的倍數，則n為11的倍數。其中0也是11的倍數。

#include <iostream>
using namespace std;

int main()
{
    string n;
    while (getline(cin, n))
    {
        int sum_even = 0, sum_odd = 0, len_n = n.length(), differ = 0;

        if (len_n == 1)
        {
            sum_odd = n[0] - '0';
            if (!(sum_odd)) //輸入0則結束
                break;
        }
        else
        {
            for (int i = 0; i < len_n; i = i + 2)
            {
                sum_odd += n[i] - '0';
                if (n[i + 1] != NULL)
                    sum_even += n[i + 1] - '0';
            }
        }

        differ = abs(sum_odd - sum_even);
        if (!(differ % 11))
            cout << n << " is a multiple of 11." << endl;
        else
            cout << n << " is not a multiple of 11." << endl;
    }
    return 0;
}
