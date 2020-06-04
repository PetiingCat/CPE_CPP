/**
 * (BEGIN006) 檔尾封-行尾封-數數之和 : 
 * 輸入數列，每列為一個測試案例。
 * 每一個案例內含數個數字。
 * 請針對每個案例，輸出案例中的總和。
 * 
 * 標準輸入串:
 * 90 80 51 68 55 62 59 41 90 35 91 
 * 98 18 75 95 23 64 90 58 91 56 79 33 56 
 * 57 48 56 30 22 77 47 
 * 71 86 54 11 35 75 
 * 36 36 97 70 48 63 37 31 82 93 87 
 * 93 63 64 93 81 38 62 99 81 11 87 96 25 46 
 * 83 86 60 70 52 30 67 69 
 * 14 10 90 64 11 79 66 53 92 
 * 正確輸出串:
 * Sum=722↵\r\n
 * Sum=836↵\r\n
 * Sum=337↵\r\n
 * Sum=332↵\r\n
 * Sum=680↵\r\n
 * Sum=939↵\r\n
 * Sum=517↵\r\n
 * Sum=479↵\r\n
*/
#include <iostream>
#include <sstream>
using namespace std;
int main()
{
    int n;
    string s;
    while (getline(cin, s))
    {
        istringstream sin(s); //將string s存進istringstream sin
        int sum = 0;
        while (sin >> n) //從sin流出，用空格做分切，可以直接賦值給不同型態的變數
            sum += n;
        cout << "Sum=" << sum << endl;
    }
    return 0;
}