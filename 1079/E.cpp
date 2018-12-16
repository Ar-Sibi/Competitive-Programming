#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    int start=1;
    while(n>0){
        if(n&1==1){
            cout<<start<<" ";
        }
        start*=2;
        n/=2;
    }	
	return 0;
}
