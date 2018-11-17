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

int comp(pll a,pll b){
	if(a.X>b.X){
		return 1;
	}else{
		if(a.X<a.X){
			return 0;
		}else{
			return a.Y>b.Y
		}
	}
}
int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	ll n,k;
	cin>>n;
	vpll a(n,mp(0,0));
	fur(i,0,n){
		cin>>a[i].X>>a[i].Y;
	}

	
	return 0;
}
