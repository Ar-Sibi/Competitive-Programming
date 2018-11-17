#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio( false );
    cin.tie(NULL);
    char a[4];
    a[0]='<';
    a[1]='^';
    a[2]='>';
    a[3]='v';
    int l;
    int r;
    char x,y;
    cin>>x;
    cin>>y;
    long long t;
    cin>>t;
    for(int i=0;i<4;i++)
    if(a[i]==x)
    l=i;
    for(int i=0;i<4;i++)
    if(a[i]==y)
    r=i;
    int diff=r-l;
    t%=4;
    if(t%2==0){
        cout<<"undefined";
        return 0;
    }else{
        if(((l+t)%4)==r){
            cout<<"cw";
            return 0;
        }else if(((4+l-t)%4)==r){
            cout<<"ccw";
            return 0;
        }else{
            cout<<"undefined";
            return 0;
        }
    }
        
}