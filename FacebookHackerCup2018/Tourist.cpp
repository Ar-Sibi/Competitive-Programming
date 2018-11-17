#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<string, ll> psl;
typedef vector<int> vi;
typedef vector<ll> vll;

#define fur(i,a,b) for(int (i)=(a);i<(b);++(i))
#define revf(i,a,b) for(int (i)=(a)-1;(i)>=(b);--(i))
#define mp make_pair
#define mod 1000000007
#define inf 2000000007
#define pb push_back
#define eps 1e-5
#define X first
#define Y second

bool comparator(pair<string,pll> a,pair<string,pll> b){
    if(a.Y.Y>b.Y.Y){
        return false;
    }else{
        if(a.Y.Y==b.Y.Y){
            if(a.Y.X>b.Y.X){
                return false;
            }
            return true;
        }
        return true;
    }
    return true;
}

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
    ll tc;
    cin>>tc;
    fur(tcs,1,tc+1){
        ll n,k,v;
        cin>>n>>k>>v;
        vector<string> s(n);
        ll lcmval = (n/__gcd(n,k))*k;
        for(int i=0;i<n;i++){
            cin>>s[i];
        }
        ll val=((v-1)*k)%lcmval;
        cout<<"Case #"<<tcs<<":";
        vector<pair<string,pll>> var = vector<pair<string,pll>>(n);
        for(int i=0;i<n;i++){
            var[i]=mp(s[i],mp(i,0));
        }
        sort(var.begin(),var.end(),comparator);
        
        vll answerBuilder = vll((lcmval));
        vll answer = vll(k);
        for(int j=0;j<(n/__gcd(n,k));j++){
            for(int i=0;i<k;i++){
                var[i].Y.Y++;
                answerBuilder[j*k+i]=var[i].Y.X;
            }
            sort(var.begin(),var.end(),comparator);
        }
        ll startingPoint = ((v-1)%((lcmval))*(k%(lcmval)));
        for(ll st=0;st<k;st++){
            answer[st]=answerBuilder[(st+startingPoint)%(lcmval)];
        }
        sort(answer.begin(),answer.end());
        for(ll st=0;st<k;st++){
            cout<<" "<<var[answer[st]].X;
        }
        cout<<"\n";
    }

	return 0;
}
