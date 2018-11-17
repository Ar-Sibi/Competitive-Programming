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

int LessThanEqualOrLastBinSearch( int key, vll *data)
{
    ll len = (*data).size();
    int min = 0;
    int max = len-1;
    // var max = data.length - 1; // Javascript, Java conversion

    while( min <= max)
    {
        int mid = min + ((max - min) / 2);

        /**/ if ((*data)[mid] > key)  min  = mid + 1;
        else if ((*data)[mid] < key)  max  = mid - 1;
        else   /*(*data)[mid] = key)*/return mid    ;
    }

    if( max < 0 )
        return 0;     // key < (*data)[0]
    else
    if( min > (len-1))
        return len-1; // key >= (*data)[len-1]
    else
        return (min < max)
            ? min  
            : max + 1;
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
  vll a(n);
  vll u(n);
  unordered_map<ll,ll> s;
  ll size=0;
  bool val=false;
  for(ll i=0;i<a.size();i++){
    cin>>a[i];
    if(s[a[i]]==0){u[size]=a[i];size++;}
    else val=true;
    s[a[i]]++;
  }
  size++;
  if(!val){
    cout<<1;
    return 0;
  }
  for(ll i=0;i<size;i++){u[i]=s[u[i]];}
  sort(u.begin(),u.begin()+size-1);
  ll ind=-1;
  ll max=0;
  u[size]=INT_MAX;
  for(ll i=1;i<u[size-2]+1;i++){
    ll curr=0;
    ll x=i;
    auto it=lower_bound(u.begin(),u.begin()+size-1,x);
    ind=it-u.begin();
    ll count=20;
    while(((count--)>0)&&(x<u[size-2]+1)&&(ind<size-1)){
      curr+=x;
      x*=2;
      it=lower_bound(u.begin(),u.begin()+size-1,x);
      if(ind>=(it-u.begin())){
        ind=ind+1;
      }else{
        ind=it-u.begin();
      }
    }
    if(curr>max){

      max=curr;
    }
  }
  cout<<max;
	
	return 0;
}