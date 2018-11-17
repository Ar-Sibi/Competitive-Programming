#include<bits/stdc++.h>

using namespace std;
int main(){
    ios_base::sync_with_stdio( false );
    int q;
    int k;
    cin>>q>>k;
    string s;
    cin>>s;
    vector<int> close(26,-1);
    vector<int> open(26,-1);
    for(int i=0;i<s.length();i++){
        if(open[s[i]-'A']==-1){
            open[s[i]-'A']=i;
        }
        close[s[i]-'A']=i;
    }
    int count =0;
    vector<int> pref(s.length(),0);
    //vector<int> another(q,0);
    for(int i=0;i<s.length();i++){
        for(int j=0;j<26;j++)
            count+=(open[j]==i);
        if(count>k){
            cout<<"YES";
            return 0;
        }
        for(int j=0;j<26;j++)
            count-=(close[j]==i);
    }
    cout<<"NO";
    return 0;
}