#include <iostream>
using namespace std;

void PrintTriangle(int n){
    int i,j,k;
    for(i=0;i<n;i++){

        if(i<n-1){
            for(j=0;j<(n-i-1);j++){
                cout<<' ';
            }
        }
        for(k=0;k<(2*i+1);k++){
            cout<<'*';
        }
        cout<<'\n';
    }
}

int main()
{
    int n;
    while(cin>>n){
        PrintTriangle(n);
    }
    return 0;
}
