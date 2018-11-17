#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
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

int min(ll x, ll y)
{
	return x > y ? y : x;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	unordered_map<string, int> s;
	unordered_map<string, int> u;

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string q;
		cin >> q;
		s[q]++;
	}
	for (int i = 0; i < n; i++)
	{
		string q;
		cin >> q;
		u[q]++;
	}
	ll count = abs(s["S"] - u["S"]);
	count += abs(s["M"] - u["M"]);
	count += abs(s["L"] - u["L"]);
	count += abs(s["XS"] - u["XS"]);
	count += abs(s["XL"] - u["XL"]);
	count += abs(s["XXS"] - u["XXS"]);
	count += abs(s["XXL"] - u["XXL"]);
	count += abs(s["XXXS"] - u["XXXS"]);
	count += abs(s["XXXL"] - u["XXXL"]);
	cout << count/2;
	return 0;
}
