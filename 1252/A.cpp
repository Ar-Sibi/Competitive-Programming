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

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    ll n, q;
    cin >> n >> q;
    vll r(n), c(n);
    vll lr(n), lc(n);
    fur(i, 0, n) cin >> r[i];
    fur(j, 0, n) cin >> c[j];
    fur(i, 1, n) {
        if (r[i] % 2 == r[i - 1] % 2) {
            lr[i] = lr[i - 1];
        } else {
            lr[i] = i;
        }
        if (c[i] % 2 == c[i - 1] % 2) {
            lc[i] = lc[i - 1];
        } else {
            lc[i] = i;
        }
    }
    // fur(i,0,n){
    //   cout<<lc[i]<<" ";
    // }
    // cout<<"\n";
    // fur(i,0,n){
    //   cout<<c[i]<<" ";
    // }
    // cout<<"\n";
    while (q--) {
        vll a(2), b(2);
        cin >> a[0] >> b[0] >> a[1] >> b[1];
        a[0]--;
        b[0]--;
        a[1]--;
        b[1]--;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        // cout<<c[1]<<"  "<<c[0]<<lc[1]<<"  "<<lc[0]<<"w\n";
        if (lr[a[1]] <= a[0]&&lc[b[1]]<=b[0]) {
          cout<<"YES\n";
        }else{
          cout<<"NO\n";
        }
        // cout<<endl;
    }
    return 0;
}
