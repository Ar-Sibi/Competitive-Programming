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
	int n;
	cin>>n;
	vi ar = vi(n);
	
	for(int i=0;i<n;i++){
		cin>>ar[i];
	}
	sort(ar.begin(),ar.end());
	if(n%2==0){
	cout<<ar[(n-1)/2];
	}else{
		cout<<ar[(n)/2];

	}


	
	return 0;
}
