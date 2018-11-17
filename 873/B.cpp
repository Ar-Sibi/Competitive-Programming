#include<bits/stdc++.h>
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
	long n,k,x;
	cin>>n;
	cin>>k;
	cin>>x;
	vi a = vi(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int y=0;
	int sum=0;
	revf(i,n,0){
		if(y<k){
			if(a[i]>x){
				sum+=x;
				y++;
			}else{
				sum+=a[i];
			}
		}else{
			sum+=a[i];
		}
	}
	cout<<sum;
	return 0;
}
