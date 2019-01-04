#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vll;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;
typedef pair<string,ll> psl;
typedef vector<psl> vpsl;
typedef vector<int> vi;

#define fur(i,a,b) for(int (i)=(a);i<(b);++(i))
#define revf(i,a,b) for(int (i)=(a)-1;(i)>=(b);--(i))
#define mp make_pair
#define mod 1000000007
#define inf 2000000007
#define pb push_back
#define eps 1e-5
#define X first
#define Y second

ll min(ll a,ll b){
	return a<b?a:b;
}
ll max(ll a,ll b){
	return a>b?a:b;
}

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	ll t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		vll prefix(s.length()+2,0);
		fur(i,0,s.length()){
			if(s[i]!='.'){
				prefix[max(i-(s[i]-'0'),0)]+=1;
				prefix[min(i+(s[i]-'0')+1,s.length())]-=1;
			}
		}
		bool ans=false;
		fur(i,1,s.length()+1){
			prefix[i]=prefix[i]+prefix[i-1];
			if(prefix[i]>1)
			ans=true;
		}
		if(ans!=true){
			cout<<"safe\n";
		}else{
			cout<<"unsafe\n";
		}

	}
	return 0;
}
