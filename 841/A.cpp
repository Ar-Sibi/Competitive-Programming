#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> colors(26,0);
    int n;
    cin>>n;
    int friends=0;
    cin>>friends;
    string s;
    cin>>s;
    long long totalcount=0;
    locale loc;
    tolower(s,loc);
    for(int i=0;i<s.length();i++){
        colors[s[i]-'a']++;
        totalcount++;
    }
    if(totalcount<friends){
        cout<<"NO";
        return 0;
    }
    for(int i=0;i<26;i++){
        if(colors[i]>friends){
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
    return 0;
}