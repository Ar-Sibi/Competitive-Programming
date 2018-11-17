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

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	ll t;
	cin>>t;
	vpll ar=vpll(26,mp(0,0));
	ar[0]=mp(0,1);
	ar[1]=mp(1,2);
	ar[2]=mp(1,4);
	fur(i,3,26){
		ar[i].X=ar[i-1].X+ar[i-2].X*2;
		ar[i].Y=ar[i-1].Y*2;
	}
	while(t--){
		ll n;
		cin>>n;
		cout<<ar[n].X<<" "<<ar[n].Y<<" ";
	}


	
	return 0;
}
