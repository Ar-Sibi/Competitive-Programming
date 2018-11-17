#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
int main(){
	int a;
	cin>>a;
	int b;
	cin>>b;
	unordered_map<string,string> l;
	for(int i = 0; i<a+b;i++){
		if(i<a){
			string sa;
			string sb;
			cin>>sa;
			cin>>sb;
			sb+=";";
			l[sb]=sa;
		}
		else{
		string sx;
		string sy;
		cin>>sx;
		cin>>sy;
		cout<<sx<<" "<<sy<<" #"<<l[sy]<<endl;
		}
	}
	return 0;
}
