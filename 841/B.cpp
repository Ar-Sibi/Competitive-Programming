#include<bits/stdc++.h>
using namespace std;
int main(){ 
    cin.tie(NULL);
    ios_base::sync_with_stdio( false );
    int x;
    long long sum=0;
    cin>>x;
    bool oddpresent = false;
    while(x--){
        int y;
        cin>>y;
        if(y%2==1)
        oddpresent=true;
        sum+=y;
    }
    if(sum%2==0){
        if(oddpresent)
        cout<<"First";
        else
        cout<<"Second";
    }else{
        cout<<"First";
    }
}