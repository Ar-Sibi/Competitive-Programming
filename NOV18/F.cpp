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

ll max(ll a,ll b){
	return a>b?a:b;
}
ll min(ll a,ll b){
	return a<=b?a:b;
}
unordered_map<string,int> hr;

ll xGCD(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    ll x1, y1, gcd = xGCD(b, a % b, x1, y1);
    x = y1;
    y = x1 - (long long)(a / b) * y1;
    return gcd;
}

// factorial of n modulo mod
ll modfact(ll n) {
    ll result = 1;
    while (n > 1) {
        result = (long long)(result * n) % mod;
        n -= 1;
    }
    return result%mod;
}

// multiply a and b modulo mod
ll modmult(ll a, ll b) {
    return (a * b)% mod;
}

// inverse of a modulo MOD
ll inverse(ll a) {
    ll x, y;
    (a, mod, x, y);
    return (mod+x)%mod;
}

// binomial coefficient nCk modulo mod
ll bc(ll n, ll k)
{   
    // cout<<"weqweqweqw"<<inverse(modfact(k))<<endl;
    // cout<<modmult(modfact(n), inverse(modfact(k)))<<"wops"<<endl;
    return modmult(modmult(modfact(n), inverse(modfact(k))), inverse(modfact(n - k)));
}


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
ll gcdExtended(ll a, ll b, ll *x, ll *y) 
{ 
    // Base Case 
    if (a == 0) 
    { 
        *x = 0, *y = 1; 
        return b; 
    } 
  
    ll x1, y1; // To store results of recursive call 
    ll gcd = gcdExtended(b%a, a, &x1, &y1); 
  
    // Update x and y using results of recursive 
    // call 
    *x = y1 - (b/a) * x1; 
    *y = x1; 
  
    return gcd; 
} 

ll modInverse(ll a, ll m) 
{ 
    ll x, y; 
    ll g = gcdExtended(a, m, &x, &y); 
    if (g != 1) 
        return -1;
    else
    { 
        // m is added to handle negative x 
        ll res = (x%m + m) % m; 
        return res;
    } 
} 
  

 


ll nChoosek( ll n, ll k )
{
    if (k > n) return 0;
    if (k * 2 > n) k = n-k;
    if (k == 0) return 1;

    ll result = n;
    hr[to_string(n)+"C"+to_string(0)]=1;
    hr[to_string(n)+"C"+to_string(1)]=result;
    for( ll i = 2; i <= k; ++i ) {
        result =(result*(n-i+1))%mod;
        result =(result*modInverse(i,mod))%mod;
        hr[to_string(n)+"C"+to_string(i)]=result;
    }
    return result;
}


int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
    ll t;
    cin>>t;
    vector<vll> help(1001,vll(1002));
    fur(i,1,1001){
        ll h=1;
        help[i][0]=1;
        fur(j,0,i+1){
            h=(h*(i-j))%mod;
            h=(h*modInverse(j+1,mod))%mod;
            help[i][j+1]=h;
        }
    }
    while(t--){
        ll n;
        cin>>n;
        // n=500;
        vll ar(n);
        fur(i,0,n){
            cin>>ar[i];
        }
        // cout<<1<<endl;
        vll prec(n);
        ll sum=modpow(2,n-1,mod);
        ll j=n-2;
        ll h=1;
        if(n!=1)
        prec[0]=1;
        fur(k,0,n-2){
            h=(h*(j-k))%mod;
            h=(h*modInverse(k+1,mod))%mod;
            // cout<<n-2<<"C"<<k<<"="<<bc(n-2,k+1)<<endl;
            prec[k+1]=h;
            //cout<<prec[k+1]<<endl;bc(n-2,k+1);
        }
        // cout<<1<<endl;
        sort(ar.begin(),ar.end());
        ll nums=1;
        if(n>100){
        fur(i,0,n){
            fur(j,i+1,n){
                //ll j=i+k;
                if(ar[i]==ar[j]){
                    ll val=min(i,n-(j+1));
                    if(j-i==1){
                        // cout<<i<<" "<<j<<" "<<val<<" "<<prec[val]<<endl;
                        sum=(sum+prec[val])%mod;
                    }
                    else
                        sum=(sum+help[n-((j-i)+1)][val])%mod;
                }
            }
        }
        }else{
            fur(i,0,n-1){
            fur(j,i+1,n){
                if(ar[i]==ar[j]){
                    ll val=min(i,n-(j+1));
                    if(j-i==1){
                        // cout<<i<<" "<<j<<" "<<val<<" "<<prec[val]<<endl;
                        sum=(sum+prec[val])%mod;
                    }else{

                        // cout<<i<<" "<<j<<" "<<val<<" "<<nChoosek(n-((j-i)+1),val)%mod<<endl;
                        sum=(sum+nChoosek(n-((j-i)+1),val))%mod;
                    }
                }
            }
        }
        }
        // fur(i,1,n){
        //     if(ar[i]==ar[i-1]){
        //         nums++;
        //     }else{
        //         if(nums>=2){
        //             ll val=min(i-nums,n-(i));
        //         // cout<<"p"<<prec[val]<<endl;
        //         if(nums==2)
        //             sum=(sum+prec[val])%mod;
        //         else {
        //             sum=(sum+(((modpow(2,nums-1,mod)-1)*bc(n-nums,val)%mod)))%mod;
        //         }
        //         }
        //         nums=1;
        //     }
        // }
        // if(nums>=2){
        //     sum=sum+(modpow(2,nums-1,mod)-1)%mod;
        // }

        cout<<sum<<'\n';
    }
	return 0;
}