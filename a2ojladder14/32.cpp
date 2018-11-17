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
	ll n,k;
	cin>>n;
	vll a(n);
	fur(i,0,n)cin>>a[i];
	cin>>k;
	vpll b(k,mp(0,0));
	fur(i,0,k){
		cin>>b[i].X>>b[i].Y;
	}
	ll bottom=a[0];
	fur(i,0,k){
		bottom=max(bottom+b[i].Y,a[b[i].X-1]+b[i].Y);
		cout<<bottom-b[i].Y<<'\n';
	}
	return 0;
}
