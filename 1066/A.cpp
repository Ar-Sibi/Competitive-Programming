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

#define fur(i, a, b) for (int(i) = (a); i < (b); ++(i))
#define revf(i, a, b) for (int(i) = (a)-1; (i) >= (b); --(i))
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
	ll t;
	cin >> t;
	vll a(t);
	ll n=t;
	fur(i, 0, n) cin >> a[i];
	ll max = 0;
	fur(i, 0, n)
	{
		if (a[i] > max)
		{
			max = a[i];
		}
	}
	for(ll j = 0; j >= 0; j++)
	{
		max+=j;
		ll sum = 0, sum2 = 0;
		fur(i, 0, n)
		{
			sum += max - a[i];
			sum2 += a[i];
		}
		if(sum>sum2){
			cout<<max;
			return 0;
		}
		max-=j;

	}

	return 0;
}
