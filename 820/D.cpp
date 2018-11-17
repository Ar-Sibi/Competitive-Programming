#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	long long n;
	cin>>n;
	vector<int> compensator(n);
	vector<int> inputarr(n);
	for(int i=0;i<n;i++){
		cin>>inputarr[i];
		compensator[(inputarr[i]-i+n)%n]++;
	}
	return 0;
}
