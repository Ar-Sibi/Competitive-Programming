#include<bits/stdc++.h>
using namespace std;
int main(){
	double max = 10000.0;
	int q ;
	int no;
	cin>>q;
	cin>>no;
	while(q--){
		double d;
		cin>>d;
		double v;
		cin>>v;
		if((d/v)<max){
			max=d/v;
		}
	}
	cout<<setprecision(10)<<no*max;
	return 0;
}
