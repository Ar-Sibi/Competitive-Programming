#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
vector<int> getSetBits(long long x){
	vector<int> d(0);
	int i=0;
	while(x){
		if((x&1)==1){
			d.push_back(i);
		}
		x/=2;
		i++;
	}
	return d;
}
int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	long long d;
	cin>>d;
	int reqdsize;
	cin>>reqdsize;
	unordered_map<long long,int> x; 
	vector<int> bytes = getSetBits(d);
	for(int i=0;i<bytes.size();i++){
		x[bytes[i]]++;
	}
	int currsize = bytes.size();
	if(currsize>reqdsize){
		cout<<"No";
		return 0;
	}
	int start = bytes[bytes.size()-1];
	int iterator = start;
		while(x[iterator]==0)
			iterator--;
		if(currsize!=reqdsize){
			x[iterator]--;
			x[iterator-1]+=2;
			currsize++;
		}
	cout<<"Yes\n";
	for(long  i = 100000; i>= -100000;i--){
		while(x[i]>0){
			cout<<i<<" ";
			x[i]--;
		}
	}
	return 0;
}
