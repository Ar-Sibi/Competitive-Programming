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
typedef long long ld;
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
bool comp(pll a, pll b) {
    if (a.X == b.X) {
        return a.Y > b.Y;
    } else {
        return a.X < b.X;
    }
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    ll n;
    cin >> n;
    vpll a(n);
    fur(i, 0, n) {
        cin >> a[i].X >> a[i].Y;
        if (a[i].X > a[i].Y) {
            ll t = a[i].Y;
            a[i].Y = a[i].X;
            a[i].X = t;
        }
        // if(a[i].X!=a[i].Y){
        //   a.push_back({a[i].Y,a[i].X});
        // }
    }
    n = a.size();
    sort(a.begin(), a.end(), comp);
    pll curr = a[0];
    map<ll, ll> m;
    ll maxh = -1;
    maxh = a[n - 1].Y;
    long long maxarea = 0;
    // cout<<"sdads\n";
    revf(i, n, 0) {
        cout<<a[i].X<<"  "<<a[i].Y<<"\n";
        maxarea = max<long long>((a[i].X * a[i].Y * 1.0f), maxarea);
    }
    revf(i, n - 1, 0) {
        maxarea = max<long long>(
            (min<ll>(a[i].X, a[i + 1].X) * min<ll>(a[i].Y, a[i + 1].Y)) * 2,
            maxarea);
        if (a[i].Y != a[i + 1].Y) {
            cout<<a[i].X<<"  "<<a[i].Y<<"f\n";
            m[a[i + 1].X] = maxh;
            maxarea = max<long long>(maxarea, 2 * a[i].X * min(a[i].Y, maxh));
        }
        maxh = max(a[i].Y, maxh);
    }
    if (maxarea % 2 == 0) {
        cout << maxarea / 2 << ".0\n";
    } else {
        cout << maxarea / 2 << ".5";
    }
    return 0;
}
