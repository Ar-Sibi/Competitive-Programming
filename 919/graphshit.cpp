#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long x;
	long long y;
	cin >> x;
	cin >> y;
	string str;
	cin>>str;
	vector<vector<int> > s(x, vector<int>());
	for (long i = 0; i < y; i++)
	{
		long a, b;
		cin >> a;
		cin >> b;
		s[a].push_back(b);
		s[b].push_back(-a);
	}

	vector<bool> t = vector<bool>(x+1, false);


	for (long i = 0; i < s.size(); i++)
	{
		stack<long> mystack = stack<long>();
		if(t[i]==false)
			mystack.push(i);
		else
			continue;
		while (!mystack.empty())
		{
			long x = mystack.top();
			mystack.pop();
			t[x] = true;
			for (int h = 0; h < s[i].size(); h++)
			{
				if (s[i][h] >= 0)
				{
				if(t[s[i][h]]){
					cout<<h<<i<<x<<endl;
				cout<<"-1";
				return 0;
			}
					mystack.push(s[i][h]);
				}
			}
		}
	}
	return 0;
}
