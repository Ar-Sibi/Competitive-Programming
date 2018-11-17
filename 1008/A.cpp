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
	unordered_map<char,int> s;
	s['a']=1;
	s['e']=1;
	s['i']=1;
	s['o']=1;
	s['u']=1;
	s['n']=2;
	string d;
	cin>>d;
	int ch=0;
	for(int i=0;i<d.length()-1;i++){
		if(s[d[i]]==0&&s[d[i+1]]!=1){
			cout<<"NO";
			return 0;
		}
	}
	if(s[d[d.length()-1]]==0){
		cout<<"NO";
		return 0;
	}
	cout<<"YES";
	return 0;
}
