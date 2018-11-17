#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
int rows;
int columns;
cin>>rows;
cin>>columns;
int consecutive;
vector<long> row(rows);
vector<long> column(columns);
cin>>consecutive;
long long ans=0;
for(int i=0;i<rows;i++){
	string s;
	cin>>s;
	for(int j=0;j<columns;j++){
	char c = s[j];
	if(c=='*'){
	if(row[i]<consecutive){
		row[i]=0;
	}else{
		ans += (row[i]-consecutive+1);
		row[i]=0;
	}
	if(column[j]<consecutive){
	       column[j]=0;
        }else{
              ans += (column[j]-consecutive+1);
	      column[j]=0;
        }
	}
	else if (c=='.'){
		row[i]++;
		column[j]++;
		if(i==rows-1){
		
	if(column[j]<consecutive){
		               column[j]=0;
			               }else{
					                     ans += (column[j]-consecutive+1);
							                   column[j]=0;
									           }
		}
		if(j==columns-1){
	if(row[i]<consecutive){
		                row[i]=0;
				        }else{
						                ans += (row[i]-consecutive+1);
								                row[i]=0;
										        }

		}
	}
	}
}
if(consecutive==1)
	cout<<ans/2<<endl;
	else
cout<<ans<<endl;
return 0;
}
