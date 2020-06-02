#include <iostream>
#include <algorithm>
#define Max 500
using namespace std;

int count_testcase = 0;
int address[Max];

bool cmp(int a, int b)
{
    return (a < b);
}

int main()
{
    int i = 0;
    cin >> count_testcase;
    for (i = 0; i < count_testcase; i++)
    {
        int answer = 0;
        int r = 0;
        cin >> r;
        for (int j = 0; j < r; j++)
        {
            cin >> address[j];
        }
        sort(address, address + r, cmp);
        int mid = address[r / 2];
        for (int j = 0; j < r; j++)
        {
            answer += abs(address[j] - mid);
        }
        cout << answer << endl;
    }
    //cout << "STOP";
}