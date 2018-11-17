#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
bool cmp1(pair<int,int>a,pair<int,int>b){
    return a.second>b.second;
}
bool cmp(pair<int,int>a,pair<int,int>b){
    return a.second>b.second;
}
int main(){ 
    cin.tie(NULL);
    ios_base::sync_with_stdio( false );
    unordered_map<int,int> sd;
    int n;
    cin>>n;
    vector<int> a(n);
    vector<int> d(n);
    vector<pair<int,int>> b(n);
    vector<pair<int,int> > c(n);
    for(int i=0;i<n;i++){
    int z;
    cin>>z;
    a[i]= z;
    }
    for(int i=0;i<n;i++){
        int z;
    cin>>z;
    d[i]=z;
    b[i] = pair<int,int>(i,z);
    }
    sort(b.begin(),b.end(),cmp1);
    sort(a.begin(),a.end());
    for(int i=0;i<n;i++){
        sd[b[i].first]=i;
    }
    
    for(int i=0;i<n;i++){
        cout<<a[sd[i]]<<" ";
    }
    return 0;
}