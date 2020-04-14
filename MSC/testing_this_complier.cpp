#include <iostream>
#include <numeric>
using namespace std;

int SUM_test_this_onlinejudge(int *ptr, int n){
    int initial_sum  = 0;
    return accumulate(ptr, ptr+n, initial_sum);
}

int main() {
    int n,array[100];
    cin>>n;
    int i,sum=0;
    for(i=0;i<n;i++){
        cin>>array[i];
    }
    cout<<SUM_test_this_onlinejudge(array,n)<<endl;
    return 0;
}
