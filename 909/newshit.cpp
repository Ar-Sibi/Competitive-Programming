#include<bits/stdc++.h>
using namespace std;
int main(){
string a;
string b;
cin>>a;
cin>>b;
string c="";
c+=a[0];
int i=1;
for(;i<a.length();i++){
	if(a[i]<b[0]){
	c+=a[i];
	}
	else 
		break;
}
c+=b[0];
cout<<c;
}
