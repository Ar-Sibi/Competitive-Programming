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

ll max(ll a,ll b){
    return a>b?a:b;
}
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
vll visited;
int calculateColors(vector<vll> *adj,vll *colors,ll index){
    visited[index]=1;
    ll colorVal=0;
    if((*adj)[index].size()==1&&index!=0)colorVal=1;
    else;
    for(ll i=0;i<(*adj)[index].size();i++){
        if(!visited[(*adj)[index][i]]){
            colorVal+=calculateColors(adj,colors,(*adj)[index][i]);
        }
    }
    (*colors)[index]=colorVal;
    return colorVal;
}

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
    ll n;
    cin>>n;
    vector<vll> adj(n,vll());
    visited=vll(n);
    vll colors(n);
    fur(i,0,n-1){
        ll x,y;
        cin>>x;
        x--;
        adj[i+1].pb(x);
        adj[x].pb(i+1);
    }
    calculateColors(&adj,&colors,0);
    sort(colors.begin(),colors.end());
    fur(i,0,n){
        cout<<max(colors[i],1)<<" ";
    }
	return 0;
}
