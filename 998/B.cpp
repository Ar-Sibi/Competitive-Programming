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
	int p;
	cin>>p;
	vi x = vi(n);
	for(int i=0;i<n;i++){
		cin>>x[i];
	}
	int count =0;
	vi y = vi();
	for(int i=0;i<n-1;i++){
		count+= ((x[i]%2)==0)?1:-1;
		if(!count){
			y.pb(abs(x[i]-x[i+1]));
		}
	}
	if(count+(((x[x.size()-1]%2)==0)?1:-1)!=0){
		cout<< 0;
		return 0;
	}
	sort(y.begin(),y.end());
	
	int sum=0,ans=0;
	for(int i=0;i<y.size();i++){
		sum+=y[i];
		if(sum<=p){
			ans++;
		}else{
			cout<<ans;
			return 0;
		}
	}
	cout<<ans;
	
	return 0;
}
