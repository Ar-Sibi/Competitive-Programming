#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	long long levels=0;
	cin>>levels;
	long long numonscreen=2;
	if(levels==1){
		cout<<2;
		return 0;
	}else{
		cout<<2<<endl;
	}
	for(long long i=2;i<=levels;i++){
		cout<<(i+1)*(i+1)*(i)-numonscreen/i<<endl;
		//cout<<"TAG"<<numonscreen + ((i+1)*(i+1)*(i)-numonscreen/i)*i<<endl;
		numonscreen=i*(i+1);
	}
	return 0;
}
