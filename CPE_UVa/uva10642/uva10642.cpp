#include <iostream>
using namespace std;

int CompareDestination_and_Count(int s_x, int s_y, int d_x, int d_y)
{
    /*base case*/
    if ((s_x == d_x) && (s_y == d_y))
        return 0;

    /*recursive case*/
    if (s_y == 0)
    {
        return (CompareDestination_and_Count(0, (s_x + 1), d_x, d_y)) + 1;
    }
    else // if (s_y > 0) // s_y would not be negetive
    {
        return (CompareDestination_and_Count((s_x + 1), (s_y - 1), d_x, d_y)) + 1;
    }
}

int main()
{
    int n;
    cin >> n;
    for (int orderlist = 1; orderlist <= n; orderlist++)
    {
        int s_x, s_y, d_x, d_y;
        cin >> s_x >> s_y >> d_x >> d_y;
        cout << "Case " << orderlist << ": " << CompareDestination_and_Count(s_x, s_y, d_x, d_y) << endl;
    }
}