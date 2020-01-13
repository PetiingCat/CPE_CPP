#include <iostream>
#include <string>
using namespace std;

int AlphabetToNum(string s){
    int sum=0,i;
    for(i=0;i<s.length();i++){
        if(s[i]>='a'){
            sum+=(s[i]-'a'+1);
        }else{
            sum+=(s[i]-'A'+1);
        }
    }
    return sum;
}

int main()
{
    string s="";
    while(cin>>s){
    cout<<s+':'<<AlphabetToNum(s)<<endl;
    }
   return 0;
}