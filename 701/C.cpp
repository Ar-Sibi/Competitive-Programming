#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	unordered_map<char,int> ch;
	long n;
	cin>>n;
	vector<char> d(0);
	string input;
	cin>>input;
	for(int i=0;i<n;i++){
		if(ch[input[i]]==0){
			d.push_back(input[i]);
			ch[input[i]]=d.size();
		}
	}
	vector<int> x(d.size(),-1);
	long long minmin=INT_MAX;
	for(int i=0;i<n;i++){
		long long max=0;
			int index=ch[input[i]]-1;
			x[index]=i;
			int j=0;
		for( j=0;j<d.size();j++){
			if(x[j]==-1){
			break;
			}
			if((i-x[j])>max){
				max = i-x[j];
			}
		}
		if(j==d.size()){
			if(max<minmin){
				minmin=max;
			}
		}else{

		}
	}
	cout<<minmin+1;
	return 0;
}
