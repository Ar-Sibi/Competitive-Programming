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
#define mod 998244353 
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
vvll adj;
vll a;
vll visited;
vll colors;
ll odd=0;
ll even=0;
set<ll> sets;
bool eh;
void dfs(ll ind){
    sets.insert(ind);
    fur(i,0,adj[ind].size()){
        if(!visited[adj[ind][i]]){
            colors[adj[ind][i]]=!colors[ind];
            visited[adj[ind][i]]=1;
            dfs(adj[ind][i]);
        }else{
            if(colors[ind]==colors[adj[ind][i]]){
                eh=true;
            }
        }
    }
}


int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
    ll t;
    cin>>t;
    while(t--){
        ll n,m;
        cin>>n>>m;
        a=vll(n);
        visited=vll(n);
        colors=vll(n);
        adj=vvll(n,vll(0));
        eh=false;
        odd=0;
        even=0;
        
        fur(i,0,m){
            ll x,y;
            cin>>x>>y;
            x--;
            y--;
            adj[x].pb(y);
            adj[y].pb(x);
        }
        odd=1;
        fur(i,0,n){
            if(!visited[i]){
                sets.clear();
                dfs(i);
                ll curo=1;
                ll cure=1;
                if(sets.size()==1){
                    odd=(odd*3)%mod;
                }else{
                for(auto f : sets) {
                    if(colors[f]){
                        curo=((curo)*2)%mod;
                        cure=((cure)*1)%mod;
                    }else{
                        curo=((curo)*1)%mod;
                        cure=((cure)*2)%mod;
                    }
                }
                odd=(((curo+cure)%mod)*odd)%mod;  
                }
            }
        }
        if(eh){
            cout<<0<<"\n";
        }else{
            cout<<((odd)%mod)<<"\n";
        }
        
    }



	return 0;
}
