#include<bits/stdc++.h>
using namespace std;
bool isperfect(long long i){
	int x= i;
long long sum=0;
	while(x!=0){
	sum+=x%10;
	x/=10;
	}
	if(sum>10)
		return false;
	if(sum==10)
		return true;
	return false;
}
int main(){
	long req =0;
	int q;
	cin>>q;
	long long i;
	for( i=9;i<100000000;i++){
		if(isperfect(i)){
		req++;
		}
		if(req==q){
		break;
		}
	}
	cout<<i;
return 0;
}
