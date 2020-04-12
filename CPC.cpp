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
    ll k;
    cin >> n >> k;
    // vpll b(k);
    queue<pair<pll, ll>> q;
    fur(i, 0, k) {
        ll x, y;
        cin >> x >> y;
        // b[i]={x,y};
        q.push({{x, y}, 0});
    }
    vvll m(n, vll(n));
    ll ans = 0;
    while (!q.empty()) {
        pair<pll, ll> top = q.front();
        m[top.X.X][top.X.Y] = 1;
        q.pop();
        ans = max(ans, top.Y);
        if (top.X.X - 1 >= 0) {
            if (!m[top.X.X - 1][top.X.Y]) {
                q.push({{top.X.X - 1, top.X.Y}, top.Y + 1});
                m[top.X.X - 1][top.X.Y] = 1;
            }
        }
        if (top.X.Y - 1 >= 0) {
            if (!m[top.X.X][top.X.Y - 1]) {
                q.push({{top.X.X, top.X.Y - 1}, top.Y + 1});
                m[top.X.X][top.X.Y - 1] = 1;
            }
        }
        if (top.X.X + 1 <= n - 1) {
            if (!m[top.X.X + 1][top.X.Y]) {
                q.push({{top.X.X + 1, top.X.Y}, top.Y + 1});
                m[top.X.X + 1][top.X.Y] = 1;
            }
        }
        if (top.X.Y + 1 <= n - 1) {
            if (!m[top.X.X][top.X.Y + 1]) {
                q.push({{top.X.X, top.X.Y + 1}, top.Y + 1});
                m[top.X.X][top.X.Y + 1] = 1;
            }
        }
    }
    cout << ans;
    return 0;
}

#include <iostream>
#include <vector>
using namespacestd;
int find(vector<int> &C, intx) {
    return (C[x] == x) ? x : C[x] = find(C, C[x]);
}
Void merge(vector<int> &C, intx, inty) { C[find(C, x)] = find(C, y); }
Int main() {
    int n = 5;
    vector<int> C(n);
    for (inti = 0; i < n; i++) C[i] = i;
    merge(C, 0, 2);
    merge(C, 1, 0);
    merge(C, 3, 4);
    for (inti = 0; i < n; i++) cout << i << " " << find(C, i) << endl;
    return 0;
}

#include <memory.h>
struct edge {
    inte, nxt;
};
intV, E;
edge e[MAXE], er[MAXE];
intsp[MAXV], spr[MAXV];
intgroup_cnt, group_num[MAXV];
boolv[MAXV];
intstk[MAXV];
void fill_forward(intx) {
    inti;
    v[x] = true;
    for (i = sp[x]; i; i = e[i].nxt)
        if (!v[e[i].e]) fill_forward(e[i].e);
    stk[++stk[0]] = x;
}
voidfill_backward(intx) {
    inti;
    v[x] = false;
    group_num[x] = group_cnt;
    for (i = spr[x]; i; i = er[i].nxt)
        if (v[er[i].e]) fill_backward(er[i].e);
}
voidadd_edge(intv1,
             intv2)  // add edge v1->v2
{
    e[++E].e = v2;
    e[E].nxt = sp[v1];
    sp[v1] = E;
    er[E].e = v1;
    er[E].nxt = spr[v2];
    spr[v2] = E;
}
void SCC() {
    inti;
    stk[0] = 0;
    memset(v, false, sizeof(v));
    for (i = 1; i <= V; i++)
        if (!v[i]) fill_forward(i);
    group_cnt = 0;
    for (i = stk[0]; i >= 1; i--)
        if (v[stk[i]]) {
            group_cnt++;
            fill_backward(stk[i]);
        }
}
