#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int>d(6);
    long sum=0;
    for(int i=0;i<6;i++){
    cin>>d[i];
    sum+=d[i];
    }
    if(sum%2!=0){
        cout<<"NO";
        return 0;
    }
    int req = sum/2;
    sort(d.begin(),d.end());
    req-=d[0];
    if(req>=0){
        for(int i=1;i<6;i++){
            for(int j=i+1;j<6;j++){
                if(d[i]+d[j]==req){
                    cout<<"YES";
                    return 0;
                }
            }
        }
        cout<<"NO";
        return 0;
    }else{
        cout<<"NO";
    }
    return 0;
}