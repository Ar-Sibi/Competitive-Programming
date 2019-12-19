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
  vvll a(n,vll(0));
  vvll b(n,vll(n));
  fur(i,0,n){
    string s;
    cin>>s;
    fur(j,0,n){
      if(s[j]=='1'){
        b[i][j]=1;
        a[i].push_back(j);
      }
    }
  }
  ll sn;
  cin>>sn;
  vll p(sn);
  fur(i,0,sn){
    cin>>p[i];
    p[i]--;
  }
  // vpll dp(sn);
  // // vpll dp2(n,{-1,-1});
  // vpll jumps(sn,{INT_MAX,-1});
  // ll skip=-1;
  // fur(i,0,sn){
  //   if(i<skip)continue;
  //   unordered_map<ll,ll> m;
  //   m[p[i]]=1;
  //   // fur(lo,0,a[p[i]].size()){

  //   // }
  //   fur(j,i+2,sn){
  //     if(m[p[j]])break;
  //     m[p[j]]=1;
  //     if()
  //   }
  // }
  // jumps[sn-1]={0,-1};
  vll ans(0);
  ans.pb(sn-1);
  revf(i,sn,0){
    // cout<<i<<"  \n";
    revf(j,i-1,0){
      if(p[i]==p[j]){
        ans.pb(j+1);
        if(!j)
        ans.pb(j);
        i=j+1;
        break;
      }
      // cout<<p[j]<<"  "<<p[i]<<"asdasd \n";
      if(b[p[j]][p[i]]){
        // cout<<i<<"asdasdas"<<j<<"\n";
        ans.pb(j+1);
        cout<<j+1<<"\n";
        i=j+2;
      }else{
        // break;
      }
    }
  }
  ans.pb(0);
  reverse(ans.begin(),ans.end());
  cout<<ans.size()<<"\n";
  fur(i,0,ans.size()){
    cout<<p[ans[i]]+1<<" ";
  }
  // dp2[p[sn-1]]={0,sn};
  // revf(i,sn-1,0){
  //   fur(j,0,a[i].size()){
  //     cout<<a[i][j]<<"\n";
  //     if(!(dp2[a[i][j]].Y==-1)){
        
  //       if(dp[i].Y==-1){
  //         dp[i]={1+dp2[a[i][j]].X,dp2[a[i][j]].Y};
  //       }else{
  //         if(dp[i].X+1<dp[i].X){
  //           dp[i]={1+dp2[a[i][j]].X,dp2[a[i][j]].Y};
  //         }
  //       }
  //     }
  //     if(dp2[p[i]].Y==-1){
  //      dp2[p[i]]=dp[i]; 
  //     }else if(dp2[p[i]].X<dp[i].X){
  //       dp2[p[i]]=dp[i];
  //     }
  //   }
  // }
  // cout<<dp[0].X;
  // unordered_map<ll,ll> m;
  // vpll dd(n,{INT_MAX,INT_MIN});
  // fur(i,0,sn){
  //   cin>>p[i];
  //   if(i<dd[p[i]].X){
  //     dd[p[i]].X=i;
  //   }
  //   if(i>dd[p[i]].Y){
  //     dd[p[i]].Y=i;
  //   }
  // }




	return 0;
}
