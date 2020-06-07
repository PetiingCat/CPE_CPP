#include <iostream>
using namespace std;

int main()
{
    int month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    string week[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    int Week_of_2011_Zero = 5; // 2011/1/10 is Monday(2011 is not leap year), so it is not difficult to know 1/0 is Saturday.

    int testcase;
    while (cin >> testcase)
    {
        int m, d;
        while (testcase--)
        {
            cin >> m >> d;
            int week_of_date = d + Week_of_2011_Zero;
            for (int i = 0; i < m - 1; i++)
            {
                week_of_date += month[i];
            }
            cout << week[week_of_date % 7] << endl;
        }
    }
}