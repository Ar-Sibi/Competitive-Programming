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
	int n,m;
	cin>>n;
	cin>>m;
	string s;
	cin>>s;
	vi ff = vi(26);
	fur(i,0,s.length()){
		ff[s[i]-'a']++;
	}
	vector<char> arr = vector<char>();
	unordered_map<char,int> revmap;
	fur(i,0,26){
		if(ff[i]){
			revmap[i+'a']=arr.size();
			arr.pb(i+'a');
		}
	}
	if(m>n){
		fur(i,n,m){
			s+=arr[0];
		}
	}else if(m==n){
		int l = s.length()-1;
		while(s[l]==arr[arr.size()-1]){
			s[l]=arr[0];
			l--;
		}
			s[l] = arr[revmap[s[l]]+1];
			cout<<s;
			return 0;
	}else{
		string t="";
		for(int i=0;i<m;i++){
			t+=s[i];
		}
		int l = t.length()-1;
		while(t[l]==arr[arr.size()-1]){
			t[l]=arr[0];
			l--;
		}
			t[l] = arr[revmap[t[l]]+1];
			cout<<t;
			return 0;
	}
	cout<<s;
	return 0;
}
