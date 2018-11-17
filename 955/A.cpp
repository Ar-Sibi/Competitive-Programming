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
	ll sttime=0;
	ll hrs;
	ll mins;
	cin>>hrs;
	cin>>mins;
	sttime=hrs*60+mins;
	if(sttime==0)sttime=24*60;
	float max=INT32_MAX;
	bool first = false;
	ll hunger,hi,buncost,hungerdecrease;
	cin>>hunger>>hi>>buncost>>hungerdecrease;
	for(ll i=sttime;i!=sttime-1;i++){
		float bunsreqd = hunger/hungerdecrease;
		if(hunger%hungerdecrease!=0)bunsreqd++;
		float cost = bunsreqd*buncost;
		if(i>=(20*60)){
			cost-=((double)cost/5.0);
		}
		//if(i==20*60)cout<<cost<<endl;
		if(!first){
			max=cost;
			first =true;
		}
		if(max>cost){
			max=cost;
		}
		hunger+=hi;
		i=i%(24*60);
	}


	cout<<setprecision(12)<<max;
	return 0;
}
