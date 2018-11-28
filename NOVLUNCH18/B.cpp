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
    ll t;
    cin>>t;
    unordered_map <ll,ll> mapper;
    mapper[2]=1;
    fur(i,3,100000){
        ll val=i;
        for(int j=2;j<=sqrt(val);j++){
            if(val%j==0){
                mapper[i]++;
                while((val%j)==0){
                    val/=j;
                }
            }
        }
        if(val!=1){
            mapper[i]++;
        }
    }
    vector<vll> pr(100000,vll(0));
    fur(i,2,100001){
            ll val=i;
            if(val==2){
                pr[i].pb(2);
            }else
            for(ll j=1;j<=sqrt(val);j++){
                if(j*j==val){
                    pr[i].pb(j);
                }else{
                    if(val%j==0){
                        pr[i].pb(j);
                        pr[i].pb(val/j);
                    }
                }
            }
        }
    while(t--){
        ll n;
        cin>>n;
        vll a(n);
        fur(i,0,n){
            cin>>a[i];
        }
        ll max=0;
        unordered_map<ll,ll> m;
        fur(i,0,n){
            ll val=a[i];
            fur(j,0,pr[val].size()){
                m[pr[val][j]]++;
            }
        }
        fur(i,2,100001){
            // cout<<mapper[i]<<" "<<m[i]<<"\n";
            ll val1=mapper[i]*m[i];
            if(max<val1){
                max=val1;
            }
        }
        cout<<max<<"\n";
    }


	
	return 0;
}
