#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
struct myhash {
    static uint64_t splitmix64(uint64_t x) {
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
typedef vector<vll> vvll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;
typedef pair<string,ll> psl;
typedef vector<psl> vpsl;
typedef vector<int> vi;

#define fur(i,a,b) for(ll (i)=(a);i<(b);++(i))
#define revf(i,a,b) for(ll (i)=(a)-1;(i)>=(b);--(i))
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


int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
  ll n;
  cin>>n;
  vll ma(0);
  vll mi(0);
  ll gg=0;
  fur(i,0,n){
    ll q;
    cin>>q;
    ll a=INT_MAX;
    ll b=INT_MIN;
    bool mark=false;
    while(q--){
      ll y;
      cin>>y;
      if(y<a)a=y;
      if(y>a)mark=true;
      if(y>b)b=y;
    }
    if(mark)gg++;
    else{
      mi.push_back(a);
      ma.push_back(b);
    }
  }
  sort(ma.begin(),ma.end());
  sort(mi.begin(),mi.end());
  reverse(mi.begin(),mi.end());    
  reverse(ma.begin(), ma.end());
  ll ans=gg*gg+2*gg*(n-gg);
  ll dda=0; 
  fur(i,0,n-gg){
    // cout<<mi[i]<<" "<<ma[i]; maxa > mina 
    // cout<<mi[i]<<":"<<"\n";
    fur(j,dda,n-gg){
      // cout<<ma[j]<<" ";
      if(mi[i]<ma[j]){dda++;}
      else break;
    }
    // cout<<"\n";
    ans+=dda;
    // ans+=(n-gg)-dda;
    // cout<<"\n";
    // }
    // for(;j<n-gg;){
    //   cout<<mi[i]<<ma[j]<<"\n";
    //   if(mi[i]>ma[j])j++;
    //   else break;
    // }
    // cout<<j<<"\n";
    // ans+=(n-gg)-j;
  }
  cout<<ans;

	return 0;
}
