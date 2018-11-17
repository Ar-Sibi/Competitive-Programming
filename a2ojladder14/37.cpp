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
bool sorter(pll a, pll b){
  return a.X>b.X;
}

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
  ll t;
  cin>>t;
  vpll ar(t,mp(0,0));
  vector<int **> a(1001,nullptr);
  vector<int ***> b(1001,nullptr);
  vector<int *> v(t);
  fur(i,1,t+1){
    v[i-1]=new int();
    *v[i-1]=i;
  }
  ll mult=0;
  fur(i,0,t){
    ll x,y;
    cin>>x>>y;
    ar[i].X=x;
    ar[i].Y=y;
  }
  sort(ar.begin(),ar.end());
  fur(i,0,t){
    ll x=ar[i].X;
    ll y=ar[i].Y;
    if(a[x]||b[y]){
      if(a[x]&&b[y]){
        if(**a[x]!=***b[y]){
        ***b[y]=**a[x];
        **b[y]=*a[x];
        *b[y]=a[x];
        v[i]=*a[x];
        }
      }
      else if(a[x]){
        v[i]=*a[x];
        a[x]=&v[i];
        b[y]=&a[x];
      }else{
        *v[i]=***b[y];
        a[x]=*b[y];
      }
    }else{
      a[x]=&v[i];
      b[y]=&a[x];
    }
  }
  ll ans=0;
  unordered_map<string,ll> d;
  ll xnoty=0;
  vll ri(t,0);
  fur(i,0,t){
    ri[i]=i+1;
  }
  do{
    xnoty=0;
    fur(i,0,t){
      if(ri[**a[ar[i].X]]!=ri[***b[ar[i].Y]]){
        xnoty++;
        if(ri[**a[ar[i].X]]<ri[***b[ar[i].Y]]){
          ri[***b[ar[i].Y]]=ri[**a[ar[i].X]];
        }else{
          ri[**a[ar[i].X]]=ri[***b[ar[i].Y]];
        }
      }
    }
    // cout<<xnoty<<endl;
  }while(xnoty!=0);
  fur(i,0,t){
    //  cout<<to_string(**a[ar[i].X])+"M"+to_string(***b[ar[i].Y])<<endl;
    //  cout<<min(**a[ar[i].X],***b[ar[i].Y])<<endl;
    if(!d[to_string(min(ri[**a[ar[i].X]],ri[***b[ar[i].Y]]))]){
      // cout<<min(**a[ar[i].X],***b[ar[i].Y])<<endl;
      ans++;
    }
    d[to_string(min(ri[**a[ar[i].X]],ri[***b[ar[i].Y]]))]=1;
  }
  cout<<ans-1;
	return 0;
}
