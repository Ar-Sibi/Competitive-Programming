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

ll setBitNumber(ll n)
{
    if (n == 0)
        return 0;

    ll msb = 0;
    while (n != 0)
    {
        n = n / 2;
        msb++;
    }

    return msb;
}

ll recursivelyGiveAnswer(ll r, ll v)
{
    ll ans1;
    vll bits(setBitNumber(v));
    vll bitsr(setBitNumber(r));
    // cout<<bits.size()<<endl;
    ll vcopy = v;
    fur(i, 0, bits.size())
    {
        bits[i] = v % 2;
        v /= 2;
    }
    v = vcopy;
    ll max = 1;
    fur(i, 0, bits.size())
    {
        if (bits[i])
        {
            max *= 1;
        }
        else
        {
            max *= 2;
        }
    }
    ll rcopy = r;
    r = r >> setBitNumber(v);
    ll ans = max * r;
    r = rcopy;
    rcopy = r;
    fur(i, 0, bitsr.size())
    {
        bitsr[i] = r % 2;
        r /= 2;
    }
    r = rcopy;
    ll val = 1;
    bool greater = false;
    bool equal = true;
    ll ind = 0;
    revf(i, bits.size(), 0)
    {
        if (equal)
        {
            if (bitsr[i] > bits[i])
            {
                equal = false;
                val=recursivelyGiveAnswer(r%modpow(2,i+1,mod),v%modpow(2,i+1,mod));    
            }
            else if (bitsr[i] < bits[i])
            {
                val = 0;
                break;
            }
            else
            {
                equal = true;
            }
        }
        else
        {
            
        }
    }
    // cout << "\nf" << max << " " << val << "\n";
    ans = ans + val;
    ans1 = ans;
    return ans1;
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    ll q;
    cin >> q;
    while (q--)
    {
        ll l, r, v;
        cin >> l >> r >> v;
        ll count = setBitNumber(v);
        // cout<<"XXX"<<recursivelyGiveAnswer(r,v);
        if (r < v)
        {
            cout << "0\n";
        }
        else
        {   
            ll ans1 = 0, ans2 = 0;
            ans1=recursivelyGiveAnswer(r,v);
            ans2=recursivelyGiveAnswer(l,v);
            // cout<<ans1<<"FFF"<<ans2<<"\n";
            // cout<<l<<" "<<v<<"\n";
            if((l>=v)&&((l&v)==v)){
                ans2--;
            }
            cout<<ans1-ans2<<"\n";
        }
    }

    return 0;
}
