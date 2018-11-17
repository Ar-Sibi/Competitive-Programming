#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
int main(){
    ios_base::sync_with_stdio( false );
    cin.tie(NULL);
    long queries;
    cin>>queries;
    unordered_map<long long,int> iscube;
    for(long long i=1;i<1000000;i++){
        iscube[i*i*i]=1;
    }
    while(queries--){
        long long x,y;
        cin>>x>>y;
        long double ld = x*y;
        if(iscube[x*y])
        cout<<"Yes\n";
        else
        cout<<"No\n";
    }
    return 0;
}