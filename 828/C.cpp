#include <bits/stdc++.h>
#include <sstream>
#include <string>
#include <sstream>
#include <vector>
#include <iterator>

using namespace std;
template <typename Out>
void split(const std::string &s, char delim, Out result)
{
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim))
    {
        *(result++) = item;
    }
}
bool custompaircomparator(pair<int, int> x, pair<int, int> y)
{
    return x.first < y.first;
}
vector<int> split(const std::string &s, char delim)
{
    std::vector<std::string> elems;
    split(s, delim, std::back_inserter(elems));
    vector<int> elem(elems.size()-1);
    for (int i = 1; i < elems.size(); i++)
    {
        stringstream geek(elems[i]);
        geek >> elem[i-1];
        elem[i-1]--;
    }
    return elem;
}

int main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    int q;
    cin >> q;
    int max = 0;
    vector<string> strings(q);
    vector<vector<int> > arr(q, vector<int>());
    vector<pair<int, int>> sor(0);
    for (int i = 0; i < q; i++)
    {
        cin >> strings[i];
        int vals;
        cin>>vals;
        for (int k = 0; k < vals; k++)
        {   int sit;
            cin>>sit;
            sit--;
            sor.push_back(pair<int, int>(sit, i));
            int max1 = strings[i].length() + sit;
            max = max > max1 ? max : max1;
        }
    }
    string res = "";
    for (int i = 0; i < max; i++)
    {
        res += 'a';
    }
    sort(sor.begin(), sor.end(), custompaircomparator);
    int lastreached = 0;
    for (int j = 0; j < sor.size(); j++)
    {
        int length = strings[sor[j].second].length();
        int start = sor[j].first;
        if(start+length>=lastreached){
            if(lastreached<start)
                lastreached=start;
            for(int k=lastreached;k<start+length;k++){
                res[k]=strings[sor[j].second][k-start];
            }
            lastreached=start+length;
        }
    }
    cout<<res;
    return 0;
}