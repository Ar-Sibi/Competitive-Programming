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
	ll n,k;
	cin>>n>>k;
	vi s(n);
	fur(i,0,n)cin>>s[i];
	vi q(n);
	fur(i,0,n)q[i]=s[i];
	sort(q.begin(),q.end());
	int maxval=q[(n-1)-(k-1)];
	int count =0;
	ll sum=0;
	for(int i=(n-1)-(k-1);i<q.size();i++){
		if(maxval==q[i])count++;
		sum+=q[i];
	}
	vector<int> ans(n);
	for(int i=0;i<q.size();i++){
		if(s[i]>maxval){
			ans[i]=1;
		}else{
			if(s[i]==maxval){
				if(count){
					count--;
					ans[i]=1;
				}
			}
		}
	}
	int val=0;
	int ones=0;
	cout<<sum<<'\n';
	for(int i=0;i<ans.size();i++){
		if(ans[i]==1){
			ones++;
		}
		if(ones==2){
			cout<<val<<" ";
			ones--;
			val=0;
		}
		val++;
	}
	cout<<val<<endl;;
	return 0;
}
