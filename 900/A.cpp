#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    int X=0;
    int Y=0;
    while(t--){
        int x;
        int y;
        cin>>x>>y;
        if(x<0)
            X++;
            else 
            Y++;
    }
    if(X==1||Y==1||(X==0&&Y>1)||(Y==0&&X>1))
        cout<<"Yes";
        else
        cout<<"No";
    return 0;
}