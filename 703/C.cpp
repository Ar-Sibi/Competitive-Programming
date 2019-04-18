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

bool sorter(pll a,pll b){
    return a.Y<b.Y;
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
    ll n,w,v,u;
    cin>>n>>w>>v>>u;
    vpll bus(n);
    fur(i,0,n){
        ll x,y;
        cin>>x>>y;
        bus[i]={x,y};
    }
    bool cancross=true;
    fur(i,0,n){
        if(u*bus[i].X-v*bus[i].Y<0){
            cancross=false;
        }
    }
    pair<long double,long double> curr={0,0};
    long double time=0;
    if(cancross){
        // cout<<"WOT";
        long double ans=(w/(u*1.0f));
        cout<<setprecision(12)<<ans;
        return 0;
    }else{
        double d=1.0;
        long double dr=u*v;
        sort(bus.begin(),bus.end(),sorter);
        fur(i,0,n){
            if(bus[i].Y<=w){
            if(curr.X>bus[i].X){

            }else{
                if(u*(bus[i].X-curr.X)*1.0f-v*(bus[i].Y-curr.Y)>0){
                    time+=(bus[i].X-curr.X*d)*u;
                    curr=bus[i];
                }else{
                    time+=(bus[i].Y-curr.Y*d)*v;
                    curr.X+=((bus[i].Y-curr.Y)*v)/(u*1.0f);
                    curr.Y=bus[i].Y;
                }
                // cout<<curr.X<<"   "<<curr.Y<<"\n";
            }
            }
        }
        time+=((w-curr.Y*1.0f))*v;
    }
    cout<<setprecision(12)<<time/(u*v*1.0f);
	return 0;
}
