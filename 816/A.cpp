#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	long long n;
	string s;
	cin>>s;
	int hours = (s[0]-'0')*10+s[1]-'0';
	int mins = (s[3]-'0')*10+s[4]-'0';
	int minsx=0;
	while(true){
		string t="     ";
		for(int i=0;i<s.length();i++){
			t[4-i]=s[i];
		}
		if(s==t){
			cout<<minsx;
			return 0;
		}
		mins = (mins+1)%60;
		hours = (mins==0)?(hours+1)%24:hours;
		int x= hours/10;
		int y = mins/10;
		s[4]=mins%10+'0';
		s[3]=y%10+'0';
		s[1]=hours%10+'0';
		s[0]=x%10+'0';
		minsx++;
	}
	return 0;
}
