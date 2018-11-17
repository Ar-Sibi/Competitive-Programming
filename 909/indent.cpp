#include<bits/stdc++.h>
using namespace std;
long long totallify(vector<int> l,int reduction,int prod,int index){
	if(index==l.size()-1){
	//	cout<<reduction<<"s"<<endl;
		return l[index]-reduction;
	}
	long long sum=0;
	//cout<<l[index]<<"q"<<reduction<<endl;
	for(int i=l[index]-reduction;i>=1;i--){
	//	cout<<i<<"i"<<endl;
		sum+=totallify(l,l[index]-i,prod,index+1);
	}
	return sum;
}
int main(){
int t;
cin>>t;
vector<int>s(t);
for(int i=0;i<t;i++){
	char x;
	cin>>x;
	if(x=='f')
		s[i]=1;
}
long long total=1;
long long mod=1000000007;
vector<int>levels(0);
int indent_levels=1;
if(s[0]==1){
	indent_levels++;
}
for(int i=1;i<t-1;i++){
	if(s[i]==1&&s[i-1]!=1){
	levels.push_back(indent_levels);
	}
	if(s[i]==1)
		indent_levels++;
}
if(s[t-1]==0&&s[t-2]==0)
	levels.push_back(indent_levels);
for(int i=0;i<levels.size();i++){
	//cout<<levels[i]<<endl;
}
total = totallify(levels,0,1,0);
cout<<total%mod;
}
