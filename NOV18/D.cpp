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

ll max(ll a,ll b){
	return a>b?a:b;
}

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	ll n,q,k;
	cin>>n>>q>>k;
	vll ar(n);
	ll zeroes=0;
	fur(i,0,n){
		cin>>ar[i];
		if(ar[i]!=1)
		zeroes++;
	}
	string s;
	cin>>s;
	if(zeroes==0){
		fur(i,0,s.length()){
			if(s[i]=='?'){
				cout<<((n>k)?k:n)<<'\n';
			}
		}
	}else{
		ll lind=0,ls=0;
		ll currs=0;
		for(ll i=0;i<2*n;i++){
			if(ar[i%n]==1){
				currs++;
			}else{
				if(i!=0){
					if(ls<currs){
						lind=((n+i-1)%n);
						ls=currs;
					}
					currs=0;
				}
			}
		}
		ll sind=0,ss=0;
		currs=0;
		ll f=0;
		// cout<<" "<<((lind)%n)<<endl;
		for(ll i=((lind+1)%n);i!=(n+lind-(ls))%n;i=(i+1)%n){
			// cout<<i<<" "<<ar[i]<<" "<<currs<<endl;
			if(ar[i%n]==1){
				currs++;
			}else{
				if(f){
					if(ss<currs){
						sind=((n+i-1)%n);
						ss=currs;
					}
					currs=0;
				}
			}
			f=1;
		}
		if(ss<currs){
			sind=((n+lind-ls-1)%n);
			ss=currs;
		}
		lind++;
		sind++;
		// cout<<ls<<" "<<lind<<" "<<ss<<" "<<sind<<endl;
		fur(J,0,s.length()){
			if(s[J]=='!'){
				lind=(lind+n+1)%n;
				sind=(sind+n+1)%n;
			}else{
				if(lind-ls<0){
					ll maximum=max(lind,ls-lind);
					ll ans=max(maximum,ss);
					cout<<((ans>k)?k:ans)<<'\n';
				}else{
					cout<<((ls>k)?k:ls)<<'\n';
				}
			}
		}
	}



	
	return 0;
}
