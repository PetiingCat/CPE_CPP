#include <iostream>
#include <string.h>
using namespace std;

void swap(int &A, int &B){
    int temp = A;
    A = B;
    B = temp;
}
void swap2(int *A, int *B){
    int temp = *A;
    *A = *B;
    *B = temp;
}
void PrintArray(int &A,int n){
    int i,*ptrA;
    ptrA=&A;
    for(i=0;i<n;i++)
        cout<<ptrA[i]<<" ";
    cout<<endl;
}

void BubbleSort(int &A,int n){
    int i,j,*idptr,*deptr,*ptrA,cnt=0;
    ptrA=&A;
    for(i=n-1;i>0;i--){//cout<<++cnt<<" times:"<<endl;
        for(j=0;j<i;j++){
            if(ptrA[j]>ptrA[j+1]){
                swap(ptrA[j],ptrA[j+1]);
            }//PrintArray(A,n);
        }
    }
}

void BubbleSort2(int A[],int n){
    int i,j,k,*idptr,*deptr,cnt=0,t;
    for(i=n-1;i>0;i--){
        cout<<++cnt<<" times:"<<endl;t=0;
        for(idptr=&A[0],deptr=&A[1];t<i;deptr++){
            t++;
            if(*idptr>*deptr){
                swap2(idptr,deptr);
                idptr=deptr;
                deptr=idptr;
            }
            //PrintArray(*A,n);
            for(k=0;k<n;k++)
                cout<<A[k]<<" ";
            cout<<endl;
        }
    }
}

int BinarySearch(int a[],int TA,int L,int R,int cnt){
    if(L>R){cout<<"Unfind cost "<<cnt<<" times"<<endl; return 0;}
    if(TA==a[((L+R)/2)]){cout<<"FIND at "<<cnt<<" times"<<endl; return 1;}
    else if(TA<a[((L+R)/2)])return BinarySearch(a,TA,L,((L+R)/2)-1,++cnt);
    else if(TA>a[((L+R)/2)])return BinarySearch(a,TA,((L+R)/2)+1,R,++cnt);
}

int main(){
    int X;
    int n,f;
    while(cin>>n){
        int *a = new int [n];
        int i;
        for(i=0;i<n;i++)
            cin>>a[i];
        cin>>f;
        BubbleSort(*a,n);
        //BubbleSort2(a,n);
        PrintArray(*a,n);
        X=BinarySearch(a,f,0,n-1,1);
    }
    return 0;
}
