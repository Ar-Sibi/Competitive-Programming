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
	int n, m;
	cin >> n;
	cin >> m;
	vector<string> ar = vector<string>(n);
	for (int i = 0; i < n; i++)
	{
		cin >> ar[i];
	}
	vector<vi> fr = vector<vi>(n, vi(m));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (ar[i][j] == '*')
			{
				int t = i - 1;
				int l = j - 1;
				if (t >= 0)
				{
					if (l >= 0)
					{
						fr[t][l]++;
					}
					l++;
						fr[t][l]++;
					l++;
					if (l < m)
					{
						fr[t][l]++;
					}
				}
				t++;
				l=j-1;
				if (l >= 0)
				{
					fr[t][l]++;
				}
				l++;
					fr[t][l]++;
				l++;
				if (l < m)
				{
					fr[t][l]++;
				}
				t++;
				l=j-1;
				if(t<n){
					if(l>=0){
						fr[t][l]++;
					}
					l++;
						fr[t][l]++;
					l++;
					if(l<m){
						fr[t][l]++;
					}
				}
			}
		}
	}
	ll x=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(fr[i][j]==0){
				if(ar[i][j]=='.'||ar[i][j]=='*'){
					x++;
				}
			}else{
				if((ar[i][j]-'0'==fr[i][j])||ar[i][j]=='*'){
					x++;
				}
			}
		}
	}
	cout<<((x==m*n)?"YES":"NO");
	return 0;
}
