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

int comp(pll a,pll b){
	return a.X>b.X;
}

int comp1(pll a,pll b){
	if(a.Y==b.Y){
		return a.X>b.X;
	}
	return a.Y>b.Y;
}

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	ll n;
	cin>>n;
	vpll a(n,mp(0,0));
	vpll b(n,mp(0,0));
	fur(i,0,n){
		cin>>a[i].X>>a[i].Y;
		b[i].X=a[i].X;
		b[i].Y=a[i].Y;
	}
	sort(a.begin(),a.end(),comp1);
	sort(b.begin(),b.end(),comp);
	fur(i,0,n){
		if((a[i].X==b[i].X)&&(a[i].Y==b[i].Y)){
		
		}else{
			cout<<"Happy Alex";
			return 0;
		}
	}
	cout<<"Poor Alex";
	return 0;
}
