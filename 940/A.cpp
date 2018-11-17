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

int min(int x, int y){ 
	return x>y?y:x;
	}

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	ll n,d;
	cin>>n;
	cin>>d;
	
	vi ar=vi(n);
	for(int i=0;i<n;i++)cin>>ar[i];
	sort(ar.begin(),ar.end());
	if(n==1){
		cout<<0;
		return 0;
	}
	vi arr= vi(n);
	for(int i=1;i<ar.size();i++){
		arr[i]=ar[i]-ar[i-1];
	}
	int curmin=0;
	int maxsize=0;
	int size=0;
	for(int i=1;i<arr.size();i++){
		size+=arr[i];
		while(size>d){
			size-=arr[curmin];
			curmin++;
		}
		if(maxsize<i-curmin){
			maxsize=i-curmin;
		}
	}
	cout<<arr.size()-(maxsize+1);
	return 0;
}
