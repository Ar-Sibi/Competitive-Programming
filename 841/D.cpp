#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int x;
    cin>>x;
    int edges;
    cin>>edges;
    vector<pair<int, vector<int> > > adj (x,pair<int,vector<int> >(0,vector<int>(0)));
    for(int i=0;i<x;i++){
        int d;
        cin>>d;
        adj[i].first=d;
    }
    for(int i=0;i<edges;i++){
        int x;
        int y;
        cin>>x>>y;
        x--;
        y--;
        adj[x].second.push_back(y);
        adj[y].second.push_back(x);
    }
}