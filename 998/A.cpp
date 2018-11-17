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
	int x;
	vi l;
	cin>>x;
	l=vi(x);
	int index=0;
	int min = INT_MAX;
	for(int i=0;i<x;i++){
		cin>>l[i];
		if(l[i]<min){
			min=l[i];
			index=i;
		}
	}
	sort(l.begin(),l.end());
	if(l[0]==l[l.size()-1]&&(l.size()==1||l.size()==2)){
		cout<<-1;
		return 0;
	}
	cout<<1<<endl<<index+1;


	
	return 0;
}
