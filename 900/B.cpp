#include<bits/stdc++.h>
using namespace std;
int main(){
    int nr;
    int dr;
    int f;
    cin>>nr>>dr>>f;
    nr=nr%dr;
    for(int i=0;i<dr;i++){
        int x = nr *10;
        if(x/dr==f){
            cout<<i+1;
            return 0;
        }
        nr = x %dr;
    }
    cout<<-1;
    return 0;
}