/*successive elements take on all the values 1 through n-1*/
/* sequence: 15 11 9 6 5 is a Jolly jumper too.*/
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

bool CheckJolly(bool DR[], int n);
void Output(bool Jolly);

int main()
{
    int n;
    while (cin >> n)
    {
        int N[3000];
        bool DifferenceRecord[3000];
        memset(DifferenceRecord, false, sizeof(DifferenceRecord));

        for (int i = 0; i < n; i++)
        {
            cin >> N[i];
        }
        for (int i = 0; i < n - 1; i++)
        {
            int difference = abs(N[i] - N[i + 1]);
            if (!(DifferenceRecord[difference]))
                DifferenceRecord[difference] = true;
        }
        Output(CheckJolly(DifferenceRecord, n));
    }
}

bool CheckJolly(bool DR[], int n)
{
    bool JollyIs = true;
    for (int i = 1; i < n; i++)
    {
        if (!(DR[i]))
        {
            JollyIs = false;
            break;
        }
    }
    return JollyIs;
}

void Output(bool Jolly)
{
    if (Jolly)
        cout << "Jolly" << endl;
    else
        cout << "Not jolly" << endl;
}