#include <bits/stdc++.h>

using namespace std;
vector<int>a[1000000];
bool A[1000000];
int main(){
    int z;
    cin>>z;
    int l=0;
    while(z!=0){
		for(int i=0;i<1000000;i++){
			a[i].clear();
		}
		int k=0;
		for(int i=0;i<z;i++){
			int b,c;
			cin>>b>>c;
			if(a[b].size()==0){
				k++;
			}
			if(a[c].size()==0){
				k++;
			}
			a[b].push_back(c);
			a[c].push_back(b);
		}
		int w,y;
		cin>>w>>y;
		while(w!=0 or y!=0){
			l++;
			queue<pair<int,int> >b;
			
			for(int i=0;i<1000000;i++){
				A[i]=false;
			}
			b.push(make_pair(w,0));
			A[w]=true;
			int f=1;
			while(!b.empty() and b.front().second<y){
				pair<int,int>B=b.front();
				b.pop();
				for(int i=0;i<a[B.first].size();i++){
					if(A[a[B.first][i]]==false){
						A[a[B.first][i]]=true;
						b.push(make_pair(a[B.first][i],B.second+1));
						f++;
					}
				}
			}
			cout<<"Case "<<l<<": "<<k-f<<" nodes not reachable from node "<<w<<" with TTL = "<<y<<'.'<<endl;
			cin>>w>>y;
		}
		cin>>z;
	}
}
