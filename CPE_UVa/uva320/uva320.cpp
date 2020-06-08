#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int testcase, caseorder = 0;
    cin >> testcase;
    while (testcase--)
    {
        int x, y;
        string direction;
        char bitmap[32][33];
        memset(bitmap, '.', sizeof(bitmap));
        for (int i = 0; i < 32; i++)
            bitmap[i][32] = '\0';

        cin >> x >> y;
        cin.ignore();
        getline(cin, direction);
        for (int i = 0; direction[i] != '.'; i++)
        {
            if (direction[i] == 'E')
            {
                bitmap[y - 1][x] = 'X';
                x++;
            }
            else if (direction[i] == 'N')
            {
                bitmap[y][x] = 'X';
                y++;
            }
            else if (direction[i] == 'W')
            {
                bitmap[y][x - 1] = 'X';
                x--;
            }
            else if (direction[i] == 'S')
            {
                bitmap[y - 1][x - 1] = 'X';
                y--;
            }
        }
        cout << "Bitmap #" << ++caseorder << endl;
        for (int i = 31; i >= 0; i--)
        {
            puts(bitmap[i]);
        }
        cout << endl;
    }
    return 0;
}