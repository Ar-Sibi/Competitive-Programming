#include<bits/stdc++.h>
using namespace std;
int main(){
    int r;
    int c;
    cin>>r>>c;
    vector<string>strings(r);
    for(int i=0;i<r;i++){
        cin>>strings[i];
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(strings[i][j]=='S'){
                if(i!=0){
                    if(strings[i-1][j]=='W'){
                        goto shit;           
                    }else{
                        strings[i-1][j]=((strings[i-1][j]=='.')?'D':strings[i-1][j]);
                    }
                }
                if(i!=r-1){
                    if(strings[i+1][j]=='W'){
                        goto shit;           
                    }else {

                        strings[i+1][j]=((strings[i+1][j]=='.')?'D':strings[i+1][j]);
                    }
                }
                if(j!=0){
                    if(strings[i][j-1]=='W'){
                        goto shit;           
                    }else{
                        strings[i][j-1]=((strings[i][j-1]=='.')?'D':strings[i][j-1]);
                    }
                }
                if(j!=c-1){
                    if(strings[i][j+1]=='W'){
                        goto shit;           
                    }else{
                        strings[i][j+1]=((strings[i][j+1]=='.')?'D':strings[i][j+1]);
                    }
                }
            }
        }
    }
    cout<<"Yes"<<endl;
    for(int i=0;i<r;i++){
        cout<<strings[i]<<endl;
    }
    return 0;
    shit:
    cout<<"No";
    return 0;
    return 0;
}