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
	while(t--){
	unordered_map<int,int> s;
	ll n;
	cin>>n;
	vll ar(n+1);
	fur(i,1,n+1)cin>>ar[i];
	bool found=false;
	fur(i,1,n+1){
		if(!s[ar[ar[i]]])
			s[ar[ar[i]]]=ar[i];
		else{
			if(s[ar[ar[i]]]!=ar[i]){
				found=true;
			}
		}
	}
	if(found){
		cout<<"Truly Happy\n";
	}else{
		cout<<"Poor Chef\n";
	}
	}
	return 0;
}
