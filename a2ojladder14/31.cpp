#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vll;
typedef vector<vll> vvll;
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

ll numfactors(ll n)
{
	ll count = 0;
	for (ll i = 1; i <= sqrt(n); i++)
	{
		if (n % i == 0)
		{
			// If divisors are equal, print only one
			if (n / i == i)
				count++;

			else // Otherwise print both
				count += 2;
		}
	}
	return count;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	ll n, k;
	cin >> n >> k;
	vll factors(n);

	vvll factorsl(n, vll());
	fur(j, 1, n + 1)
	{
		for (ll i = 1; i <= sqrt(j); i++)
		{
			if (j % i == 0)
			{
				if (j / i == i)
				{
					factorsl[j - 1].push_back(i);
				}
				else
				{
					factorsl[j - 1].push_back(i);
					factorsl[j - 1].push_back(j / i);
				}
			}
		}
	}
	fur(i, 1, n + 1)
	{
		factors[i - 1] = numfactors(i);
	}
	vvll dp(n,vll(k));
	fur(i, 0, n) dp[i][0] = 1;
	fur(i, 1, k)
	{
		fur(l, 0, n)
		{
			fur(j, 0, factorsl[l].size())
			{
				dp[l][i]=(dp[l][i]+dp[factorsl[l][j]-1][i-1])%mod;
			}
		}
	}
	ll sum=0;
		fur(j,0,n){
			sum=(sum+dp[j][k-1])%mod;
		}
		cout<<sum;
	return 0;
}
