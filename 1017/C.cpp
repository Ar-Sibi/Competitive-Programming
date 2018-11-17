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
	ll n;
	cin>>n;
	if(n==1)
	cout<<1;
	else if(n==2){
		cout<<"2 1";
	}else if(n==3){
		cout<<"3 1 2";
	}else {
		fur(i,0,n){
			if(i%2){
				cout<<n/2-i/2<<" ";
			}else{
				cout<<n-i/2<<" ";
			}
		}
	}


	
	return 0;
}
