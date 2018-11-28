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

ll sorter(pll a,pll b){
    return a.Y>b.Y;
}

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
    ll n,m;
    cin>>n>>m;
    vpll powers(2*n);
    unordered_map<ll,ll> pairs;
    unordered_map<ll,ll> p;
    vll visited(2*n+1);
    vpll pair(m);
    fur(i,0,2*n){
        ll x;
        cin>>x;
        p[i+1]=x;
        powers[i]=mp(i+1,x);
    }
    fur(i,0,m){
        ll x,y;
        cin>>x>>y;
        pair[i]=mp(x,y);
        pairs[x]=y;
        pairs[y]=x;
    }
    ll t;
    sort(powers.begin(),powers.end(),sorter);
    cin>>t;
    if(t==1){
        ll c=0;
        fur(i,0,m){
            if(p[pair[i].X]>p[pair[i].Y]){
                cout<<pair[i].X<<endl;
                cout.flush();
                c++;
            if(c==2*n)
            return 0;
                visited[pair[i].X]=1;
            }else{
                cout<<pair[i].Y<<endl;
                cout.flush();
                c++;
            if(c==2*n)
            return 0;
                visited[pair[i].Y]=1;
            }
            ll x;
            cin>>x;
            c++;
            if(c==2*n)
            return 0;
            visited[x]=1;
        }
        fur(i,0,2*n){
            if(!visited[powers[i].X]){
                visited[powers[i].X]=1;
                cout<<powers[i].X<<endl;
                cout.flush();
                c++;
            if(c==2*n)
            return 0;
                ll x;
                cin>>x;
                c++;
            if(c==2*n)
            return 0;
                visited[x]=1;
            }
        }
    }else{
        ll c=0;
        ll x;
        cin>>x;
        visited[x]=1;
        c++;
        while(pairs[x]){
            cout<<pairs[x]<<endl ;
           cout.flush();
            c++;
            if(c==2*n){
                return 0;
            }
            visited[x]=1;
            visited[pairs[x]]=1;
            cin>>x;
            visited[x]=1;
            c++;
            if(c==2*n)
            return 0;
        }
        fur(i,0,m){
            if(!visited[pair[i].X]&&!visited[pair[i].Y]){
            if(p[pair[i].X]>p[pair[i].Y]){
                cout<<pair[i].X<<endl;
                cout.flush();
                c++;
            if(c==2*n)
            return 0;
                visited[pair[i].X]=1;
            }else{
                cout<<pair[i].Y<<endl;
                cout.flush();
                c++;
            if(c==2*n)
            return 0;
                visited[pair[i].Y]=1;
            }
            ll x;
            cin>>x;
            c++;
            if(c==2*n)
            return 0;
            visited[x]=1;
            }
        }
        fur(i,0,2*n){
            if(!visited[powers[i].X]){
                cout<<powers[i].X<<endl;
                cout.flush();
                c++;
            if(c==2*n)
            return 0;
                visited[powers[i].X]=1;
                ll x;
                cin>>x;
                c++;
            if(c==2*n)
            return 0;
                visited[x]=1;
            }
        }
    }

	
	return 0;
}
