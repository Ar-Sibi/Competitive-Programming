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
    ll n;
    cin >> n;
    vll a(n);
    vll visitede(n);
    vll visitedo(n);
    queue<ll> qe, qo;
    vvll ar(n, vll(0));
    fur(i, 0, n) {
        cin >> a[i];
        if (i + a[i] < n) {
            ar[i + a[i]].push_back(i);
        }
        if (i - a[i] >= 0) {
            ar[i - a[i]].push_back(i);
        }
        if (a[i] % 2 == 0) {
            visitede[i] = 1;
            qe.push(i);
        } else {
            visitedo[i] = 1;
            qo.push(i);
        }
    }
    while (!qe.empty()) {
        ll i = qe.front();
        // cout << i << "  s" << visitede[i] << "\n";
        qe.pop();
        fur(j, 0, ar[i].size()) if (!visitede[ar[i][j]]) {
            visitede[ar[i][j]] = visitede[i] + 1;
            qe.push(ar[i][j]);
        }
    }
    while (!qo.empty()) {
        ll i = qo.front();
        qo.pop();
        fur(j, 0, ar[i].size()) if (!visitedo[ar[i][j]]) {
            visitedo[ar[i][j]] = visitedo[i] + 1;
            qo.push(ar[i][j]);
        }
    }

    fur(i, 0, n) {
        if (a[i] % 2 == 0) {
            cout << visitedo[i] -1 << " ";
        } else {
            cout << visitede[i] - 1 << " ";
        }
    }
    return 0;
}
