#include <iostream>
#include <cmath>
using namespace std;

void CheckDigit(int n){
    if(n<10)cout<<'0'<<n;
    else cout<<n;
}

double CompoundInterest(int cnt,int n,double PV,double r){
    double sum=0,FV=0,i;

    for(i=n;i>0;i--){
        FV=PV*pow(1+r*0.01,i);
        CheckDigit(cnt);cout<<" ";CheckDigit(i);cout<<" "<<FV<<endl;
        sum+=FV;
        cnt++;
    }
    return sum;
}

/*Recursion*/
double CompoundInterest2(int cnt,int n,double PV,double r){
    double FV=0;
    if(!n)return FV;

    FV=PV*pow(1+r*0.01,n);
    CheckDigit(cnt);cout<<" ";CheckDigit(n);cout<<" "<<FV<<endl;

    return FV+CompoundInterest2(++cnt,--n,PV,r);
}

int main()
{
    int n,m,r;
    while(cin>>n>>m>>r){
        cout<<CompoundInterest2(1,n,m,r)<<endl;
    }
    return 0;
}
