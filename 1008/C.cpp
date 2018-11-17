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

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	ll n;
	cin >> n;
	vector<ll> ar = vector<ll>(n);
	vector<ll> v = vector<ll>(n);
	unordered_map<ll, ll> s;
	fur(i, 0, n)
	{
		cin >> ar[i];
		v[i] = ar[i];
		s[ar[i]]++;
	}
	vector<ll>::iterator ip;
	sort(v.begin(), v.end());
	// Using std::unique
	ip = unique(v.begin(), v.end());
	// Now v becomes {1 3 10 1 3 7 8 * * * * *}
	// * means undefined

	// Resizing the vector so as to remove the undefined terms
	v.resize(distance(v.begin(), ip));
	ll count = 0;
	ll li = 0;
	ll lower = 0;
	ll higher = 0;
	lower += s[v[li]];
	for (int i = 1; i < v.size(); i++)
	{	
			count += min(s[v[i]],lower);
			lower= lower - min(s[v[i]],lower);
			lower+=s[v[i]];
	}
	cout << count;
	return 0;
}
