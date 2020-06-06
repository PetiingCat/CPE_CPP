// kuti (100000 00), (8位數)
// lakh   (1000 00), (6位數)
// hajar    (10 00), (4位數)
// shata     (1 00), (3位數)
// 9,99,9,99,|99,99,99,9,99 (15位數) //20,0,00
#include <iostream>
#include <iomanip>
using namespace std;

void print_Bangla(long long int n)
{
    if (n == 0) //該位數不存在
        return;

    if (n / 10000000)
    {
        print_Bangla(n / 10000000);
        cout << (" kuti");
        n %= 10000000;
    }

    if (n / 100000)
    {
        print_Bangla(n / 100000);
        cout << (" lakh");
        n %= 100000;
    }

    if (n / 1000)
    {
        print_Bangla(n / 1000);
        cout << (" hajar");
        n %= 1000;
    }

    if (n / 100)
    {
        print_Bangla(n / 100);
        cout << (" shata");
        n %= 100;
    }

    if (n) //
        cout << " " << n;
}

int main()
{
    long long int n;
    int count_order = 0;
    while (cin >> n)
    {
        cout << setw(4) << (++count_order) << ".";
        if (n)
            print_Bangla(n);
        else
            cout << (" 0");
        cout << endl;
    }
    return 0;
}