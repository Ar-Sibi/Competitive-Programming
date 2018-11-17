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
	string s;
	int n;
	cin>>n;
	cin>>s;
	ll max=0;
	fur(i,0,s.length()){
		ll subsum=0;
		ll count=0;
		fur(j,i,s.length()){
			if(s[j]=='0')
				count++;
			else 
				count--;
			if(count==0){
				if(max<j-i)	max=j-i+1;
			}
		}
	}
	cout<<max;
	return 0;
}
