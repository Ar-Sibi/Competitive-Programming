#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vll;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;
typedef pair<string,ll> psl;
typedef vector<psl> vpsl;
typedef vector<int> vi;

#define fur(i,a,b) for(int (i)=(a);i<(b);++(i))
#define revf(i,a,b) for(int (i)=(a)-1;(i)>=(b);--(i))
#define mp make_pair
#define mod 1000000007
#define inf 2000000007
#define pb push_back
#define eps 1e-5
#define X first
#define Y second
#define inc 0
#define dec 1
    

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


int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
    ll n,q;
    cin>>n>>q;
    vll a(n);
    vll dp1(n);
    vll dp2(n);
    fur(i,0,n)cin>>a[i];
    ll m=1,l=n;
    fur(i,0,n-1){
        if(a[i]<=a[i+1]){
            dp1[i]=m;
            dp1[i+1]=m;
        }else{
            m++;
        }
        if(a[i]>=a[i+1]){
            dp2[i]=l;
            dp2[i+1]=l;
        }else{
            l++;
        }
    }
    fur(i,0,n-1){
        if(dp1[i]!=0&&dp1[i+1]!=dp1[i]){
            ll val=dp1[i];
            ll eqval=dp2[i];
            // cout<<i<<endl;
            while(true){
                if(dp2[i]==eqval){
                    dp2[i]=val;
                }else{
                    break;
                }
                i++;
                if(i==n){
                    break;
                }
            }
        }
    }
    while(q--){
        ll x, y;
        cin>>x>>y;
        x--;y--;
        if(n==1){
            cout<<"Yes\n";
        }else 
        if((dp1[x]!=0&&dp1[x]==dp1[y])||(dp1[x]!=0&&dp1[x]==dp2[y])||(dp2[x]!=0&&dp2[x]==dp2[y])){
            cout<<"Yes\n";
        }else{
            cout<<"No\n";
        }
    }
    // fur(i,0,n){
    //     cout<<dp1[i]<<" ";
    // }
    // cout<<endl;
    // fur(i,0,n){
    //     cout<<dp2[i]<<" ";
    // }
}