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
	vector<string> x(4,"abcd");
	for(ll f=0;f<3;f++){
		for(ll g=0;g<4;g++)
		x[f+1][g]=x[f][g]+4;
	}
	for(ll f=0;f<4;f++)
	cout<<x[f]<<endl;
	cout<<endl;
	for(ll f=0;f<4;f++)
	for (ll g = f + 1; g < 4; g++)
	{
		char er = x[f][g];
		x[f][g] = x[g][f];
		x[g][f] = er;
	}
	for(ll f=0;f<4;f++)
	cout<<x[f]<<endl;
	return 0;
}
