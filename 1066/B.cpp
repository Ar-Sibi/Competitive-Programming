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
ll min(ll a,ll b){
	return a<b?a:b;
}
ll max(ll a,ll b){
	return a>b?a:b;
}


int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	ll n;
	cin>>n;
	vll a(n+1,0);
	fur(i,0,n)cin>>a[i+1];cout<<endl;
	vll b(0);
	fur(i,1,n+1){
		bool breakme=false;
		ll j;
		for( j=1;j<n+1;j++){
			if(j>=i+1){
				//cout<<i<<endl;
				
				
				if((a[j-(i)]-a[j-(i+1)])!=(a[j]-a[j-1])){

				break;
				}
			}
		}
		if(j==n+1){
			b.push_back(i);
		}
	}
	cout<<b.size()<<'\n';
	fur(i,0,b.size())cout<<b[i]<<" ";
	return 0;
}
