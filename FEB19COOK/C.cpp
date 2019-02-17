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
    ll t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        vpll a(n);
        vll pref(100000+1);
        fur(i,0,n){
            ll x,y;
            cin>>x>>y;
            x--;
            y--;
            a[i]={x,y};
            pref[x]+=1;
            pref[y+1]-=1;
        }
        vll val(100000);
        val[0]=pref[0];
        fur(i,1,100000){
            val[i]=pref[i]+val[i-1];
        }
        vll prefk(100000+1);
        vll prefk1(100000+1);
        // prefk[0]==val[0]==k?1:0;
        // prefk1[0]==val[0]==(k+1)?1:0;
        ll countk=0;
        // fur(i,0,10){
        //     cout<<val[i]<<" ";
        // }
        fur(i,1,100000+1){
            if(val[i-1]==k)countk++;
            if(val[i-1]==k){
                prefk[i]=1+prefk[i-1];
            }else prefk[i]=prefk[i-1];
            if(val[i-1]==k+1){
                prefk1[i]=1+prefk1[i-1];
            }else prefk1[i]=prefk1[i-1];
        }
        ll max=INT64_MIN;
        // cout<<endl<<countk<<endl;
        fur(i,0,n){
            ll  a1=prefk[a[i].Y+1]-prefk[a[i].X];
            ll  a2=prefk1[a[i].Y+1]-prefk1[a[i].X];
            // cout<<a1<<" "<<a2<<endl;
            if(countk-a1+a2>max){
                max=countk+a2-a1;
            }
        }
        cout<<max<<endl;
    }
	return 0;
}
