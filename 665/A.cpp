#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

#define fur(i, a, b) for (int(i) = (a); i < (b); ++(i))
#define revf(i, a, b) for (int(i) = (a)-1; (i) >= (b); --(i))
#define mp make_pair
#define mod 1000000007
#define inf 2000000007
#define pb push_back
#define eps 1e-5
#define X first
#define Y second

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	ll a, b;
	ll f, t;
	string time;
	cin >> a >> b >> f >> t;
	cin >> time;
	int minutes = 0;
	minutes += time[4] - '0';
	minutes += (time[3] - '0')*10;
	minutes += (time[1] - '0')*60;
	minutes += (time[0] - '0')*600;
	ll maxminutes = 23*60 + 59;
	int count=0;
	for(int i=300;i<24*60;i+=f){
		if(i+t<=minutes||i>=minutes+b){
		}else{
			count++;
		}
	}
	cout<<count;
	return 0;
}
