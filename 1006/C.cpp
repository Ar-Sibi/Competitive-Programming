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
	ll n;
	cin>>n;
	vi ar(n);
	fur(i,0,n)cin>>ar[i];
	ll ans=0;
	ll left=0;
	ll right=n-1;
	ll lsum=ar[0];
	ll rsum=ar[right];
	while(left<right){
		if(lsum<rsum){
			left++;
			if(left==right)
				break;
			lsum+=ar[left];
		}else if(rsum<lsum){
			right--;
			if(left==right)
				break;
			rsum+=ar[right];
		}
		if(lsum==rsum){
			ans=lsum;
			left++;
			if(left==right)
			break;
			lsum+=ar[left];
		}
	}
	cout<<ans;
	return 0;
}
