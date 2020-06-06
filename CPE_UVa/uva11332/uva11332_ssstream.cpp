#include <iostream>
#include <sstream>
using namespace std;

stringstream ss_buffer;
void ini_ss_Buffer()
{
    ss_buffer.str("");
    ss_buffer.clear();
}

int Summing_Digits(int n)
{
    string N;
    ini_ss_Buffer();
    ss_buffer << n;
    ss_buffer >> N;

    /*base case*/
    if (N.length() == 1)
    {
        int g;
        ini_ss_Buffer();
        ss_buffer << N;
        ss_buffer >> g;
        return g;
    }

    /*recursive*/
    int sum = 0;
    for (char c : N)
    {
        int d;
        ini_ss_Buffer();
        ss_buffer << c;
        ss_buffer >> d;
        sum += d;
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