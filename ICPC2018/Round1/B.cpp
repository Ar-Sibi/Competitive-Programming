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

long long max(ll a,ll b){
	return a>b?a:b;
}

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	ll t;
	cin>>t;
	while(t--){
		ll n,k;
		cin>>n;
		cin>>k;
		vll arr(n);
		vll arx(n);
		fur(i,0,n){
			cin>>arr[i];
		}
		if(n==1){
			cout<<arr[0];
			continue;
		}
		sort(arr.begin(),arr.end());
		fur(i,0,n)arx[n]=max(0,arr[i]-k);
		ll last=0;
		ll residue=0;
		ll sum1=0;
		fur(i,0,n){
			sum1+=arx[i];
		}
		if(arx[n-2]>sum1/2){
			last=2*arx-sum1;
		}
		ll sum=0;
		fur(i,0,n){
			sum+=arr[i];
		}
		cout<<sum<<"\n";
	}


	
	return 0;
}
