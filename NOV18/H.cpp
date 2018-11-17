#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vll;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;
typedef pair<string,ll> psl;
typedef vector<psl> vpsl;
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

ll max(ll a,ll b){
	return a>b?a:b;
}
ll min(ll a,ll b){
	return a<=b?a:b;
}
string addBinary(string a, string b) 
{ 
    string result = ""; // Initialize result 
    int s = 0;          // Initialize digit sum 
  
    // Travers both strings starting from last 
    // characters 
    int i = a.size() - 1, j = b.size() - 1; 
    while (i >= 0 || j >= 0 || s == 1) 
    { 
        // Comput sum of last digits and carry 
        s += ((i >= 0)? a[i] - '0': 0); 
        s += ((j >= 0)? b[j] - '0': 0); 
  
        // If current digit sum is 1 or 3, add 1 to result 
        result = char(s % 2 + '0') + result; 
  
        // Compute carry 
        s /= 2; 
  
        // Move to next digits 
        i--; j--; 
    } 
    return result; 
}
bool isSmaller(string str1, string str2) 
{ 
    // Calculate lengths of both string 
    int n1 = str1.length(), n2 = str2.length(); 
  
    if (n1 < n2) 
        return true; 
    if (n2 > n1) 
        return false; 
  
    for (int i=0; i<n1; i++) 
    { 
        if (str1[i] < str2[i]) 
            return true; 
        else if (str1[i] > str2[i]) 
            return false; 
    } 
    return false; 
} 
string xOr(string a,string b){
    string c="";
    if(b.length()>a.length()){
        string temp=b;
        b=a;
        a=temp;
    }
    fur(i,0,max(a.length(),b.length())){
        c=c+"0";
    }
    fur(i,0,max(a.length(),b.length())){
        c[i]=(a[i]!=b[i]?'1':'0');
    }
    return c;
}
// Function for finding difference of larger numbers 
string findDiff(string str1, string str2) 
{ 
    // Before proceeding further, make sure str1 
    // is not smaller 
    if (isSmaller(str1, str2)) 
        swap(str1, str2); 
  
    // Take an empty string for storing result 
    string str = ""; 
  
    // Calculate lengths of both string 
    int n1 = str1.length(), n2 = str2.length(); 
    int diff = n1 - n2; 
  
    // Initially take carry zero 
    int carry = 0; 
  
    // Traverse from end of both strings 
    for (int i=n2-1; i>=0; i--) 
    { 
        // Do school mathematics, compute difference of 
        // current digits and carry 
        int sub = ((str1[i+diff]-'0') - 
                   (str2[i]-'0') - 
                   carry); 
        if (sub < 0) 
        { 
            sub = sub+10; 
            carry = 1; 
        } 
        else
            carry = 0; 
  
        str.push_back(sub + '0'); 
    } 
  
    // subtract remaining digits of str1[] 
    for (int i=n1-n2-1; i>=0; i--) 
    { 
        if (str1[i]=='0' && carry) 
        { 
            str.push_back('9'); 
            continue; 
        } 
        int sub = ((str1[i]-'0') - carry); 
        if (i>0 || sub>0) // remove preceding 0's 
            str.push_back(sub+'0'); 
        carry = 0; 
  
    } 
  
    // reverse resultant string 
    reverse(str.begin(), str.end()); 
  
    return str; 
}
int getMid(int s, int e) {  return s + (e -s)/2;  } 
   
/*  A recursive function to get the xor of values in given range 
    of the array. The following are parameters for this function. 
   
    st    --> Pointer to segment tree 
    si    --> Index of current node in the segment tree. Initially 
              0 is passed as root is always at index 0 
    ss & se  --> Starting and ending indexes of the segment 
                 represented by current node, i.e., st[si] 
    qs & qe  --> Starting and ending indexes of query range */
