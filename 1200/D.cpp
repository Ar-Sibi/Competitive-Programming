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
void transpose(vvll &b)
{
    if (b.size() == 0)
        return;

    vvll trans_vec(b[0].size(), vll());

    for (int i = 0; i < b.size(); i++)
    {
        for (int j = 0; j < b[i].size(); j++)
        {
            trans_vec[j].push_back(b[i][j]);
        }
    }

    b = trans_vec;    // <--- reassign here
}
void transpose(vector<string> &b)
{
    if (b.size() == 0)
        return;

    vector<string> trans_vec(b[0].length(), "");

    for (int i = 0; i < b.size(); i++)
    {
        for (int j = 0; j < b[i].size(); j++)
        {
            trans_vec[j].append(1,b[i][j]);
        }
    }

    b = trans_vec;    // <--- reassign here
}


int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
  ll n,k;
  cin>>n>>k;
  if(k>=n){
    cout<<n*2;
    return 0;
  }
  vector<string> s(n);
  fur(i,0,n)cin>>s[i];
  vector<ll> r(n),c(n);
  vvll idk(n,vll(0));
  vvll i2dk(n,vll(0));
  fur(i,0,n){
    fur(j,0,n){
      if(s[i][j]=='B'){idk[i].pb(j);i2dk[j].pb(i);c[i]++;r[j]++;}
      }
  }
  vvll dp(n,vll(n));
  vvll dpx(n,vll(n));
  ll cd=0;
  fur(i,0,n){
    if(idk[i].size()){
      fur(j,max<ll>(0,idk[i][idk[i].size()-1]-(k-1)),min(n,idk[i][0]+1)){
        dp[i][j]=1;
      }
    }else{
      cd++;
    }
  }
  // cout<<"dp1"<<"\n\n";
  // fur(i,0,n){
  //   fur(j,0,n){
  //     cout<<dp[i][j]<<" ";
  //   }
  //   cout<<"\n";
  // }
  // cout<<"\n\n\n\n";
  fur(i,0,n){
    ll mx=0;
    ll des=0;
    fur(lfe,0,k){
      des+=dp[lfe][i];
    }
    dpx[0][i]=des;
    fur(j,1,1+(n-k)){
      // cout<<i<<" "<<j<<"  xdsdsdsd"<<dp[i][j+k]<<"\n";
      des-=dp[j-1][i];
      des+=dp[j+k-1][i];
      dpx[j][i]=des;
    }
  }
  transpose(dpx);
  transpose(s);
  dp=vvll(n,vll(n,0));
  fur(i,0,n){
    if(i2dk[i].size()){
      fur(j,max<ll>(0,i2dk[i][i2dk[i].size()-1]-(k-1)),min(n,i2dk[i][0]+1)){
        dp[i][j]=1;
      }
    }else{
      cd++;
    }
  }
  // cout<<"dp1"<<"\n\n";
  // fur(i,0,n){
  //   fur(j,0,n){
  //     cout<<dp[i][j]<<" ";
  //   }
  //   cout<<"\n";
  // }
  // cout<<"\n\n\n\n";
  fur(i,0,n){
    ll mx=0;
    ll des=0;
    fur(lfe,0,k){
      des+=dp[lfe][i];
    }
    dpx[0][i]+=des;
    fur(j,1,1+(n-k)){
      // cout<<i<<" "<<j<<"  xdsdsdsd"<<dp[i][j+k]<<"\n";
      des-=dp[j-1][i];
      des+=dp[j+k-1][i];
      dpx[j][i]+=des;
    }
  }
  // cout<<"dpx1"<<"\n";
  // fur(i,0,n){
  //   fur(j,0,n){
  //     cout<<dpx[i][j]<<" ";
  //   }
  //   cout<<"\n";
  // }
  // cout<<"\n\n\ndp21\n";
  
  // dp=vvll(n,vll(n));
  // fur(i,0,n){
  //   if(i2dk[i].size()){
  //     fur(j,max<ll>(0,i2dk[i][i2dk[i].size()-1]-(k-1)),min(n,i2dk[i][0]+1)){
  //       dp[j][i]=1;
  //     }
  //   }else{
  //     cd++;
  //   }
  // }
  // // fur(i,0,n){
  // //   fur(j,0,n){
  // //     cout<<dp[i][j]<<" ";
  // //   }
  // //   cout<<"\n";
  // // }
  // // cout<<"\n\n\n\n";
  // fur(i,0,n){
  //   ll mx=0;
  //   ll des=0;
  //   fur(lfe,0,k){
  //     des+=dp[i][lfe];
  //   }
  //   dpx[0][i]+=des;
  //   fur(j,1,1+n-k){
  //     des-=dp[i][j-1];
  //     des+=dp[i][j+k-1];
  //     dpx[i][j]+=des;
  //   }
  // }
  ll maxd=0;
  fur(i,0,n){
    fur(j,0,n){
      maxd=max(maxd,dpx[i][j]);
      // cout<<dpx[i][j]<<" ";
    }
    // cout<<"\n";
  }
  cout<<maxd+cd;

	return 0;
}
