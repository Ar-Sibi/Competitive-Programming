#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	unordered_map<long long,long long> rowmap;
	unordered_map<long long,long long> columnmap;
	long long n;
	long long m;
	long long rows=0;
	long long columns=0;
	cin>>n>>m;
	long long rowsoccupied=n*n;
	for(long long i=0;i<m;i++){
		long long x;
		long long y;
		cin>>x>>y;
		long long rowcount=0;
		long long columncount=0;
		if(rowmap[x]==0){
			rowcount = n-rows;
		}
		if(columnmap[y]==0){
			columncount = n-columns;
		}
		if(rowcount==0&&columncount==0){
			cout<<rowsoccupied<<(i<m-1?" ":"");
		}else{
			if(rowcount==0||columncount==0){
				if(rowcount){
					rowsoccupied-=rowcount;
					columns++;
					cout<<rowsoccupied<<(i<m-1?" ":"");
				}
				if(columncount){
					rowsoccupied-=columncount;
					rows++;
					cout<<rowsoccupied<<(i<m-1?" ":"");
				}
			}else{
				columns++;
				rows++;
				rowsoccupied-=rowcount+columncount-1;
				cout<<rowsoccupied<<(i<m-1?" ":"");
			}
			rowmap[x]=1;
			columnmap[y]=1;
		}
		//cout<<"T"<<rows<<"T"<<endl<<columns<<endl;
	}	
	return 0;
}
