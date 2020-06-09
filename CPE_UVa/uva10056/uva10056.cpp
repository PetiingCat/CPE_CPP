#include <iostream>
#include <cmath>   //pow()
#include <iomanip> // setprecision()
using namespace std;

int main()
{
    int S /*testcase*/,
        N /*the number players*/,
        I /* the serial of the player whose winning probability is to be determined*/;
    double p /*the probability of a successful event in a single throw*/,
        q,
        ans;

    cin >> S;
    while (S--)
    {
        cin >> N >> p >> I;
        q = 1 - p; /*the probability of a fall event in a single throw*/

        if (p == 0) //測資居然有贏的機率為零的事件
        {
            cout << "0.0000" << endl;
        }
        else
        {
            ans = (pow(q, (double)I - 1) * p) / (1 - pow(q, (double)N)); // 用貝氏定理計算 the probability of the I-th player to win
            cout << fixed << setprecision(4) << ans << endl;
        }
    }
    return 0;
}