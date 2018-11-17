#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vll;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;
typedef pair<ll,pll> tll;
typedef vector<tll> vtll;
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

bool sort12(tll a,tll b){
  return a.Y.X<b.Y.X;
}
bool sort13(tll a,tll b){
  return a.Y.Y<b.Y.Y;
}
bool sortY(pll a,pll b){
  return a.Y<b.Y;
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


int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
  ll n;
  cin>>n;
  vtll a(n);
  fur(i,0,n){
    ll x,y;
    cin>>x>>y;
    a[i]=mp(i,mp(x,y));
  }
  sort(a.begin(),a.end(),sort12);
  ll k;
  cin>>k;
  vpll seat(k);
  fur(i,0,k){
    ll x;
    cin>>x;
    seat[i]=mp(i,x);
  }
  sort(seat.begin(),seat.end(),sortY);
  ll lastind=0;
  ll ans=0;
  ll num=0;
  vpll ans1(0);
  fur(i,0,seat.size()){
    if(a[lastind].Y.X>seat[i].Y){
      continue;
    }
    fur(j,lastind+1,n){
    {
        // cout<<a[j].Y.X<<"  "<<seat[i].Y<<endl;
        if(a[j].Y.X>seat[i].Y){
        lastind=j-1;
        break;
        }
        if(j==n-1){
        lastind=n-1;
        }
      }
    }
    sort(a.begin(),a.begin()+lastind+1,sort13);
    // fur(p,0,a.size()){
      // cout<<a[p].Y.Y<<" ";
    // }
    // cout<<"\n"<<lastind<<"\n";
    if(a[lastind].Y.Y!=-1){
      num++;
      ans+=a[lastind].Y.Y;
      a[lastind].Y.Y=-1;
      ans1.pb(mp(a[lastind].X,seat[i].X));
    }
  }
  cout<<ans1.size()<<" "<<ans<<"\n";
	fur(i,0,ans1.size()){
    cout<<ans1[i].X+1<<" "<<ans1[i].Y+1<<"\n";
  }
	return 0;
}
