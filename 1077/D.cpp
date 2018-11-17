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
    int left123(int i) { return (2*i + 1); } 
  
    // to get index of right123 child of node at index i 
    int right123(int i) { return (2*i + 2); } 


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

ll modInverse(ll a, ll m)
{
  ll m0 = m;
  ll y = 0, x = 1;

  if (m == 1)
    return 0;

  while (a > 1)
  {
    // q is quotient
    ll q = a / m;
    ll t = m;

    // m is remainder now, process same as
    // Euclid's algo
    m = a % m, a = t;
    t = y;

    // Update y and x
    y = x - q * y;
    x = t;
  }

  // Make x positive
  if (x < 0)
    x += m0;

  return x;
}
bool xsorter(pll a, pll b)
{
  return a.X < b.X;
}

int main()
{
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  ll n, k;
  cin >> n >> k;
  vll a(n);
  fur(i, 0, n) cin >> a[i];
  unordered_map<ll, ll> s;
  vpll uni(0);
  fur(i, 0, n)
  {
    if (s[a[i]] == 0)
    {
      uni.pb(mp(i, a[i]));
    }
    s[a[i]]++;
  }
  fur(i, 0, uni.size())
  {
    uni[i].X = s[uni[i].Y];
  }
  make_heap(uni.begin(), uni.end(), xsorter);

  vll ans(0);
  unordered_map<ll, ll> t;
  fur(i, 0, k)
  {
    ans.pb(uni.front().Y);
    t[uni.front().Y]++;
    uni[0].X = s[uni[0].Y]/(t[uni.front().Y] + 1);
    ll pos = 0;
    while (left123(pos) < uni.size())
    {
      int smallest = left123(pos);
      if(right123(pos)<uni.size())
      if (uni[right123(pos)].X > uni[left123(pos)].X)
        smallest = right123(pos);
      if (uni[pos].X < uni[smallest].X)
      {
        pll temp=mp(uni[smallest].X,uni[smallest].Y);
        uni[smallest]=uni[pos];
        uni[pos]=temp;
        pos = smallest;
      }
      else
        break;
    }
  }
  fur(i, 0, k)
  {
    cout << ans[i] << " ";
  }
  return 0;
}
