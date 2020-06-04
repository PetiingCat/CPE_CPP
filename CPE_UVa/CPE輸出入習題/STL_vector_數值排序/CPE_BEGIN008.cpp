/**
 * 更正版解答
 * 
 * (BEGIN008) STL-vector-數值排序 : 
 * 輸入數列，每列為一個測試案例。
 * 每一個案例內含一個數字N，然後後接N個數字。
 * 請針對每個案例內的N個數字，由小到大輸出。 
 * 
 * 標準輸入串:
 * 12 61 20 41 96 89 51 82 15 57 75 55 44 
 * 10 79 33 21 63 57 14 39 47 39 97 
 * 15 75 11 10 64 39 68 98 46 17 68 32 52 95 48 44 
 * 12 89 21 65 42 83 35 79 15 81 81 25 55 
 * 6 70 61 35 30 33 75 
 * 8 40 85 71 36 35 76 90 17 
 * 13 72 25 16 40 42 53 76 68 65 67 32 10 27 
 * 5 81 59 20 23 36 
 * 11 52 21 60 23 92 96 27 86 77 92 50 
 * 7 60 72 83 46 93 35 77 
 * 9 69 94 87 29 77 14 35 32 15 
 * 5 88 81 60 19 28 
 * 
 * 正確輸出串:
 * 15 20 41 44 51 55 57 61 75 82 89 96↵\r\n
 * 4 21 33 39 39 47 57 63 79 97↵\r\n
 * 0 11 17 32 39 44 46 48 52 64 68 68 75 95 98↵\r\n
 * 5 21 25 35 42 55 65 79 81 81 83 89↵\r\n
 * 0 33 35 61 70 75↵\r\n
 * 7 35 36 40 71 76 85 90↵\r\n
 * 0 16 25 27 32 40 42 53 65 67 68 72 76↵\r\n
 * 0 23 36 59 81↵\r\n
 * 1 23 27 50 52 60 77 86 92 92 96↵\r\n
 * 5 46 60 72 77 83 93↵\r\n
 * 4 15 29 32 35 69 77 87 94↵\r\n
 * 9 28 60 81 88↵\r\n
 * 
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int k;
    while (cin >> k)
    {
        vector<int> a(k); //vector<宣告型態> 變數(長度, 初始值)
        while (k--)
            cin >> a[k];          //vector的調用其實和陣列很像
        sort(a.begin(), a.end()); //a.begin()回傳指在第一個元素的位址的ptr，a.end()回傳指在的最後一個元素的下一個位址的ptr
        while (++k < a.size())
        {
            if (k)
                cout << " ";
            cout << a[k];
        }
        cout << endl;
    }
}
/*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	char c;
	while(cin.get(c).unget()){ //iostream其實像是個buffer，使用cin.get可以讀出字元，也能使用cin.unget()放回去stream
		int k;
		if(!(cin>>k))break; //這很像C風格的寫法，若是要在無限迴圈中判斷結尾，可以使用cin>>(int)，cin讀'空'表示沒讀到東西，則返回false，取not做break loop
		vector<int> a(k);
		while(k--)cin>>a[k];
		sort(a.begin(),a.end());
		while(++k<a.size()){if(k)cout<<" "; cout<<a[k];}
		cout<<endl;		
	}
}
/*/