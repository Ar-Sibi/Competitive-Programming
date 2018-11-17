#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

#define fur(i,a,b) for(int (i)=(a);i<(b);++(i))
#define revf(i,a,b) for(int (i)=(a)-1;(i)>=(b);--(i))
#define mp make_pair
#define mod 1000000007
#define inf 2000000007
#define pb push_back
#define eps 1e-5
#define X first
#define Y second

inline int max5(vector<ll> arr, int index){
	
}

inline int max(ll a,ll b ){
	return a>b?a:b;
}

inline int min(ll a,ll b ){
	return a<b?a:b;
}

inline int min5(vector<ll> arr, int index){
	int max = arr[index];
	for(int i=index-4>0?index-4:0;i<=index;i++){
		if(arr[i]<max)max = arr[i];
	}
	return max;
}

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	vector<long long> arr = vector<ll>(n);
	fur(i,0,n){
		cin>>arr[i];
	}
	string s;
	cin>>s;
	ll maxl = 1000000000;
	ll maxr = 1000000000;
	ll minl = -maxl;
	ll minr = -maxr;
	fur(i,1,n){
		if(s[i]=='1'&&s[i-1]=='0'){
			int max5 = arr[i];
			for(int j=i-4>0?i-4:0;j<=i;j++){
				if(arr[j]>max5)max5 = arr[j];
			}
			minl=max(minl,max5+1);
			i+=3;
		}else if (s[i]=='0'&&s[i-1]=='1'){
			int max5 = arr[i];
			for(int j=i-4>0?i-4:0;j<=i;j++){
				if(arr[j]<max5)max5 = arr[j];
			}
			maxr=min(maxr,max5-1);
			i+=3;
		}else if(s[i]=='0'&&i!=1&&i>4){
			int max5 = arr[i];
			for(int j=i-4>0?i-4:0;j<=i;j++){
				if(arr[j]>max5)max5 = arr[j];
			}
			maxl=min(maxl,max5);
		}else if(i!=1&&i>4){
			int max5 = arr[i];
			for(int j=i-4>0?i-4:0;j<=i;j++){
				if(arr[j]<max5)max5 = arr[j];
			}
			minr=min(minr,max5);
		}
	}
	cout<<max(minl,minr)<<' '<<min(maxl,maxr);
	return 0;
}
