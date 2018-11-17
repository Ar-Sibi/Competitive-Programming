#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vll;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;
typedef pair<string,ll> psl;
typedef vector<psl> vpsl;
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

ll min(ll a,ll b){
	return a<b?a:b;
}



int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	string c;
	cin>>c;
	int last=c.length()-1;
	bool max=false;
	vll flip(c.length(),0);
	while(last>=0){
		ll maxindex=0;
		ll minindex=0;
		for(int i=0;i<=last;i++){
			if(max){
				if(c[i]>=c[maxindex]){
					maxindex=i;
				}
			}else{
				if(c[i]<=c[minindex]){
					minindex=i;
				}
			}
		}
		if(max){
			last=maxindex-1;
			flip[maxindex]=1;
		}else{
			last=minindex-1;
			flip[minindex]=1;
		}
		max=!max;
	}
	fur(i,0,c.length()){
		cout<<flip[i]<<" ";
	}

	
	return 0;
}
