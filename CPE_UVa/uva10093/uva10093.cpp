#include <iostream>
using namespace std;

int main()
{
    int sum, Max_DigitNumber, tmp;
    string R;
    while (getline(cin, R))
    {
        sum = 0;
        Max_DigitNumber = 1;
        int i;
        for (i = 0; i < R.length(); i++)
        {
            if (R[i] >= '0' && R[i] <= '9')
            {
                tmp = R[i] - '0';
            }
            else if (R[i] >= 'A' && R[i] <= 'Z')
            {
                tmp = R[i] - 'A' + 10; //62進位制裡，A是第10個數字
            }
            else if (R[i] >= 'a' && R[i] <= 'z')
            {
                tmp = R[i] - 'a' + 36; //62進位制裡，a是第36個數字
            }
            else
                continue;

            if (Max_DigitNumber < tmp)
                Max_DigitNumber = tmp;
            sum += tmp;
        }

        for (i = Max_DigitNumber; i < 62; i++)
            if (!(sum % i))
            {
                cout << i + 1 << endl;
                break;
            }

        if (i == 62)
            cout << "such number is impossible!" << endl;
    }
    return 0;
}