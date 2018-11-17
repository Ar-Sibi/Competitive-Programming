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
	return a>b?a:b;
}

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	ll n,k,d;
	cin>>n>>k>>d;
	vector<vll> a(k,vll(n));
	fur(i,0,k){
		ll x;
		cin>>x;
	}
	fur(i,0,n){
		fur(j,0,k){
			cin>>a[j][i];
		}
	}
	ll min=INT_FAST64_MAX;
	fur(i,0,k){
		ll sum=0;
		fur(j,0,n){
			sum+=a[i][j];
		}
		ll mmin=INT32_MAX;
		fur(p,(ll)floor((long double)sum/n)-1,(ll)floor((long double)sum/n)+2){
			ll abssum=0;
			fur(o,0,n){
				abssum+=abs(p-a[i][o]);
			}
			if(abssum<mmin){
				mmin=abssum;
			}
		}
		if(min>mmin){
			min=mmin;
		}
	}
	cout<<min;
	return 0;
}
