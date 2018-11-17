#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vll;
typedef vector<vll> vvll;
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
	return a.Y>b.Y;
}

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	ll n,e;
	cin>>n;
	cin>>e;
	vpll ar(n,mp(0,0));
	vll cost(n);
	vll netcost(n);
	fur(i,0,n){cin>>cost[i];ar[i].X=i;ar[i].Y=0;}
	vvll m(n,vll());
	fur(i,0,e){
		ll x,y;
		cin>>x>>y;
		x--;y--;
		m[x].pb(y);
		m[y].pb(x);
		ar[x].Y=cost[x];
		ar[y].Y=cost[y];
		netcost[x]+=cost[y];
		netcost[y]+=cost[x];
	}
	// cout<<"sadasd"<<endl;;
	// fur(i,0,m.size()){
	// 	cout<<"netcost"<<netcost[i]<<"   :";
	// 	fur(j,0,m[i].size()){
	// 		cout<<m[i][j]<<"  ";
	// 	}
	// 	cout<<endl;
	// }
	ll val=0;
	fur(i,0,n){
		sort(ar.begin()+i,ar.end(),comp);
		val+=netcost[ar[i].X];
		fur(j,0,m[ar[i].X].size()){
			// cout<<endl<<"X"<<m[ar[i].X][j]<<"Y"<<endl;
			netcost[m[ar[i].X][j]]-=cost[ar[i].X];
		}
	}
	cout<<val;
	return 0;
}
