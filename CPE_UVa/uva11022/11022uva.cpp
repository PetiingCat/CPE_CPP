#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {  
    int input1, input2, input3;
    while(cin>>input1) {
        int bin[3][3] = {0}; // bin color, bin label. 
        int all_counts = 0;
        for (int i = 0; i < 3; ++i) {
            cin >> input2 >> input3;
            bin[0][i] = input1; // B
            bin[2][i] = input2; // G
            bin[1][i] = input3; // C
            all_counts += input1 + input2 + input3;
            if (i != 2)
                cin >> input1;
        }
        vector <char> bottle_name = {'B','C','G'};
        vector <int> array = {0,1,2};
        vector <int> bestArrange;
        int ans = -1;
        do
        {
            int curr = (all_counts - bin[array[0]][0] - bin[array[1]][1] - bin[array[2]][2]);
            if (ans > curr || ans==-1) {
                ans = curr;
                bestArrange = array;
            }
        }while(next_permutation(array.begin(), array.end()));
        printf("%c%c%c %d\n", bottle_name[bestArrange[0]], bottle_name[bestArrange[1]], bottle_name[bestArrange[2]], ans);
    }
    return 0;
}