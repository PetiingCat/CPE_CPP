#include <iostream>
#include <cstring>
using namespace std;

void input(int &n, int &m, char **map)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == '.')
                map[i][j] = '0';
        }
    }
}

void MineNeighborAddOne(int i, int j, int n, int m, char **map)
{
    for (int ii = i - 1; ii <= i + 1; ii++)
    {
        for (int jj = j - 1; jj <= j + 1; jj++)
        {
            if (map[ii][jj] == '*')
                continue;
            map[ii][jj]++;
        }
    }
}

void output(int &n, int &m, char **map, int &field)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (map[i][j] == '*')
            {
                MineNeighborAddOne(i, j, n, m, map);
            }
        }
    }

    if (field > 1)
        cout << endl;
    cout << "Field #" << field << ":" << endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout << map[i][j];
        }
        cout << endl;
    }
}

int main()
{
    int n, m;
    int field = 0;
    while (cin >> n >> m)
    {
        if (n == 0 && m == 0)
            break;

        char map[n + 2][m + 2];
        memset(map, '0', sizeof(map));
        char *mapptr[n + 2];
        for (int i = 0; i < n + 2; i++)
        {
            mapptr[i] = map[i];
        }

        input(n, m, mapptr);
        field++;
        output(n, m, mapptr, field);
    }
    return 0;
}