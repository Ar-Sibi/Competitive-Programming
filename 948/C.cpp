#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
int main(){
    unordered_map<int,int> s;
    int x;
    cin>>x;
    vector<long> v1(x);
    vector<long> v2(x);
    long long melted=0;
    int meltcount=0;
    for(int i=0;i<x;i++)cin>>v1[i];
    for(int i=0;i<x;i++)cin>>v2[i];
    for(int i=0;i<x;i++){
        if(v1[i]<v2[i])
            s[i]++;
    }
}