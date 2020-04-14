#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    /*cin.sync_with_stdio(false), cin.tie(0), cout.tie(0);*/
    int Tmoney, type_of_coins, coin[1001], opt_miniumn[1001]={};int t;
    cin>>t;
    while(t--){
        cin>>type_of_coins>>Tmoney;
        int i,j;
        for(i=1;i<=Tmoney;i++)
            opt_miniumn[i]=1000;
        for(i=0;i<type_of_coins;i++)
            cin>>coin[i];
        sort(coin, coin+type_of_coins);
        /*for(i=0;i<type_of_coins;i++)
            cout<<coin[i]<<" ";*/
        for(i=0;i<type_of_coins;i++){
            for(j=coin[i];j<=Tmoney;j++)
                opt_miniumn[j] = min(opt_miniumn[j-coin[i]]+1,opt_miniumn[j]);
        }
    if(opt_miniumn[Tmoney]==1000){opt_miniumn[Tmoney]=-1;}
    cout << opt_miniumn[Tmoney] <<endl;
    }
    return 0;
}
