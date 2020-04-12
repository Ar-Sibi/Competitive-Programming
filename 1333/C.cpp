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

ll findSubarraySum(vll arr, ll n, ll sum) {
    // STL map to store number of subarrays
    // starting from index zero having
    // particular value of sum.
    unordered_map<ll, ll,myhash> prevSum;

    ll res = 0;

    // Sum of elements so far.
    ll currsum = 0;
    vll f(n, 0);
    ll lasti = 0;
    prevSum[0] = 0;
    vll dp(n+1);
    for (ll i = 0; i < n; i++) {
        // Add current element to sum so far.
        currsum += arr[i];

        // If currsum is equal to desired sum,
        // then a new subarray is found. So
        // increase count of subarrays.

        // currsum exceeds given sum by currsum
        //  - sum. Find number of subarrays having
        // this sum and exclude those subarrays
        // from currsum by increasing count by
        // same amount.
        // cout<<currsum<<"\n";
        // else
        // prevSum[currsum] = i+1;
        dp[i+1]=dp[i];
        if (prevSum[currsum - sum]||currsum==sum) {
            if (arr[i] != 0) {
                // ll f = (i + 1 - max<ll>(prevSum[currsum] - 1, lasti));
                // cout << "d" << i + 1 << " " << prevSum[currsum] - 1 << " "
                //      << lasti <<" "<<f<< "\n";
                // cout<<i<<" "<<prevSum[currsum-sum]<<"\n";
                dp[i+1] = max(dp[i+1],prevSum[currsum - sum]+1);
            } else {
                ll f = ((i - 1) - max<ll>(prevSum[currsum] - 1, lasti));
                res += (f * f + 1)/2;
                lasti = i + 1;
                dp[i+1]=i+1;
            }
            // cout<<res<<"\n";
        }
        // Add currsum value to count of
        // different values of sum.
        prevSum[currsum] = i + 1;
    }
    
    vll ans(n);
    fur(j,0,n){
      ll g=(j+1)-dp[j+1];
      // cout<<g<<"\n";
      ans[j]=(g*(g+1))/2;
    }
    // cout<<"\n";
    fur(i,1,n){ 
      ll overlap=(i-1)-dp[i+1];
      overlap++;
      ans[i]+=ans[i-1]-(overlap*(overlap+1))/2;
    }
    // fur(i,0,n){ 
    //   cout<<ans[i]<<" ";
    // }
    return ans[n-1];
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    ll n;
    cin >> n;
    vll a(n);
    fur(i, 0, n) cin >> a[i];
    ll ans = findSubarraySum(a, n, 0);
    // cout<<ans;
    // cout<<((n*(n-1))-ans);
    cout << ans;
    return 0;
}
