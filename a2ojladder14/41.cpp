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
ll M,N;
ll twod(ll x,ll y){
    return x*M+y;
}

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
    ll n,m;
    cin>>n>>m;
    N=n;
    M=m;
    vector<string> s(n);
    vector<vll> visited(n,vll(m,0));
    vector<vll> parent(n,vll(m,-1));
    fur(i,0,n)cin>>s[i];
    fur(i,0,n){
        fur(j,0,m){
            char x=s[i][j];
            // cout<<i<<"s"<<j<<endl;
            if(!visited[i][j]){
                queue<pll> q;
                q.push(mp(i,j));
                while(!q.empty()){
                    pll v=q.front();q.pop();
                    // cout<<v.X<<" "<<v.Y<<s[v.X][v.Y]<<endl;
                    visited[i][j]=true;
                    if(v.X>0){
                        if(s[v.X-1][v.Y]==x){
                            if(visited[v.X-1][v.Y]&&parent[v.X][v.Y]!=twod(v.X-1,v.Y)){
                                cout<<"Yes";
                                return 0;
                            }else{
                                if(!visited[v.X-1][v.Y]){
                                    parent[v.X-1][v.Y]=twod(v.X,v.Y);
                                    q.push(mp(v.X-1,v.Y));
                                    visited[v.X-1][v.Y]=true;
                                }
                            }
                        }
                    }
                    if(v.X<N-1){
                        if(s[v.X+1][v.Y]==x){
                            if(visited[v.X+1][v.Y]&&parent[v.X][v.Y]!=twod(v.X+1,v.Y)){
                                cout<<"Yes";
                                return 0;
                            }else{
                                if(!visited[v.X+1][v.Y]){
                                    parent[v.X+1][v.Y]=twod(v.X,v.Y);
                                    q.push(mp(v.X+1,v.Y));
                                    visited[v.X+1][v.Y]=true;
                                }
                            }
                        }
                    }
                    if(v.Y>0){
                        if(s[v.X][v.Y-1]==x){
                            if(visited[v.X][v.Y-1]&&parent[v.X][v.Y]!=twod(v.X,v.Y-1)){
                                cout<<"Yes";
                                return 0;
                            }else{
                                if(!visited[v.X][v.Y-1]){
                                    parent[v.X][v.Y-1]=twod(v.X,v.Y);
                                    q.push(mp(v.X,v.Y-1));
                                    visited[v.X][v.Y-1]=true;
                                }
                            }
                        }
                    }
                    if(v.Y<M-1){
                        if(s[v.X][v.Y+1]==x){
                            if(visited[v.X][v.Y+1]&&parent[v.X][v.Y]!=twod(v.X,v.Y+1)){
                                cout<<"Yes";
                                return 0;
                            }else{
                                if(!visited[v.X][v.Y+1]){
                                    parent[v.X][v.Y+1]=twod(v.X,v.Y);
                                    q.push(mp(v.X,v.Y+1));
                                    visited[v.X][v.Y+1]=true;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
	cout<<"No";
	return 0;
}
