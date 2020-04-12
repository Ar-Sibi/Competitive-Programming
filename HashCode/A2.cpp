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
  ll b,l,d;
  cin>>b>>l>>d;
  vll bs(b);
  fur(i,0,b)cin>>bs[i];
  vvll lsindex(l,vll(0));
  vvll libextd(l,{0,0,0,0,0});
  fur(i,0,l)libextd[i][3]=i;
  fur(i,0,l){
    ll sz,signupdays,booksperday;
    cin>>sz>>signupdays>>booksperday;
    libextd[i][0]=signupdays;
    libextd[i][1]=booksperday;
    libextd[i][2]=sz;
    libextd[i][3]=i;
    lsindex[i]=vll(sz);
    vvll f(sz,{0,0,0});
    fur(j,0,sz){
      cin>>f[j][1];
      f[j][0]=bs[f[j][1]];
    }
    sort(f.begin(),f.end());
    reverse(f.begin(),f.end());
    fur(j,0,sz){
      lsindex[i][j]=f[j][1];
    }
  }
  // fur(i,0,lsindex.size()){
  //   fur(j,0,lsindex[i].size()){
  //     cout<<lsindex[i][j]<<" ";
  //   }
  //   cout<<"\n";
  // }
  sort(libextd.begin(),libextd.end());
  vvll answer(l);
  unordered_map<ll,ll> visited;
  ll libinwait=0;
  ll libonboard=-2;
  vll bookp(l);
  fur(i,0,d){
    if(libinwait==0&&(libonboard<l)){
      libonboard++;
      if(libonboard<l-1)
      libinwait=libextd[libonboard+1][0];
    }
    // cout<<libinwait<<" "<<libonboard<<"x\n";
    fur(j,0,libonboard+1){

      ll c=libextd[j][1];
      // cout<<c<<"yyy";
      // cout<<libextd[j][2];
      while(c&&(bookp[j]<libextd[j][2])){
        if(!visited[lsindex[libextd[j][3]][bookp[j]]]){
          answer[j].pb(lsindex[libextd[j][3]][bookp[j]]);
          visited[lsindex[libextd[j][3]][bookp[j]]]=1;
          c--;
          // cout<<c<<"sadasdasd\n\n\n\n\n"<<lsindex[libextd[j][3]][bookp[j]]<<"\n\n\n";
        }
        bookp[j]++;
        // cout<<bookp[j]<<"yyy\n";
      }
    }
    libinwait--;
  }
  ll skip=0;
  fur(i,0,libonboard+1){
    if(answer[i].size()==0)skip++;
  }
  cout<<libonboard+1-skip<<"\n";
  
  fur(i,0,libonboard+1){
    if(answer[i].size()!=0){
      cout<<libextd[i][3]<<" "<<answer[i].size()<<"\n";
      fur(j,0,answer[i].size()){
        cout<<answer[i][j]<<" ";
      }
      cout<<"\n";
    }
  }
  return 0;
}
