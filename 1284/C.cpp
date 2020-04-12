#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
struct myhash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM =
            chrono::steady_clock::now().time_since_epoch().count();
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

ll modpow(ll base, ll exp, ll modulus) {
    base %= modulus;
    ll result = 1;
    while (exp > 0) {
        if (exp & 1) result = (result * base) % modulus;
        base = (base * base) % modulus;
        exp >>= 1;
    }
    return result;
}

ll modinv(ll a, ll m) {
    ll m0 = m;
    ll y = 0, x = 1;
    if (m == 1) return 0;
    while (a > 1) {
        ll q = a / m;
        ll t = m;
        m = a % m, a = t;
        t = y;
        y = x - q * y;
        x = t;
    }
    if (x < 0) x += m0;
    return x;
}
ll modmult(ll a, ll b, ll m) { return (a * b) % m; }
ll modfact(ll n, ll m) {
    ll result = 1;
    while (n > 1) {
        result = (long long)(result * n) % m;
        n -= 1;
    }
    return result % m;
}
ll bc(ll n, ll k, ll m) {
    // cout<<"weqweqweqw"<<inverse(modfact(k))<<endl;
    // cout<<modmult(modfact(n), inverse(modfact(k)))<<"wops"<<endl;
    return modmult(modmult(modfact(n, m), modinv(modfact(k, m), m), m),
                   modinv(modfact(n - k, m), m), m);
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    ll n, m;
    cin >> n >> m;
    vll f(n);
    f[0] = 1;
    fur(i, 1, n + 1) f[i] = (f[i - 1] * i) % m;
    ll f2 = 1;
    fur(i, 1, n + 1) f2 = (f2 * i) % m;
    f2 = (f2 * n) % m;
    ll ans = 0;

    fur(i, 2, n + 1) {ans+=(((n-i)+1)*f[i]*f[n-i]);
  cout<<ans<<"\n";
  ans%=m;
    }
    cout << ans;
    // ans=((n*(n-1))/2)%m;
    // ans=(ans*ans)%m;
    // ans = (ans*2) % m;
    ans = (ans + f2) % m;
    cout << f2 << "\n";
    cout << ans;

    return 0;
}
