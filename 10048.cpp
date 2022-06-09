#include <bits/stdc++.h>
using namespace std;
int b[106];
int acha(int n){
	if(n!=b[n]){
		return acha(b[n]);
	}
	return n;
}

int main(){
	//freopen("12.txt","w",stdout);
	int x,y,z;
	cin>>x>>y>>z;
	int zz=0;
	while(x!=0 or y!=0 or z!=0){
		zz++;
		if(zz>1){
			cout<<endl;
		}
		priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>> ,greater<pair<int,pair<int,int>>>>a;
		vector<pair<int,int>>v[106];
		int vi[106];
		for(int i=0;i<x+5;i++){
			v[i].clear();
			b[i]=i;
			vi[i]=false;
		}
		for(int i=0;i<y;i++){
			int c,d,e;
			cin>>c>>d>>e;
			a.push(make_pair(e,make_pair(c,d)));
		}
		while(!a.empty()){
			int c=acha(a.top().second.first);
			int d=acha(a.top().second.second);
			if(c!=d){
				b[c]=d;
				v[a.top().second.first].push_back(make_pair(a.top().second.second,a.top().first));
				v[a.top().second.second].push_back(make_pair(a.top().second.first,a.top().first));
			}
			a.pop();
		}
		cout<<"Case #"<<zz<<endl;
		for(int j=0;j<z;j++){
			int aa,bb;
			cin>>aa>>bb;
			for(int kk=0;kk<x+5;kk++){
			vi[kk]=false;
			}
			vi[aa]=true;
			queue<int>t;
			t.push(aa);
			int mm=-1;
			while(!t.empty() and t.front()!=bb){
				int yy=t.front();
				t.pop();
				for(int ll=0;ll<v[yy].size();ll++){
					cout<<v[yy][ll].first<<endl;
					if(vi[v[yy][ll].first]==false){
						vi[v[yy][ll].first]=true;
						if(v[yy][ll].second>mm){
							mm=v[yy][ll].second;
						}
						t.push(v[yy][ll].first);
					}
				}
			}
			if(vi[bb]==true){
				cout<<mm<<endl;
			}
			else{
				cout<<"no path"<<endl;
			}
		}
		cin>>x>>y>>z;
	}
}
