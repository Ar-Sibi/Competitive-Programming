#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	long long x,y,X,Y,r;
	cin>>r>>x>>y>>X>>Y;
	long long dist = sqrt((X-x)*(X-x)+(Y-y)*(Y-y));
	if(dist==0){
		cout<<dist;
		return 0;
	}
	long long sq = r;
	if (dist%sq==0)
		cout<<((dist/sq))-1;
	else
		cout<<(dist/sq);

	return 0;
}
