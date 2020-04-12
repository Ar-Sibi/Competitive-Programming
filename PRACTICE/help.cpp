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
ll nChoosek( ll n, ll k )
{
    if (k > n) return 0;
    if (k * 2 > n) k = n-k;
    if (k == 0) return 1;
    ll result = n;
    for( ll i = 2; i <= k; ++i ) {
        result =(result*(n-i+1))%mod;
        result =(result*modinv(i,mod))%mod;
    }
    return result;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    ll n,k;
    cin>>n>>k;
    vll a(n);
    fur(i,0,n)cin>>a[i];
    sort(a.begin(),a.end());
    vpll mm(n,{INT_MIN,INT_MAX});
    fur(tt,1,n){
        mm[tt].X=((a[tt]==a[tt-1])?mm[tt-1].X:(tt-1));
    }
    revf(tt,n-1,0){
        mm[tt].Y=(a[tt]==a[tt+1])?mm[tt+1].Y:tt+1;
    }
    
    fur(i,0,n)a[i]=a[i]%mod;
    vll b(n,1);
    ll startingSign=(k%2==0)?1:-1;
    startingSign=(mod+startingSign)%mod;
    ll ans=0;
    fur(i,0,k+1){
        ll sub=nChoosek(k,i);
        vll c(n+1,0);
        if(i!=0)
        fur(j,0,n){
            b[j]=(b[j]*a[j])%mod;
        }
        fur(j,1,n+1){
            c[j]=(c[j-1]+b[j-1])%mod;
        }
        // cout<<"\n";
        ll sum=0;
        fur(j,0,n){
            if(mm[j].X!=INT_MIN){
                if(k%2==0){
                    // cout<<k-i<<" "<<"d"<<j<<" "<<a[j]<<" "<<c[mm[j].X+1]<<" "<<((c[mm[j].X+1]*modpow(a[j],(k-i),mod))%mod)<<"debug\n";
                    sum=((sum+((c[mm[j].X+1]*modpow(a[j],(k-i),mod))%mod)))%mod;
                }else{
                    sum=((sum-((c[mm[j].X+1]*modpow(a[j],(k-i),mod))%mod)))%mod;
                }
            }
            // cout<<"int"<<sum<<"\n";
            
            sum=(sum%mod);
            sum=(sum+mod)%mod;
        }
        fur(j,0,n){
            if(mm[j].Y!=INT_MAX){
                // cout<<"FFF"<<i<<" "<<j<<" "<<c[n]-c[mm[j].Y]<<"y"<<(((c[n]-c[mm[j].Y])*modpow(a[j],(k-i),mod))%mod)<<"x"<<"\n";
                sum=((sum+(((c[n]-c[mm[j].Y])*modpow(a[j],(k-i),mod))%mod)))%mod;
            }
            // cout<<"int"<<sum<<"\n";
            
            sum=(sum%mod);
            sum=(sum+mod)%mod;
        }
        // cout<<"FINALSUM"<<sum<<"\n";
        // cout<<sub<<"\n";
        sum=(sum*sub)%mod;
        ans=(ans+sum*startingSign)%mod;
        // cout<<"s"<<sum<<"\n\n";
        ans=(ans+mod)%mod;
        sum=0;
        startingSign*=-1;
    }
    cout<<(ans)%mod;

    return 0;
}
