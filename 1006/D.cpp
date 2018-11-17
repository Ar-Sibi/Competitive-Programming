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
	string a,b;
	ll n ;
	cin>>n;
	cin>>a;
	cin>>b;
	
	ll ans=0;
	fur(i,0,n/2){
		vector<char> sol(4);
		sol[0]=a[i];
		sol[1]=b[i];
		sol[2]=a[(n-1)-i];
		sol[3]=b[(n-1)-i];
		sort(sol.begin(),sol.end());
		vector<int> freq(4);
		for(int k=0;k<4;k++){
			for(int j=0;j<4;j++){
				if(sol[k]==sol[j])
				freq[k]++;
			}
		}
		vector<int> sh(4);
		for(int l=0;l<4;l++)
			sh[l]=freq[l];
		sort(sh.begin(),sh.end());
		
		if(sh[0]==sh[3]){
			if(sh[0]==1){
				ans+=2;
			}
		}else{
			if(sh[3]==3)
			ans+=1;
			else if(sh[0]==1)
			ans+=2;
		}
	}

	if(n%2==1){
		if(a[n/2]!=b[n/2])
		ans+=1;
	}
	cout<<ans;
	return 0;
}
