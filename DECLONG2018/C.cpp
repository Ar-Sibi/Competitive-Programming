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

vll out;
vector<vll> adj;
vll in;
class comparator
{
 public:
   bool operator()(ll a, ll b)
   {
       ll ca=0;
       ll cb=0;
        fur(i,0,adj[a].size()){
            cout<<in[adj[a][i]]<<endl;
            if(in[adj[a][i]]==1){
                ca++;
            }
        }
        fur(i,0,adj[b].size()){
            if(in[adj[b][i]]==1){
                cb++;
            }
        }
        cout<<ca<<" "<<cb<<endl;
        cout<<a<<" "<<b<<endl;
        cout<<endl;
        if(ca!=cb)
            return ca>cb;
        return out[a]<out[b];
   }
};


int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
    ll n,m;
    cin>>n>>m;
    adj=vector<vll>(n,vll(0));
    vector<vll> revadj(n,vll(0));
    in=vll(n);
    out=vll(n);
    fur(i,0,m){
        ll x,y;
        cin>>x>>y;
        x--;
        y--;
        adj[y].pb(x);
        revadj[x].pb(y);
        in[x]++;
        out[y]++;
    }
    cout<<out[2];
    priority_queue<ll,vll,comparator> q;
    // queue<ll> emptied;
    vector<vll> steps(0);

    fur(i,0,n){
        if(in[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        vll ans(0);
        while(ans.size()<2){
        if(q.size()>=1){
            ll val=q.top();q.pop();
            ans.pb(val);
        }else break;
        }
        for(int j=0;j<ans.size();j++){
        for(int i=0;i<adj[ans[j]].size();i++){
                in[adj[ans[j]][i]]--;
                if(in[adj[ans[j]][i]]==0){
                    q.push(adj[ans[j]][i]);
                }
            }
        }
        steps.pb(ans);
    }
    cout<<steps.size()<<"\n";
    fur(i,0,steps.size()){
        cout<<steps[i].size()<<" ";
        fur(j,0,steps[i].size()){
            cout<<steps[i][j]+1<<" ";
        }
        cout<<"\n";
    }

	return 0;
}
