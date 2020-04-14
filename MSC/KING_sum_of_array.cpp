#include <iostream>
using namespace std;



int main() {
    int n,array[100];
    cin>>n;
    int i,sum=0;
    for(i=0;i<n;i++){
        cin>>array[i];
        sum+=array[i];
    }
    cout<<sum<<endl;
    return 0;
}
