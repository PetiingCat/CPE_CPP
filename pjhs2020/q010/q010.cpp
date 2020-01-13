#include <iostream>
using namespace std;

void swap(int& a, int& b){
    int temp=a;
    a=b;
    b=temp;
}

void ans(int n,int m){
    if(n>m)swap(n,m);

    int i,flag=0;
    for(i=n;i<=m;i++){
        if((i%5==2)&&(i%8==1)&&(i%7==1)){
            cout<<i<<endl;;
            flag=1;
        }
    }
    if(flag==0)cout<<"µL¸Ñ"<<endl;;
}

int main()
{
    int n,m;
    while(cin>>n>>m){
        ans(n,m);
    }
    return 0;
}
