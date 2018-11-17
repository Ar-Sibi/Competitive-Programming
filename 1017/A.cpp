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
	if(a.Y>b.Y){
		return 1;
	}else{
		if(a.Y<b.Y){
			return 0;
		}else{
			return a.X>b.X?0:1;
		}
	}
}

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	ll n;
	cin>>n;
	vpll ans(n);
	fur(i,0,n){
		ll a,b,c,d;
		cin>>a>>b>>c>>d;
		ans[i]=mp(i,a+b+c+d);
	}
	sort(ans.begin(),ans.end(),comp);
	fur(i,0,n){
		if(ans[i].X==0)
			cout<<i+1<<endl;
	}
	
	return 0;
}
