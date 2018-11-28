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


ll modpow(ll base, ll exp, ll modulus) {
  base %= modulus;
  ll result = 1;
  while (exp > 0) {
    if (exp & 1) result = (result * base) % modulus;
    base = (base * base) % modulus;
    exp >>= 1;
  }
  return result;
}

ll modinv(ll a, ll m) { 
    ll m0 = m; 
    ll y = 0, x = 1; 
    if (m == 1) 
      return 0; 
    while (a > 1) 
    { 
        ll q = a / m;
        ll t = m;
        m = a % m, a = t;
        t = y;
        y = x - q * y;
        x = t;
    } 
    if (x < 0)
       x += m0;
    return x;
}
bool sorter(pll a,pll b){
    return a.Y<b.Y;
}
bool isadj(ll a,ll b){
    if(a>b){
        ll temp = b;
        b=a;
        a=temp;
    }
    return a+1==b;
}
int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
    ll n;
    cin>>n;
    if(n==1){
        ll x;
        cin>>x;
        cout<<x+1;
        return 0;
    }
    vpll ind(n);
    fur(i,0,n){
        ll x;
        cin>>x;
        ind[i]=mp(i,x);
    }
    sort(ind.begin(),ind.end(),sorter);
    ll numcom=0;
    unordered_map<ll,ll> comsize;
    unordered_map<ll,ll> hmap;
    vll som(n);
    ll ansk=0;
    ll ansi=n;
    ll componentsevercreated=0;
    fur(i,0,n){
        if(ind[i].X==0){
            if(som[1]!=0){
                hmap[-abs(som[1])]=0;
                som[0]=-abs(som[1]);
                comsize[hmap[-abs(som[1])]-hmap[abs(som[1])]]--;
                comsize[hmap[-abs(som[1])]-hmap[abs(som[1])]+1]++;
                if(comsize[hmap[-abs(som[1])]-hmap[abs(som[1])]+1]==numcom){
                    if(numcom>ansk){
                        ansk=numcom;
                        ansi=i;
                    }
                }
            }else{
                componentsevercreated++;
                som[0]=componentsevercreated;
                hmap[componentsevercreated]=0;
                hmap[-componentsevercreated]=0;
                comsize[1]++;
                numcom++;
                if(comsize[1]==numcom){
                    if(numcom>ansk){
                        ansk=numcom;
                        ansi=i;
                    }
                }
            }
        }else if(ind[i].X==n-1){
            if(som[n-2]!=0){
                comsize[-hmap[-abs(som[n-2])]+hmap[abs(som[n-2])]+1]--;
                hmap[abs(som[n-2])]=n-1;
                som[n-1]=+abs(som[n-2]);
                comsize[-hmap[-abs(som[n-2])]+hmap[abs(som[n-2])]+1]++;
                if(comsize[-hmap[-abs(som[n-2])]+hmap[abs(som[n-2])]+1]==numcom){
                    if(numcom>ansk){
                        ansk=numcom;
                        ansi=i;
                    }
                }
            }else{
                componentsevercreated++;
                som[n-1]=componentsevercreated;
                hmap[componentsevercreated]=n-1;
                hmap[-componentsevercreated]=n-1;
                comsize[1]++;
                numcom++;
                if(comsize[1]==numcom){
                    if(numcom>ansk){
                        ansk=numcom;
                        ansi=i;
                    }
                }
            }
        }else{
            ll in=ind[i].X;
            if(som[in+1]!=0&&som[in-1]!=0){
                som[hmap[abs(som[in+1])]]=abs(som[in+1]);
                som[hmap[-abs(som[in-1])]]=-abs(som[in-1]);
                numcom--;
                ll leftmostindex=hmap[-abs(som[in-1])];
                comsize[hmap[abs(som[in-1])]-hmap[-abs(som[in-1])]+1]--;
                comsize[hmap[abs(som[in+1])]-hmap[-abs(som[in+1])]+1]--;
                ll rightmostindex=hmap[+abs(som[in+1])];
                hmap[abs(som[in-1])]=hmap[+abs(som[in+1])];
                som[hmap[+abs(som[in+1])]]=abs(som[in-1]);
                comsize[rightmostindex-leftmostindex+1]++;
                if(comsize[rightmostindex-leftmostindex+1]==numcom){
                    if(numcom>ansk){
                        ansk=numcom;
                        ansi=i;
                    }
                }
            }else if(som[in+1]!=0){
                som[hmap[abs(som[in+1])]]=abs(som[in+1]);
                comsize[abs(hmap[-som[in+1]]-hmap[som[in+1]])+1]--;
                hmap[-abs(som[in+1])]=in;
                som[in]=-abs(som[in+1]);
                comsize[abs(hmap[-som[in+1]]-hmap[som[in+1]])+1]++;
                if(comsize[-hmap[-abs(som[in+1])]+hmap[abs(som[in+1])]+1]==numcom){
                    if(numcom>ansk){
                        ansk=numcom;
                        ansi=i;
                    }
                }
            }else if(som[in-1]!=0){
                comsize[hmap[abs(som[in-1])]-hmap[-abs(som[in-1])]+1]--;
                som[hmap[-abs(som[in-1])]]=-abs(som[in-1]);
                hmap[abs(som[in-1])]=in;
                som[in]=+abs(som[in-1]);
                // cout<<hmap[abs(som[in-1])]-hmap[-abs(som[in-1])]+1<<"wtf"<<endl;
                comsize[hmap[abs(som[in-1])]-hmap[-abs(som[in-1])]+1]++;
                if(comsize[-hmap[-abs(som[in-1])]+hmap[abs(som[in-1])]+1]==numcom){
                    if(numcom>ansk){
                        ansk=numcom;
                        ansi=i;
                    }
                }
            }else{
                componentsevercreated++;
                numcom++;
                som[in]=componentsevercreated;
                hmap[componentsevercreated]=in;
                hmap[-componentsevercreated]=in;
                comsize[1]++;
                if(comsize[1]==numcom){
                    if(numcom>ansk){
                        ansk=numcom;
                        ansi=i;
                    }
                }
            }
        }
        // fur(d,0,n){
        //     cout<<som[d]<<" ";
        // }
        // cout<<endl;
        // cout<<numcom<<"comp"<<endl;
        // fur(g,1,6){
        //     cout<<comsize[g]<<endl;
        // }
        // cout<<endl<<"anstillnow"<<ansk;
        // cout<<"next"<<endl;
    }
    // fur(i,0,n){
    //     cout<<som[i]<<" ";
    // }
    // cout<<ansi;
    cout<<endl<<ind[ansi].Y+1;
	return 0;
}