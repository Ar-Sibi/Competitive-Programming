#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	long totalpg,insp,maxsp,acc,rev;
	cin>>totalpg>>insp>>maxsp>>acc>>rev;
	if(totalpg<=insp){
		cout<<1;
		return 0;
	}
	long currpg=insp;
	long days=1;
	while(currpg<totalpg){
		insp+=acc;
		if(insp>=maxsp)insp=maxsp;
		currpg-=rev;
		currpg+=insp;
		days++;
	}
	cout<<days;
	return 0;
}
