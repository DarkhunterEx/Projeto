#include<bits/stdc++.h>
using namespace std;
vector<int>c[1000000];
vector<int>o;
int d[1000000];

int ts(int n){
	priority_queue<int,vector<int>,greater<int>>a;
	for(int i=0;i<n;i++){
		if(d[i]==0){
			a.push(i);
		}
	}
	while(!a.empty()){
		int u=a.top();a.pop();
		o.push_back(u);
		for(int i=0;i<c[u].size();i++){
			d[c[u][i]]--;
			if(d[c[u][i]]==0) a.push(c[u][i]);
		}
	}
}

int main(){
	//freopen("12.txt","w",stdout);
	int a,b;
	cin>>a>>b;
	while(a!=0 or b!=0){
		o.clear();
		for(int i=0;i<1000000;i++){
		c[i].clear();
		d[i]=0;
		}
		for(int i=0;i<b;i++){
			int w,y;
			cin>>w>>y;
			w--;
			y--;
			c[w].push_back(y);
			d[y]=d[y]+1;
		}
		ts(a);
		for(int i=0;i<o.size();i++){
			cout<<o[i]+1<<endl;
		}
		cin>>a>>b;
	}
}
