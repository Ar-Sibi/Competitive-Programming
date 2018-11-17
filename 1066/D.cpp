#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vll;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;
typedef pair<string, ll> psl;
typedef vector<psl> vpsl;
typedef vector<int> vi;

#define fur(i, a, b) for (ll(i) = (a); i < (b); ++(i))
#define revf(i, a, b) for (ll(i) = (a)-1; (i) >= (b); --(i))
#define mp make_pair
#define mod 1000000007
#define inf 2000000007
#define pb push_back
#define eps 1e-5
#define X first
#define Y second

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	ll n, m;
	cin>>n>>m;
	vector<vll> a(m, vll(n));
	fur(i, 0, m)
	{
		fur(j, 0, n)
		{
			cin >> a[i][j];
		}
	}
	unordered_map<string, ll> mapper;
	fur(j,0,m)
	fur(i,1,n){
		mapper[to_string(a[j][i-1])+"f"+to_string(a[j][i])]++;
	}
	ll start=0;
	ll val=0;
	ll last=0;
	fur(i,1,n){
		if(mapper[to_string(a[0][i-1])+"f"+(to_string(a[0][i]))]==m)last++;
		else{
			val+=(last*(last+1))/2;
			last=0;
		}
	}
	val+=(last*(last+1))/2;
	cout<<val+n;
	return 0;
}
