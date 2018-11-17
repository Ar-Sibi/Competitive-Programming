#include<bits/stdc++.h>
using namespace std;
int max(int x,int y){
    return x>y?x:y;
}
long long pow(int x){
    return 1LL*x*x;
}
int main(){
    int r;
    int c;
    cin>>r;
    cin>>c;

    int rows=r;
    int columns=c;
    vector<string> mat(rows);
    for(int i=0;i<rows;i++)
        {
            string str;
            cin>>str;
            mat[i]=str;
        }
    long long s=0;
    long reqw=-1;
    long reqh=-1;
    int xst=-1;
    int yst=1000;
    int lastx=-1;
    int lasty=-1;
    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            if(mat[i][j]=='B'){
                if(xst==-1){
                    xst=i;
                } 
                if(yst>j){
                    yst=j;
                }
                s++;
                lasty=i;
                if(lastx<j)
                    lastx=j;
            }
        }
    }
    if(lastx-yst+1>rows){
        cout<<-1;
        return 0;    
    }
    if(lasty-xst+1>columns){
        cout<<-1;
        return 0;    
    }
    cout<<pow(max((lastx-yst),(lasty-xst))+1)-s;
    return 0;
}