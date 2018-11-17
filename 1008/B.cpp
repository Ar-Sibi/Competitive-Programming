#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
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

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	vector<pll> s = vector<pll>(n);
	fur(i,0,n){
		int x,y;
		cin>>x>>y;
		if(x<y)
		s[i]=mp(x,y);
		else
		s[i]=mp(y,x);
	}
	vector<vector<ll> > dp = vector<vector<ll> > (n);
	ll val = 1000000000;
	fur(i,0,n){
		if(val>=s[i].Y){
			val = s[i].Y;
		} else if(val>=s[i].X){
			val = s[i].X;
		}else{
			cout<<"NO";
			return 0;
		}
	}
	cout<<"YES";
	return 0;
}
