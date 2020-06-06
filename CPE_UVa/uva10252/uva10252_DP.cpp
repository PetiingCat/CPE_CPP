/**
 * 本解法只能解uva10252的部分答案
 * 失敗原因：
 * uva10252 != LCS problem
 * uva10252只是找尋兩字串的"最大共同子字串"的排列
 * 但LSC problem是兩序列的最大共同子序列(限定順序)
 * |longest_subsequence of uva10252 problem| > |longest_subsequence of LCS problem| 
 * 
 * 不過至少題目給的範例測資輸/出入是正確的
 * <Sample Input>
 * pretty
 * women
 * walking
 * down
 * the
 * street
 * 
 * <Sample Output>
 * e
 * nw
 * et
*/

/*課堂有教到LSC(最大共同子序列)，原來這題其實可以用DP查表來解*/
#include <iostream>
#include <vector>
#include <map> //uva10252要求用alphabat order輸出，使用map內部自動排序
using namespace std;

map<char, int> Alphabat_Order;

void print_LCS(int i, int j, vector<vector<int>> &prev, string &s1)
{
    // 第一個或第二個序列為空集合就停止
    if (i == 0 || j == 0)
        return;

    if (prev[i][j] == 0) // 左上方
    {
        print_LCS(i - 1, j - 1, prev, s1);
        //cout << s1[i]; // 印出LCS的元素
        /*改使用map做間接輸出以達到uva10252的要求，另外題目要求空格不計算*/
        if (s1[i] != ' ')
            Alphabat_Order[s1[i]]++;
    }
    else if (prev[i][j] == 1) // 左方
        print_LCS(i, j - 1, prev, s1);
    else if (prev[i][j] == 2) // 上方
        print_LCS(i - 1, j, prev, s1);
}

void LCS(vector<vector<int>> &length, string &s1, string &s2, vector<vector<int>> &prev, int n1, int n2)
{
    for (int i = 0; i <= n1; i++)
        length[i][0] = 0;
    for (int j = 0; j <= n2; j++)
        length[0][j] = 0;

    for (int i = 1; i <= n1; i++)
        for (int j = 1; j <= n2; j++)
            if (s1[i] == s2[j])
            {
                length[i][j] = length[i - 1][j - 1] + 1;
                prev[i][j] = 0; // 左上方
            }
            else
            {
                if (length[i - 1][j] < length[i][j - 1])
                {
                    length[i][j] = length[i][j - 1];
                    prev[i][j] = 1; // 左方
                }
                else
                {
                    length[i][j] = length[i - 1][j];
                    prev[i][j] = 2; // 上方
                }
            }

    cout << "LCS length is " << length[n1][n2] << endl;
    // cout << "LCS is ";
    print_LCS(n1, n2, prev, s1);
}

int main()
{
    string s1, s2;

    while (getline(cin, s1) && getline(cin, s2))
    {
        /*程式初始化/優化設定，和演算法無關*/
        int s1_len = s1.length(), s2_len = s2.length();
        Alphabat_Order.clear();

        /*字串從第1格開始，第零格不放資料(方便演算法操作)*/
        s1 = " " + s1;
        s2 = " " + s2;

        /*建立DP表*/
        vector<int> row1(s2_len + 1, 0);
        vector<vector<int>> length; //length[][]為DP表
        length.assign(s1_len + 1, row1);

        /*建立方向表*/
        vector<int> row2(s2_len + 1, 0);
        vector<vector<int>> prev; //prev[][]為紀錄方向，該格紀錄的長度是來自何方
        prev.assign(s1_len + 1, row2);

        /*LCS演算法*/
        LCS(length, s1, s2, prev, s1_len, s2_len);

        /*和LCS無關，uva10252要求用alphabat order輸出*/
        for (map<char, int>::iterator p = Alphabat_Order.begin(); p != Alphabat_Order.end(); p++)
        {
            for (int k = p->second; k > 0; k--)
                cout << p->first;
        }

        cout << endl;
    }
}