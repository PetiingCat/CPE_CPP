#include <iostream>
using namespace std;

int main()
{
    int T;
    cin >> T;
    //while ()
    //{
    while (T--)
    {
        int N, P, lose_day = 0;
        int Halt_of_Party[101];
        bool days[3651] = {0};
        cin >> N >> P;
        for (int i = 0; i < P; i++)
        {
            cin >> Halt_of_Party[i];
        }
        for (int i = 0; i < P; i++)
        {
            for (int j = Halt_of_Party[i]; j <= N; j += Halt_of_Party[i])
            {
                if (!(days[j]) && (((j - 1) % 7) < 5))
                { //日期對星期多1，因此日期減1對7取餘就會是星期
                    lose_day++;
                    days[j] = 1;
                }
            }
        }
        cout << lose_day << endl;
    }
    //}
}