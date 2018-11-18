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


int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
  string s;
  cin>>s;
  while(s!="e"){
    if(s=="an"){
      ll size;
      cin>>size;
      cout<<size<<"\n";
      fur(i,0,size){
        cout<<rand()%1000<<" ";
      }
      cout<<"\n";
    }
    if(s=="as"){
      ll size;
      cin>>size;
      cout<<size<<"\n";
      vll ans(size,0);
      fur(i,0,size){
        ans[i]=(i+1)*10000;
      }
      random_shuffle(ans.begin(),ans.end());
      random_shuffle(ans.begin(),ans.end());
      fur(i,0,size){
        cout<<ans[i]<<" ";
      }
      cout<<"\n";
    }
    cin>>s;
  }
	return 0;
}
