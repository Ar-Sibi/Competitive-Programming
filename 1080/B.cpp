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
#define x first
#define y second

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
    ll l,r;
    ll q;
    cin>>q;
    while(q--){
    cin>>l>>r;
    
    ll odd=-((((r+1)/2)*((r+1)/2))-(((l)/2)*((l)/2)));
    ll o=r/2;
    ll x=(l-1)/2;
    // cout<<x*x+1;
    ll even=(o)*(o+1)-((x)*(x+1));
    // cout<<odd<<" "<<even;
	cout<<odd+even<<"\n";
    }
	return 0;
}
