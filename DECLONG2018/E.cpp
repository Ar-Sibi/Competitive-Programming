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

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
    ll t;
    cin>>t;
    while(t--){
    ll n;
    cin>>n;
    vpll notgreatest(0);
    unordered_map<ll,bool> mapper;
    ll nd,rd;
    if(n%2==0){
        cout<<"? 1 2 3 4 5"<<endl;
        vll current(5);
        fur(i,0,5)current[i]=i+1;
        cin>>nd;
        cin>>rd;
        mapper[nd]=1;
        mapper[rd]=1;
        notgreatest.pb({nd,rd});
        ll last=5;
        for(int i=0;i<n-6;i+=2){
            fur(i,0,5){
                if(mapper[current[i]]==1){
                    current[i]=last+1;
                    last++;
                }
            }
            cout<<"?";
            fur(i,0,5)cout<<" "<<current[i];
            cout<<endl;
        
            cin>>nd;
            cin>>rd;
            mapper[nd]=1;
            mapper[rd]=1;
            notgreatest.pb({nd,rd});
        }
        fur(i,0,5){
            if(current[i]==nd){
                current[i]=last+1;
                last++;
                break;
            }
        }
        cout<<"?";
        fur(i,0,5)cout<<" "<<current[i];
        cout<<endl;
    
        cin>>nd;
        cin>>rd;
        mapper[nd]=1;
        mapper[rd]=1;
        notgreatest.pb({nd,rd});
        ll greatest=0;
        ll second=0;
        ll third;
        ll sz=notgreatest.size();
        greatest=notgreatest[sz-1].second;
        second=notgreatest[sz-1].first;
        third=notgreatest[sz-2].first;
        if(greatest==notgreatest[sz-2].first){
            greatest=notgreatest[sz-2].second;
        }
        vll great(0);
        fur(i,1,n+1){
            if(mapper[i]!=1){
                great.pb(i);
            }
        }
        current={great[0],great[1],greatest,second,third};
        cout<<"?";
        fur(i,0,5)cout<<" "<<current[i];
        cout<<endl;
    
        cin>>nd;
        cin>>rd;
        if(rd!=greatest){
            cout<<"! "<<great[2]<<endl;
        }else{
            current={great[2],great[1],greatest,second,third};
            cout<<"?";
            fur(i,0,5)cout<<" "<<current[i];
            cout<<endl;
        
            cin>>nd;
            cin>>rd;
            if(rd!=greatest){
            cout<<"! "<<great[0]<<endl;
            }else{
                cout<<"! "<<great[1]<<endl;
            }
        } 
    }else{
        cout<<"? 1 2 3 4 5"<<endl;
        vll current(5);
        fur(i,0,5)current[i]=i+1;
        cin>>nd;
        cin>>rd;
        mapper[nd]=1;
        mapper[rd]=1;
        notgreatest.pb({nd,rd});
        ll last=5;
        for(int i=0;i<n-6;i+=2){
            fur(i,0,5){
                if(mapper[current[i]]==1){
                    current[i]=last+1;
                    last++;
                }
            }
            cout<<"?";
            fur(i,0,5)cout<<" "<<current[i];
            cout<<endl;
            cin>>nd;
            cin>>rd;
            mapper[nd]=1;
            mapper[rd]=1;
            notgreatest.pb({nd,rd});
        }
        vll great(0);
        fur(i,1,n+1){
            if(mapper[i]!=1){
                great.pb(i);
            }
        }
        ll sz=notgreatest.size();
        ll ans=0;
        map<ll,ll> ansmap;
        current={great[0],notgreatest[sz-1].first,notgreatest[sz-1].second,notgreatest[sz-2].second,notgreatest[sz-2].first};
        cout<<"?";
        fur(i,0,5)cout<<" "<<current[i];
        cout<<endl;
        cin>>nd;
        cin>>rd;
        ansmap[nd]=great[0];
        ans=(ans^nd);
        current={great[1],notgreatest[sz-1].first,notgreatest[sz-1].second,notgreatest[sz-2].second,notgreatest[sz-2].first};
        cout<<"?";
        fur(i,0,5)cout<<" "<<current[i];
        cout<<endl;
        cin>>nd;
        cin>>rd;
        ans=(ans^nd);
        ansmap[nd]=great[1];
        current={great[2],notgreatest[sz-1].first,notgreatest[sz-1].second,notgreatest[sz-2].second,notgreatest[sz-2].first};
        cout<<"?";
        fur(i,0,5)cout<<" "<<current[i];
        cout<<endl;
        cin>>nd;
        cin>>rd;
        ansmap[nd]=great[2];
        ans=(ans^nd);
        cout<<"! "<<ansmap[ans]<<endl;
    }
    }


	return 0;
}
