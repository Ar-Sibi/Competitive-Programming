#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
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
	ll n , k , A ,B;
	cin>>n>>k>>A>>B;
	
	if(k==1){
		ll cost = (n-1)*(A);
		cout<<cost;
		return 0;
	}
	ll cost=0;
	while(n!=1){
		int next = (n/k)*k;
		if(next==0){
			cost += (n-1)*A;
			n=1;
		}else{
			cost += (n - next)*A;
			n = next;
			ll nex = n/k;
			if((n-nex)*A>B){
				cost += B;
				n=nex;
			}else{
				cost+= (n-1)*A;
				n=1;
			}
			
		}
	}
	cout<<cost;
	
	return 0;
}
