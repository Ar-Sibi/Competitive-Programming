#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
float getAngle(float left,float right,long n){
	float t = ((float)(n-2)*180)/(float)(n);
	float lefttheta = (left-1)*180-(left-1)*t;
	lefttheta/=2;
	float righttheta = (right-1)*180-(right-1)*t;
	righttheta/=2;
	return righttheta-lefttheta; 
}
int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	long n,reqd;
	float l,r;
	cin>>n>>reqd;
	float t=((float)(n-2)*180)/(float)(n);
	t/=(n-2);

	int minl=1;
	for(l=1;l<n-1;l++){
		if(abs(l*t - reqd)<abs(minl*t-reqd)){
			minl=l;
		}
	}
	cout<<2<<" "<<1<<" "<<2+minl;
	return 0;
}
