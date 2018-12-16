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

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    ll n, m, k, x, y;
    cin >> n >> m >> k >> x >> y;
    vector<vll> a(n, vll(m));
    if (n < 2)
    {
        ll turns = n;
        ll val = k / m;
        ll residue = k % m;
        vll a1(n);
        fur(i, 0, m)
        {
            a[0][i] = val;
        }
        fur(i,0,residue){
            a[0][i]++;
        }
        ll min = a[0][0];
        ll max = INT_MIN;
        ll sergei = a[x - 1][y - 1];
        fur(i, 0, n)
        {
            fur(j, 0, m)
            {
                if (min > a[i][j])
                    min = a[i][j];
                if (max < a[i][j])
                    max = a[i][j];
            }
        }
        
        cout << max << " " << min << " " << sergei;
    }
    else
    {
        ll turnno = (2 * m) + ((n - 2) * 2 * m);
        ll val = k / turnno;
        fur(i, 1, n - 1)
        {
            fur(j, 0, m)
            {
                a[i][j] = val * 2;
            }
        }
        fur(i, 0, m)
        {
            a[0][i] = val;
            a[n - 1][i] = val;
        }
        ll residue = k % turnno;
        fur(i, 0, n)
        {
            fur(j, 0, m)
            {
                if (residue == 0)
                    break;
                a[i][j]++;
                residue--;
            }
            if (residue == 0)
                break;
        }
        revf(i, n - 1, 0)
        {
            fur(j, 0, m)
            {
                if (residue == 0)
                    break;
                a[i][j]++;
                residue--;
            }
            if (residue == 0)
                break;
        }
        ll min = INT64_MAX;
        ll max = INT_MIN;
        ll sergei = a[x - 1][y - 1];
        fur(i, 0, n)
        {
            fur(j, 0, m)
            {
                if (min > a[i][j])
                    min = a[i][j];
                if (max < a[i][j])
                    max = a[i][j];
            }
        }
        cout << max << " " << min << " " << sergei;
    }

    return 0;
}
