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
	string s;
	cin >> s;
	bool isTwo = false;
	bool isThree = false;
	for (int i = 1; i < s.size(); i++)
	{
		if (s[i] == s[i - 1])
		{
			if (isTwo)
			{
				if (s[i - 1] == 'z')
				{
					s[i - 1] = 'a';
				}
				else
				{
					s[i - 1]++;
				}
				isTwo=false;
			}
			else
			{
				isTwo = true;
			}
		}
		else
		{
			if (isTwo)
			{
				if (s[i - 2] == 'a')
				{
					if (s[i] == 'b')
					{
						s[i-1] = 'c';
					}
					else
					{
						s[i-1] = 'b';
					}
				}
				else
				{
					if (s[i] == 'a')
					{
						if(s[i-2]=='z'){
							s[i-1]='d';
						}else{
							s[i-1]++;
						}
					}
					else
					{
						s[i-1] = 'b';
					}
				}
			}
			else
			{
			}
			isTwo=false;
		}
	}
	ll i=s.size()-1;
	if (isTwo)
			{
				if (s[i - 2] == 'a')
				{
					{
						s[i-1] = 'b';
					}
				}
				else
				{
					s[i-1]='a';
				}
			}
	cout<<s;
	return 0;
}
