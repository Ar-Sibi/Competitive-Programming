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
#define fur1(i,a,b) for(ll (i)=(a);i<=(b);++(i))
#define fur(i,a,b) for(ll (i)=(a);i<(b);++(i))
#define revf(i,a,b) for(ll (i)=(a)-1;(i)>=(b);--(i))
#define mp make_pair
#define mod 1000000007
#define inf 2000000007
#define pb push_back
#define eps 1e-5
#define X first
#define Y second

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	ll t;
	cin>>t;
	vll x(0);
	unordered_map<ll,int> s;
	fur(i,2,999999){
		bool flag=false;
		for(ll j=2;j<=sqrt(i);j++){
			if(i%j==0){
				flag=true;
				break;
			}
		}
		if(!flag){
			s[i*i]=1;
		}
	}
	while(t--){
		ll n;
		cin>>n;
		if(s[n]==1){
			cout<<"YES\n";
		}else{
			cout<<"NO\n";
		}
	}


	
	return 0;
}
