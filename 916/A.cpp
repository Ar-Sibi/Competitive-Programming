#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int w;
	cin>>w;
	int h;
	cin>>h;
	int m;
	cin>>m;
	int flag=false;
	long x=0;
	while(!flag){
		if(m%10==7){
			break;
		}
		if(h%10==7){
			break;
		}
		m-=w;
		if(m<0){
			m+=60;
			h=(24+h-1)%24;
		}
		x++;
	}
	cout<<x<<endl;
	return 0;
}
