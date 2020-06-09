#include <iostream>
using namespace std;
int main()
{
    int I;
    while (cin >> I && I)
    {
        string binary_I;
        int parity = 0;
        while (I)
        {
            binary_I.insert(binary_I.begin(), (I % 2) + '0');
            parity += I % 2;
            I /= 2;
        }
        cout << "The parity of " << binary_I << " is " << parity << " (mod 2)." << endl;
    }
}