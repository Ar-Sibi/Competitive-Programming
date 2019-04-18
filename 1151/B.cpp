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
    ll n,m;
    cin>>n>>m;
    vvll a(n,vll(m));
    ll ans=0;
    vll an(n,0);
    fur(i,0,n){
        ll c=-1;
        bool yes=true;
        fur(j,0,m){
            cin>>a[i][j];
            if(c==-1)c=a[i][j];
            else if(a[i][j]!=c){
                yes=false;
            }
        }
        if(yes==false){
               an[i]=1;
               ans^=c;
        }
    }
    vll iters(n);
    vector<vpll> distinct(n,vpll(0));
    fur(i,0,n){
        unordered_map<ll,ll> t;
        t.clear();
        fur(j,0,m){
            if(!t[a[i][j]]){
                t[a[i][j]]=1;
                distinct[i].pb({a[i][j],j});
            }
        }
        iters[i]=distinct[i].size()-1;
    }
    while(true){
        ll ans=0;
        fur(i,0,n){
            ans^=distinct[i][iters[i]].X;

        }
        if(ans!=0){
            cout<<"TAK\n";
            fur(i,0,n){
                cout<<distinct[i][iters[i]].Y+1<<" ";
            }
            return 0;
        }else{
            bool yes=true;
            revf(i,n,0){
                if(iters[i]){
                    iters[i]--;
                    yes=false;
                    break;
                }
            }
            if(yes){
                cout<<"NIE";
                return 0;
            }
        }
    }



	return 0;
}
