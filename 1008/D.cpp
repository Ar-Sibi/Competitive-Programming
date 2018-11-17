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
#define MAX 1000000

int factor[MAX] = { 0 };
 
// function to generate all prime factors
// of numbers from 1 to 10^6
void generatePrimeFactors()
{
    factor[1] = 1;
 
    // Initializes all the positions with their value.
    for (int i = 2; i < MAX; i++)
        factor[i] = i;
 
    // Initializes all multiples of 2 with 2
    for (int i = 4; i < MAX; i += 2)
        factor[i] = 2;
 
    // A modified version of Sieve of Eratosthenes to
    // store the smallest prime factor that divides
    // every number.
    for (int i = 3; i * i < MAX; i++) {
        // check if it has no prime factor.
        if (factor[i] == i) {
            // Initializes of j starting from i*i
            for (int j = i * i; j < MAX; j += i) {
                // if it has no prime factor before, then
                // stores the smallest prime divisor
                if (factor[j] == j)
                    factor[j] = i;
            }
        }
    }
}
 
// function to calculate number of factors
int calculateNoOFactors(int n)
{
    if (n == 1)
        return 1;
 
    int ans = 1;
 
    // stores the smallest prime number
    // that divides n
    int dup = factor[n];
 
    // stores the count of number of times
    // a prime number divides n.
    int c = 1;
 
    // reduces to the next number after prime
    // factorization of n
    int j = n / factor[n];
 
    // false when prime factorization is done
    while (j != 1) {
        // if the same prime number is dividing n,
        // then we increase the count
        if (factor[j] == dup)
            c += 1;
 
        /* if its a new prime factor that is factorizing n, 
           then we again set c=1 and change dup to the new 
           prime factor, and apply the formula explained 
           above. */
        else {
            dup = factor[j];
            ans = ans * (c + 1);
            c = 1;
        }
 
        // prime factorizes a number
        j = j / factor[j];
    }
 
    // for the last prime factor
    ans = ans * (c + 1);
 
    return ans;
}

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	generatePrimeFactors();
	ll testcases;
	cin>>testcases;
	while(testcases--){
		vector<ll> v=vector<ll>(3);
		cin>>v[0]>>v[1]>>v[2];
		sort(v.begin(),v.end());
		ll a=calculateNoOFactors(v[2]);
		ll b=calculateNoOFactors(v[1]);
		ll c=calculateNoOFactors(v[0]);
		cout<<a<<"  "<<b<<"  "<<c<<endl;
		ll count=0;
		count+=a*b*c;
		b--;
		c--;
		v[2]/=__gcd(v[2],v[1]);
		v[2]/=__gcd(v[2],v[0]);
		a=calculateNoOFactors(v[2]);
		a--;
		count+=a*b*c;
		v[1]/=__gcd(v[0],v[1]);
		b=calculateNoOFactors(v[1]);
		b--;
		count+=a*b*c;
		cout<<endl<<count<<endl;
	}
	

	
	return 0;
}