string getXorUtil(string *st, int ss, int se, int qs, int qe, int si) 
{ 
    // If segment of this node is a part of given range, then return 
    // the xor of the segment 
    if (qs <= ss && qe >= se) 
        return st[si]; 
   
    // If segment of this node is outside the given range 
    if (se < qs || ss > qe) 
        return 0; 
   
    // If a part of this segment overlaps with the given range 
    int mid = getMid(ss, se); 
    return xOr(getXorUtil(st, ss, mid, qs, qe, 2*si+1) ,
           getXorUtil(st, mid+1, se, qs, qe, 2*si+2)); 
} 
   
/* A recursive function to update the nodes which have the given  
   index in their range. The following are parameters 
    st, si, ss and se are same as getXorUtil() 
    i    --> index of the element to be updated. This index is  
             in input array. 
   diff --> Value to be added to all nodes which have i in range */
void updateValueUtil(string *st, int ss, int se, int i, string diff, int si) 
{ 
    // Base Case: If the input index lies outside the range of  
    // this segment 
    if (i < ss || i > se) 
        return; 
   
    // If the input index is in range of this node, then update  
    // the value of the node and its children 
    st[si] = addBinary(st[si] , diff); 
    if (se != ss) 
    { 
        int mid = getMid(ss, se); 
        updateValueUtil(st, ss, mid, i, diff, 2*si + 1); 
        updateValueUtil(st, mid+1, se, i, diff, 2*si + 2); 
    } 
} 

// The function to update a value in input array and segment tree. 
// It uses updateValueUtil() to update the value in segment tree 
void updateValue(string arr[], string *st, int n, int i, string new_val) 
{ 
    // Check for erroneous input index 
    if (i < 0 || i > n-1) 
    { 
        printf("Invalid Input"); 
        return; 
    } 
   
    // Get the difference between new value and old value 
    string diff =findDiff(new_val , arr[i]); 
   
    // Update the value in array 
    arr[i] = new_val; 
   
    // Update the values of nodes in segment tree 
    updateValueUtil(st, 0, n-1, i, diff, 0); 
} 
   
// Return xor of elements in range from index qs (quey start) 
// to qe (query end).  It mainly uses getXorUtil() 
string getXor(string *st, int n, int qs, int qe) 
{ 
    // Check for erroneous input values 
    if (qs < 0 || qe > n-1 || qs > qe) 
    { 
        printf("Invalid Input"); 
        return "-1"; 
    } 
   
    return getXorUtil(st, 0, n-1, qs, qe, 0); 
} 
   
// A recursive function that constructs Segment Tree for array[ss..se]. 
// si is index of current node in segment tree st 
string constructSTUtil(string arr[], int ss, int se, string *st, int si) 
{ 
    // If there is one element in array, store it in current node of 
    // segment tree and return 
    if (ss == se) 
    { 
        st[si] = arr[ss]; 
        return arr[ss]; 
    } 
   
    // If there are more than one elements, then recur for left and 
    // right subtrees and store the xor of values in this node 
    int mid = getMid(ss, se); 
    st[si] =  xOr(constructSTUtil(arr, ss, mid, st, si*2+1) ,
              constructSTUtil(arr, mid+1, se, st, si*2+2)); 
    return st[si];
}
   
/* Function to construct segment tree from given array. This function 
   allocates memory for segment tree and calls constructSTUtil() to 
   fill the allocated memory */
string *constructST(string arr[], int n) 
{ 
    // Allocate memory for segment tree 
   
    //Height of segment tree 
    int x = (int)(ceil(log2(n)));  
   
    //Maximum size of segment tree 
    int max_size = 2*(int)pow(2, x) - 1;  
   
    // Allocate memory 
    string *st =  (string *)malloc(sizeof(int)*max_size); 
   
    // Fill the allocated memory st 
    constructSTUtil(arr, 0, n-1, st, 0); 
   
    // Return the constructed segment tree 
    return st; 
}

int main(){
   ll n,q;
   cin>>n>>q;
   string arr[n];
   fur(i,0,n){
       cin>>arr[i];
   }
   string* ptr=constructST(arr,n);
   while(q--){
       
   }
}