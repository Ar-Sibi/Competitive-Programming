#include<bits/stdc++.h>
using namespace std;
int main(){
    long long q;
    cin>>q;
    long long  ones;
    long long  twos;
    cin>>ones;
    cin>>twos;
    long long result=0;
    while(q--){
        long long x;
        cin>>x;
        if(x==1){
            if(ones){
                ones--;
            }else if(twos){
                twos--;
                ones++;
            }else{
                result++;
            }
        }else{
            if(twos){
                twos--;
            }else{
                result+=2;
            }
        }
    }
    cout<<result;
    return 0;
}