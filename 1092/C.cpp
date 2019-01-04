#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
struct myhash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;
typedef pair<string,ll> psl;
typedef vector<psl> vpsl;
typedef vector<int> vi;

#define fur(i,a,b) for(ll (i)=(a);i<(b);++(i))
#define revf(i,a,b) for(ll (i)=(a)-1;(i)>=(b);--(i))
#define mp make_pair
#define mod 1000000007
#define inf 2000000007
#define pb push_back
#define eps 1e-5
#define X first
#define Y second



bool lengthsorter(string a,string b){
    return a.length()<b.length();
}

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
    ll n;
    cin>>n;
    if(n==2){
        cout<<"PS";
        return 0;
    }

    vector<string> a(2*(n-1));
    vector<string> b(2*(n-1));
    fur(i,0,a.size()){
        cin>>a[i];
        b[i]=a[i];
    }
    sort(a.begin(),a.end(),lengthsorter);
    vector<string> ans(0);
    string first=a[0];
    string last=a[1];
        string big=a[b.size()-1];
        string big2=a[b.size()-2];
        if(first+big==big2+last){
            ans.pb(first+big);
        } if(first+big2==big+last) {
            ans.pb(first+big2);
        } if(last+big==big2+first){
            ans.pb(last+big);
        } if(last+big2==big+first){
            ans.pb(last+big2);
        }
        // cout<<ans.size();
    unordered_map<ll,ll> m;
    string finalans="";
    bool isans=true;
    fur(j,0,ans.size()){
        // cout<<ans[j]<<endl;
        finalans="";
        isans=true;
        m.clear();
    fur(i,0,b.size()){
        if((ans[j].substr(0,b[i].size()))==b[i]&&m[b[i].size()]!=1){
            m[b[i].size()]=1;
            finalans+="P";
        }else{
            if((ans[j].substr((n)-b[i].size(),b[i].size()))==b[i]&&m[b[i].size()]!=-1)
            finalans+="S";
            else isans=false;
            
            m[b[i].size()]=-1;
        }
        if(isans==false){
            // cout<<b[i]<<" "<<i<<endl;
            break;
        }
    }    
        if(isans){
            cout<<finalans;
            return 0;
        }
    }
    return 0;
}
