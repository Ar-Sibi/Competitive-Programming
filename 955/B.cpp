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
	vector<int> d(26);
	string s;
	cin>>s;
	for(int i=0;i<s.length();i++){
		d[s[i]-'a']++;
	}
	int uniquecount=0;
	for(int i=0;i<26;i++){
		if(d[i])
			uniquecount++;
	}
	if(uniquecount>4){
		cout<<"No";
		return 0;
	}
	if(uniquecount<=1)
		cout<<"No";
		else {
			if(uniquecount==2){
				for(int i=0;i<26;i++)
				if(d[i]&&d[i]==1){
					cout<<"No";
					return 0;
				}
			}
			if(uniquecount==3){
				int onecount=0;
				for(int i=0;i<26;i++)
				if(d[i]&&d[i]==1){
					onecount++;
				}
				if(onecount>2){
				cout<<"No";
				return 0;
				}
			}
			if(uniquecount==4){
				int onecount=0;
				for(int i=0;i<26;i++)
				if(d[i]&&d[i]==1){
					onecount++;
				}
				if(onecount>3){
				cout<<"No";
				return 0;
				}
			}
			cout<<"Yes";
			return 0;
		}
	
	return 0;
}
