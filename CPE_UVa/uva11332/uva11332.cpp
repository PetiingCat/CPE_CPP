#include <iostream>
using namespace std;

int Summing_Digits(int n)
{
    string N = to_string(n);

    /*base case*/
    if (N.length() == 1)
    {
        return stoi(N);
    }

    /*recursive*/
    int sum = 0;
    for (char c : N)
    {
        sum += c - '0';
    }
    return Summing_Digits(sum);
}

int main()
{
    for (int n; cin >> n && n;)
    {
        cout << Summing_Digits(n) << endl;
    }
}
