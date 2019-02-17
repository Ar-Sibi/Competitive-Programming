#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
struct myhash
{
    static uint64_t splitmix64(uint64_t x)
    {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef long double ld;
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

ll modpow(ll base, ll exp, ll modulus)
{
    base %= modulus;
    ll result = 1;
    while (exp > 0)
    {
        if (exp & 1)
            result = (result * base) % modulus;
        base = (base * base) % modulus;
        exp >>= 1;
    }
    return result;
}

ll modinv(ll a, ll m)
{
    ll m0 = m;
    ll y = 0, x = 1;
    if (m == 1)
        return 0;
    while (a > 1)
    {
        ll q = a / m;
        ll t = m;
        m = a % m, a = t;
        t = y;
        y = x - q * y;
        x = t;
    }
    if (x < 0)
        x += m0;
    return x;
}

vll allnodes[10001];
vll visited(10001);
vll set1,set2;
void dfs(ll a,ll h)
{
	if(visited[a])
		return ;
	visited[a]=1;
	if(h%2==1)
		set2.push_back(a);
	else
		set1.push_back(a);
	for(ll i=0;i<allnodes[a].size();i++)
	{
		dfs(allnodes[a][i],h+1);
	}
	return;
}
ll u=0;
void dfs1(ll a)
{
	if(visited[a])
		return ;
	u++;
	visited[a]=1;
	if(u%2==1)
		set2.push_back(a);
	else
		set1.push_back(a);
	for(ll i=0;i<allnodes[a].size();i++)
	{
		dfs1(allnodes[a][i]);
	}
	return;
}
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
        set1.clear();
		set2.clear();
		for(ll i=0;i<=10000;i++)
		{
			allnodes[i].clear();
			visited[i]=0;
		}
		for(ll i=0;i<n-1;i++)
		{
			ll u,v;
			cin>>u>>v;
			allnodes[u].push_back(v);
			allnodes[v].push_back(u);
		}
		dfs(1,0);
		if(set1.size()==set2.size())
		{
			cout<<1<<"\n";
			for(ll i=0;i<set1.size();i++)
				cout<<set1[i]<<" ";
			cout<<"\n";
			for(ll i=0;i<set2.size();i++)
				cout<<set2[i]<<" ";
			cout<<"\n";
			continue;
		}
		for(ll i=0;i<10001;i++)
			visited[i]=0;
		set1.clear();
		set2.clear();
		dfs1(1);
		cout<<2<<"\n";
		for(ll i=0;i<set2.size();i++)
			cout<<set2[i]<<" ";
		cout<<"\n";
		for(ll i=0;i<set1.size();i++)
			cout<<set1[i]<<" ";
		cout<<"\n";
	}
	return 0;
}