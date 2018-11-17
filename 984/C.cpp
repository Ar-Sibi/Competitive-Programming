#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

#define fur(i,a,b) for(int (i)=(a);i<(b);++(i))
#define revf(i,a,b) for(int (i)=(a)-1;(i)>=(b);--(i))
#define mp make_pair
#define mod 1000000007
#define inf 2000000007
#define pb push_back
#define eps 1e-5
#define X first
#define Y second

ll ipow(ll base, ll exp)
{
    ll result = 1;
    for (;;)
    {
        if (exp & 1)
            result *= base;
        exp >>= 1;
        if (!exp)
            break;
        base *= base;
    }

    return result;
}

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int queries;
	cin>>queries;
	
	while(queries--){
		ll nr,dr,base,val;
		cin>>nr>>dr>>base;
		long double val2 = log10l(base);
		dr/=__gcd(nr,dr);
		val = ipow(base,floor(log10l(1000000000000000000)/val2));
		while(val%dr!=0){
			if(__gcd((ll)dr,val)!=1){
				ll val4 = __gcd((ll)dr,val);
				ipow(val4,floor(log10l(1000000000000000000)/log10l(val4)));
			dr/=__gcd((ll)dr,ipow(val4,floor(log10l(1000000000000000000)/log10l(val4))));
			}
			else{
				cout<<"Infinite"<<endl;
				break;
			}
		}
		if(val%dr==0){
			cout<<"Finite"<<endl;
		}
	}

	
	return 0;
}
