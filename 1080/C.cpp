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

#define fur(i, a, b) for (ll(i) = (a); i < (b); ++(i))
#define revf(i, a, b) for (ll(i) = (a)-1; (i) >= (b); --(i))
#define mp make_pair
#define mod 1000000007
#define inf 2000000007
#define pb push_back
#define x first
#define y second

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        ll x1, y1, x2, y2;
        ll x3, y3, x4, y4;
        cin >> x1 >> y1 >> x2 >> y2;
        cin >> x3 >> y3 >> x4 >> y4;
        ll whites = 0;
        ll black=0;
        ll l = y2 - y1;
        l++;
        ll w = x2 - x1;
        w++;
        if (l % 2 == 0 || w % 2 == 0)
        {
            whites = (l * w) / 2;
            black = -whites;
        }
        else
        {
            whites = (l * w) / 2;
            if ((x1 + y1) % 2 != 0)whites++;
            else{

            }
        }
        // cout<<whites<<"wqwqwd\n";
        ll x5 = max(x1, x3);
        ll y5 = max(y1, y3);
        ll x6 = min(x2, x4);
        ll y6 = min(y2, y4);
        // cout<<" "<<x5<<" "<<y5<<" "<<x6<<" "<<y6<<endl;
        if (x5 <= x6 && y5 <= y6)
        {
            ll l = y6 - y5;
            l++;
            ll w = x6 - x5;
            w++;
            ll v=0;
            if (l % 2 == 0 || w % 2 == 0)
            {
                v= (l * w) / 2;
            }
            else
            {   
                v= (l * w) / 2;
                if ((x5 + y5) % 2 == 0){
                    
                }else{
                    v++;
                }
                
            }
            whites=whites-v;
            // cout<<"wtf";
        }
        
        // cout<<whites<<"s\n";
        l=y4-y3;l++;
        w=x4-x3;w++;
        if(l%2==0||w%2==0){
            whites-=(l*w)/2;;
        }else{
            whites-=(l*w)/2;
            if((x3+y3)%2==0)whites--;
        }
        whites+=(n*m)/2;
        if(n%2==1&&m%2==1){
            whites++;
        }
        ll blackz = (n*m-whites);
        cout<<whites<<" "<<blackz<<"\n";
        // // Test
        // vector<vll> tester(m,vll(n,0));
        // fur(i,0,m){fur(j,0,n){
        //     tester[i][j]=(i+j)%2;
        //     // cout<<tester[i][j]<<" ";
        // }cout<<endl;}
        // // cout<<1<<endl;
        // fur(i,x1-1,x2){
        //     fur(j,y1-1,y2){
        //         tester[i][j]=0;
        //     }
        // }
        // fur(i,x3-1,x4){
        //     fur(j,y3-1,y4){
        //         tester[i][j]=1;
        //     }
        // }
        // ll whi=0;
        // ll bla=0;
        // // cout<<endl;
        // fur(i,0,m){
        //     fur(j,0,n){
        //         // cout<<tester[i][j]<<" ";
        //         if(!tester[i][j])whi++;
        //         else bla++;
        //     }
        //     // cout<<endl;
        // }
        // cout<<whi<<" "<<bla<<"\n\n";
    }

    return 0;
}
