#include <iostream>
#include <vector>
using namespace std;

// Debug: 輸出整張圖
void Testing_PrintAll_ArrayElementors(int M, int N, vector<vector<char>> &canvas)
{
    for (int i = 0; i <= M + 1; i++)
    {
        for (int j = 0; j <= N + 1; j++)
        {
            cout << canvas[i][j] << " ";
        }
        cout << endl;
    }
}

// 輸入length為原點出發到邊界的距離；回傳該距離是否存在完整的方框，是則回傳( 1 + 遞迴check_next_distance )，否則回傳0;
// 最終回傳原點出發到最大許可邊界的距離
int check_next_distance(int r, int c, vector<vector<char>> &canvas, int length)
{
    bool IsSame = true;
    int vertical_dirction;
    int horizontal_dirction;

    if (IsSame)
    {
        vertical_dirction = (-1) * length;             //檢查原點上方的列
        for (int j = c - length; j <= c + length; j++) //該列每一行一一檢查
        {
            if (!(canvas[r][c] == canvas[r + vertical_dirction][j]))
            {
                IsSame = false;
                break;
            }
        }
    }

    if (IsSame)
    {
        vertical_dirction = (+1) * length; //檢查原點下方的列
        for (int j = c - length; j <= c + length; j++)
        {
            if (!(canvas[r][c] == canvas[r + vertical_dirction][j]))
            {
                IsSame = false;
                break;
            }
        }
    }

    if (IsSame)
    {
        horizontal_dirction = (-1) * length;                   //檢查原點左方的行
        for (int j = r - length + 1; j <= r + length - 1; j++) //該行每一列一一檢查
        {
            if (!(canvas[r][c] == canvas[j][c + horizontal_dirction]))
            {
                IsSame = false;
                break;
            }
        }
    }

    if (IsSame)
    {
        horizontal_dirction = (+1) * length;                   //檢查原點右方的行
        for (int j = r - length + 1; j <= r + length - 1; j++) //該行每一列一一檢查
        {
            if (!(canvas[r][c] == canvas[j][c + horizontal_dirction]))
            {
                IsSame = false;
                break;
            }
        }
    }

    if (IsSame)
        return (1 + check_next_distance(r, c, canvas, (length + 1)));
    else
        return 0;
}

int main()
{
    int T;
    while (cin >> T)
    {
        int M, N, Q;
        for (; T > 0; T--)
        {
            cin >> M >> N >> Q;
            vector<char> row(102, '0');            //vector容器二維的是用方式：先製作一維陣列
            vector<vector<char>> canvas(102, row); //再製作第二維度，並將內部初值設為一維陣列
            for (int i = 1; i <= M; i++)
            {
                for (int j = 1; j <= N; j++)
                {
                    cin >> canvas[i][j]; //自訂陣列的特定位置作為cin的開始，
                                         //cin.getline(s陣列變數, 輸入長度)只能從陣列第0格開始cin，不能調整位置
                }
            }

            cout << M << " " << N << " " << Q << endl;
            // Testing_PrintAll_ArrayElementors(M, N, canvas);//Debug:輸出整張圖

            // 輸入座標
            int r, c, uplen, downlen, leftlen, rightlen;
            for (int i = 0; i < Q; i++)
            {
                cin >> r >> c;

                r = r + 1;
                c = c + 1;

                cout << 1 + 2 * check_next_distance(r, c, canvas, 1) << endl;
            }
        }
    }

    return 0;
}