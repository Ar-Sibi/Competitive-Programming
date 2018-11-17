#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vll;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;
typedef pair<string, ll> psl;
typedef vector<psl> vpsl;
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
	ll n,k;
	cin>>n>>k;
	vll ar(n);
	string s;
	cin>>s;
	fur(i,0,s.length()){
		ar[i]=(s[i]-'a')+1;
	}
	sort(ar.begin(),ar.end());
	ar.erase( unique( ar.begin(), ar.end() ), ar.end() );
	int prev=0;
	int count =1;
	int sum=ar[0];
	fur(i,1,ar.size()){
		if(ar[i]-ar[prev]!=1){
			count++;
			sum+=ar[i];
			prev=i;
		}
		if(count==k)
		break;
	}
	if(count>=k)
	cout<<sum<<endl;
	else
	cout<<-1;
	return 0;
}
