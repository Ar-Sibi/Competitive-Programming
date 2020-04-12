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
vll P(100002);
string convertToNewString(const string &s) {
    string newString = "";
    newString.append(s.size()*2+1,'@');

    for (int i = 0; i < s.size(); i++) {
        newString[i*2+1]='#';
        newString[i*2+2]=s[i];
    }

    newString += "#$";
    return newString;
}

string longestPalindromeSubstring(const string &s) {
    string Q = convertToNewString(s);
    ll c = 0, r = 0;                // current center, right limit

    for (ll i = 1; i < Q.size() - 1; i++) {
        // find the corresponding letter in the palidrome subString
        ll iMirror = c - (i - c);

        if(r > i) {
            P[i] = min<ll>(r - i, P[iMirror]);
        }

        // expanding around center i
        while (Q[i + 1 + P[i]] == Q[i - 1 - P[i]]){
            P[i]++;
        }

        // Update c,r in case if the palindrome centered at i expands past r,
        if (i + P[i] > r) {
            c = i;              // next center = i
            r = i + P[i];
        }
    }

    // Find the longest palindrome length in p.

    int maxPalindrome = 0;
    int centerIndex = 0;

    for (int i = 1; i < Q.size() - 1; i++) {
        if (((i-1-P[i])==0)&&(P[i] > maxPalindrome)) {
            maxPalindrome = P[i];
            centerIndex = i;
        }
    }

    return s.substr( (centerIndex - 1 - maxPalindrome) / 2, maxPalindrome);
}


string findLargestPalindromeStartingAt(string a,ll b){
  string s="";
  ll n=a.length();
  ll end=0;
  ll oddpos=-1;
  P=vll(6*a.length());
  // cout<<a.substr(b,a.length()-b)<<"\n\n\n";
  return longestPalindromeSubstring(a.substr(b,a.length()-2*b));
  // fur(i,b,n-b+1){
  //   bool f=false;
  //   fur(j,b,i){
  //     if(a[j]==a[(i-1)+(-j+b)]){

  //     }else{
  //       f=true;
  //     }
  //   }
  //   if(!f)
  //   end=i;
  // }
  // fur(i,b,end){
  //   s.append(1,a[i]);
  // }
  // cout<<"wtf   "<<s<<"\n";
  // return s;
}

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
  ll t;
  cin>>t;
  while(t--){
    string s;
    cin>>s;
    ll ma=0;
    ll mb=s.length()-1;
    fur(i,0,s.length()/2){
      if(s[ma]==s[mb]){
        ma++;
        mb--;
      }else{
        break;
      }
    }
    string ans=s.substr(0,ma)+findLargestPalindromeStartingAt(s,ma)+s.substr(s.length()-ma,ma);
    reverse(s.begin(),s.end());
    string ans2=s.substr(0,ma)+findLargestPalindromeStartingAt(s,ma)+s.substr(s.length()-ma,ma);
    if(ans.length()>ans2.length()){
      cout<<ans<<"\n";
    }else{
      cout<<ans2<<"\n";
    }
    // cout<<ans<<"\n";
    

  }



	return 0;
}
