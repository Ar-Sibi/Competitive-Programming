#include <bits/stdc++.h>
using namespace std;
int main()
{
    string a;
    string b;
    cin >> a;
    cin >> b;
    std::transform(a.begin(), a.end(), a.begin(), ::tolower);
    std::transform(b.begin(), b.end(), b.begin(), ::tolower);
    vector<int> q(26);
    for (int i = 0; i < a.length(); i++)
    {
        q[a[i] - 'a'] = 1;
    }
    bool star = false;
    int starlocation = -1;
    for (int i = 0; i < b.length(); i++)
    {
        if (b[i] == '*')
        {
            star = true;
            starlocation = i;
        }
    }
    long long k;
    cin >> k;
    string x;
    getline(cin,x);
    while (k--)
    {
        string d;
        getline(cin,d);
        
        std::transform(d.begin(), d.end(), d.begin(), ::tolower);
        if (star)
        {   
            if((d.length()==0&&b.length()==1)&&b[0]=='*')
            cout<<"YES\n";
            else
            if (d.length() < b.length()-1)
            {
                cout << "NO\n";
            }
            else
            {
                int i;
                for (i = 0; i < starlocation; i++)
                {
                    if (d[i] == b[i] || (b[i] == '?' && q[d[i] - 'a'] == 1))
                    {
                    }
                    else
                        break;
                }
                if (i != starlocation)
                    cout << "NO\n";
                else
                {   
                    for (i = 0; b[(b.length()-1)-i] != '*'; i++)
                    {
                        if (d[(d.length() - 1) - i] == b[(b.length()-1)-i] || (b[(b.length()-1)-i] == '?' && q[d[(d.length() - 1) - i] - 'a'] == 1))
                        {
                        }
                        else{
                            break;
                        }
                    }
                    if(b[(b.length()-1)-i] != '*'){
                    cout<<"NO\n";
                    }
                    else{
                        for(i=starlocation;i<=starlocation+d.length()-b.length();i++){
                            if(q[d[i]-'a']==1)
                                break;
                        }
                        if(i!=starlocation+d.length()-b.length()+1)
                        cout<<"NO\n";
                        else
                            cout<<"YES\n";
                    }
                }
            }
        }
        else
        {
            if (d.length() != b.length())
            {
                cout << "NO\n";
            }
            else
            {
                int i;
                for (i = 0; i < b.length(); i++)
                {
                    if (d[i] == b[i] || (b[i] == '?' && q[d[i] - 'a'] == 1))
                    {
                    }
                    else
                        break;
                }
                if (i == b.length())
                    cout << "YES\n";
                else
                    cout << "NO\n";
            }
        }
    }
}