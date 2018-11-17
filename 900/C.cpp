#include<bits/stdc++.h>
#include<unordered_map>
#define maxn 100200

using namespace std;
int a[maxn],x[maxn],y[maxn],n,k,cnt[maxn];

int main(){
    /*unordered_map<int,int> rmposs;
    int q;
    cin>>q;
    vector<int> vals(q+1);
    vals[q]=INT_MAX;
    for(int i=0;i<q;i++){
        cin>>vals[i];
    }
    if(q==1){
        cin>>q;
        cout<<q;
        return 0;
    }
    int maxlast;
    int maxnow;
    int l=vals[0];
    bool last = false;
    bool flag = vals[1]>vals[0];
    for(int i=1;i<vals.size()-1;i++){
        int x;
        x=vals[i];
        if(x>l){
            if(!flag){
            }else{
                rmposs[l]++;
            }
            l=x;
            flag=false;
        }else{
            if(vals[i+1]>vals[i]&&!flag)
            rmposs[l]++;
            else {
            flag=true;
            }
        }
    }
    if(!flag){
                
            }else{
                rmposs[l]++;
            }
    int maxval=rmposs[vals[0]];
    int max=vals[0];
    for(int i=0;i<vals.size();i++){
        if(rmposs[vals[i]]>maxval){
            maxval=rmposs[vals[i]];
            max=vals[i];
        }
    }
    if(maxval<=1)
    cout<<1;
    else
    cout<<max;
    return 0;*/
    scanf("%d",&n);for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    memset(x,0,sizeof(x));memset(y,0,sizeof(y));
    for (int i=1;i<=n;i++)
    {
        x[i]=x[i-1];y[i]=y[i-1];
        if (a[i]>x[i]) y[i]=x[i],x[i]=a[i];
        else if (a[i]>y[i]) y[i]=a[i];
    }
    for(int i=0;i<n;i++){
        cout<<y[i]<<endl;
    }
    memset(cnt,0,sizeof(cnt));
    for (int i=1;i<=n;i++) if (y[i]==a[i]) cnt[x[i]]++;
    k=1;for (int i=2;i<=n;i++) if (cnt[i]>cnt[k]) k=i;
    printf("%d\n",k);return 0;

}