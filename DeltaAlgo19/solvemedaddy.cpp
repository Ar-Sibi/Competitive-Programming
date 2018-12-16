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




int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
    vll primes(0);
    primes.pb(2);
    unordered_map<ll,ll> m;
    ll sum=2;
    m[2]=0;
    m[3]=2;
    fur(i,3,1000000){
        bool prime=true;
        for(int j=2;j<=sqrt(i);j++){
            if(i%j==0){
                prime=false;
                break;
            }
        }
        if(prime){
            primes.pb(i);
            sum+=i;
            m[i+1]=sum;
        }
    }
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        if(n<=2){
            cout<<0;
            continue;
        }
        while(m[n]==0){
            n--;
        }
        cout<<m[n]<<"\n";
    }
	return 0;
}
