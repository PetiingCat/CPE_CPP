#include <iostream>
#include <malloc.h>
#include <algorithm>
/*
int Get_Combination_of_coin(int amount,unsigned int *ptr){
    int count=0;

    while((*ptr)>0){
        if(amount >= *(ptr)){
            count += (int)(amount / *(ptr));
            amount = amount % *(ptr);
            ptr++;
            }
        else{
            ptr++;
        }
    }
    if(amount==0)return count;
    else return -1;
}*/
int main() {
    int t=0, n=0, m=0;
    unsigned int *Denomination;/*2^31-1 means 4 bytes*/

    std::cin>>t;
    while(t--){
        std::cin>>n>>m;
        Denomination =  (unsigned int*)malloc( sizeof(unsigned int) * (n+1) );
        Denomination[n+1] = 0;
        int i;
        for(i=0;i<n;i++){
            std::cin>>Denomination[i];//same as 'cin>>*(Denomination+i);'
        }
        std::reverse(Denomination,Denomination+n);/*sort n coins Denomination with decrement*/
        /*
        int j;
        for(j=0;j<n;j++){
            cout<<*(Denomination+j)<<endl;
        }*/
        //cout<<Get_Combination_of_coin(m, Denomination)<<endl;
        int count=0;
        while((*Denomination)>0){
            if(m >= *(Denomination)){
                count += (int)(m / *(Denomination));
                m = m % *(Denomination);
                Denomination++;
                }
            else{
                Denomination++;
            }
        }
        if(m==0)std::cout<<count;
        else std::cout<<-1;
    }
    return 0;
}
