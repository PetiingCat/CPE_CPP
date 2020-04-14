#include <iostream>
#include <algorithm>
using namespace std;

unsigned int* SortInDecrement(unsigned int ptr[], int n) {
    sort(ptr, ptr+n);
    reverse(ptr,ptr+n);/*sort n coins Denomination with decrement*/
    return ptr;
}

int Get_Combination_of_coin(unsigned int ptr[],int amount,int n){
    int i=0,count=0;
    /**if target is 0 then don't need to consider**/
    if(amount==0)return -1;

    /**get into checking**/
    for(i=0;i<n;i++){
        if(amount>=ptr[i]){
            count += (int)(amount / ptr[i]);
            amount = amount % ptr[i];
        }
    }
    if(amount==0)return count;
    else return -1;
}

int main() {
    int t=0, n=0, m=0;
    cin>>t;
    while(t--){
        cin>>n>>m;
        unsigned int Denomination[n];/*2^31-1 means 4 bytes*/
        int i;
        for(i=0;i<n;i++){
            cin>>Denomination[i];//same as 'cin>>*(Denomination+i);'
        }
        SortInDecrement(Denomination, n);
        cout<<Get_Combination_of_coin(Denomination, m, n)<<endl;
    }
    return 0;
}
