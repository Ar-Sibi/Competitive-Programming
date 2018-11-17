#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
int main(){
    unordered_map<int,int> s;
    int q;
    cin>>q;
    vector<int>d(0);
    vector<int>r(q);
    for(int i=0;i<q;i++){
        int x;
        cin>>x;
        r[i]=x;
        if(s[x]==0){
            s[x]=1;
            d.push_back(x);
        }
    }
    int count=0;
    for(int i=r.size()-1;i>=0;i--){
        
        if(s[r[i]]==1){
            if(count==d.size()-1){
            cout<<r[i];
            return 0;
            }
            s[r[i]]=2;
            count++;
        }
    }
    return 0;
}