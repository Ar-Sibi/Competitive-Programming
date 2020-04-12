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
ll partition(vector<bitset<30>> &a,ll st,ll end,ll ind,ll mask){
  if(ind==-1){
    return mask;
  }
  if(a[st][ind]==a[end][ind]){
    return partition(a,st,end,ind-1,mask);
  }else{
    ll e2=st;
    for(ll i=st;i<=end;i++){
      if(a[i][ind]!=a[st][ind]){
        e2=i;
        break;
      }
    }
    return min(partition(a,st,e2-1,ind-1,mask|1<<ind),partition(a,e2,end,ind-1,mask|1<<ind));
  }

}


int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
  ll n;
  cin>>n;
  vll b(n);
  fur(i,0,n){
    ll x;
    cin>>x;
    b[i]=x;
  }
  sort(b.begin(),b.end());
  vector<bitset<30>> c(n);
  fur(i,0,n)c[i]=b[i];
  ll ans=partition(c,0,n-1,30,0);
  cout<<ans;
	return 0;
}
