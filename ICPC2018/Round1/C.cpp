#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t;
	cin >> t;
	while (t--)
	{
		ll n;
		cin >> n;
		vector<string> s(n);
		map<string, string> m;
		for (ll i = 0; i < n; i++)
		{
			cin >> s[i];
			string t = s[i];
			reverse(s[i].begin(), s[i].end());
			if (s[i] > t)
			{
				s[i] = t;
			}
			m[s[i]] = s[i];
		}
		vector<string> rvs;
		vector<string> rrvs;
		vector<string> vs;
		for (auto itr = m.begin(); itr != m.end(); itr++)
		{
			vs.push_back(m[itr->first]);
			rvs.push_back(m[itr->first]);
			string t = m[itr->first];
			reverse(t.begin(), t.end());
			rrvs.push_back(t);
			if (m[itr->first] != t)
			{
				vs.push_back(t);
			}
		}
		if (vs.size() > 16)
		{
			cout << "grid\nsnot\nposs\nible\n\n";
			continue;
		}
		vs.push_back("AAAA");
		vll o(4);
		unordered_map<string, ll> sv;
		vector<string> answers;
		ll n1 = vs.size();
		for (o[0] = 0; o[0] < n1; o[0]++)
		{
			for (o[1] = 0; o[1] < n1; o[1]++)
			{
				for (o[2] = 0; o[2] < n1; o[2]++)
				{
					for (o[3] = 0; o[3] < n1; o[3]++)
					{
						ll val = o[0] * n1 * n1 * n1 + o[1] * n1 * n1 + o[2] * n1 + o[3];
						vector<string> x(4, "   ");
						vector<string> y(4, "   ");
						for (int d = 0; d < 4; d++)
						{
							x[d] = vs[o[d]];
							sv[x[d]] = val;
							reverse(x[d].begin(), x[d].end());
							sv[x[d]] = val;
							reverse(x[d].begin(), x[d].end());
						}
						for (ll f = 0; f < 4; f++)
						{
							for (ll g = f + 1; g < 4; g++)
							{
								char er = x[f][g];
								x[f][g] = x[g][f];
								x[g][f] = er;
							}
						}
						for (int d = 0; d < 4; d++)
						{
							sv[x[d]] = val;
							reverse(x[d].begin(), x[d].end());
							sv[x[d]] = val;
							reverse(x[d].begin(), x[d].end());
						}
						bool nf = false;
						for (ll i = 0; i < rvs.size(); i++)
						{
							if (sv[rvs[i]] != val)
								nf = true;
						}
						if (!nf)
						{
							string str="";
							for(int iok=0;iok<4;iok++)str+=x[iok]+"\n";
							answers.push_back(str);
						}
					}
				}
			}
		}
		if (answers.size() == 0)
		{
			cout << "grid\nsnot\nposs\nible\n\n";
			continue;
		}
		ll min = 0;
		for (int lkl = 0; lkl < answers.size(); lkl++)
		{
			
				if (answers[lkl] > answers[min])
				{
					break;
				}
				if (answers[lkl] < answers[min])
				{
					min = lkl;
					break;
				}
		}
		cout << answers[min] << "\n";
	}
}