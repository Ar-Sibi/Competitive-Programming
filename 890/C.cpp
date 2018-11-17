#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
int main(){
    int t;
    cin>>t;
    vector<int> q(t+1);
    vector<bool> q1(t+1);
    q[0]=0;
    for(int i=0;i<t;i++){
        cin>>q[i+1];
    }
    int count=0;
    for(int i=t;i>=0;i--){
        int x=i;
        if(q1[i]!=true){
            count++;
        }
        while(q1[x]==false){
            q1[x]=true;
            x=q[x];
        }
        q[i]=true;
    }
    cout<<count;
    return 0;
}