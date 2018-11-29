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
    vll maximum(n);
    ll val=0;
    ll gr2=0;
    stack<ll> ones;
    vpll twoes(0);
    fur(i,0,n){
        cin>>maximum[i];
        val+=maximum[i];
        if(maximum[i]>=2){
            gr2++;
            twoes.pb(mp(i,maximum[i]));
        }else{
            ones.push(i);
        }
    }
    if(val<=(2*n-3)){
        cout<<"NO";
        return 0;
    }
    if(gr2==1){
        cout<<"YES 2\n";
        cout<<n-1<<"\n";
        vpll edges(0);
        while(ones.size()!=0){
            ll i=0;
                if(twoes[i].Y>=1){
                    ll x=ones.top();ones.pop();
                    ll y=twoes[i].X;
                    edges.pb(mp(x,y));
                    twoes[i].Y--;
                }
            
        }
        fur(i,0,edges.size()){
            cout<<edges[i].X+1<<" "<<edges[i].Y+1<<"\n";
        }
    }else{
        vpll edges(0);
        ll max=0;
        if(!ones.empty()){
            ll x=ones.top();ones.pop();
            ll y=twoes[0].X;
            edges.pb(mp(x,y));
            max++;
        }
        if(!ones.empty()){
            ll x=ones.top();ones.pop();
            ll y=twoes[twoes.size()-1].X;
            edges.pb(mp(x,y));
            max++;
        }
        while(!ones.empty()){
            fur(i,0,twoes.size()){
                if(!ones.empty()){
                if(twoes[i].Y>2){
                    
                    ll x=ones.top();ones.pop();
                    ll y=twoes[i].X;
                    edges.pb(mp(x,y));
                    twoes[i].Y--;
                    
                }
                }
            }
        }
        fur(i,0,twoes.size()-1){
            ll x=twoes[i].X;
            ll y=twoes[i+1].X;
            edges.pb(mp(x,y));
        }
        max+=twoes.size()-1;
        cout<<"YES "<<max<<"\n";
        cout<<n-1<<"\n";
        fur(i,0,edges.size()){
            cout<<edges[i].X+1<<" "<<edges[i].Y+1<<"\n";
        }
    }



	return 0;
}
