#include <bits/stdc++.h>
using namespace std;
#define Mid (l + ((r - l) >> 1))
typedef int no;
//Lucas G
no Seg[4*1000005];
int Vet[1000005], n=1000005;

no Modify(no a, no b){
    return a + b;
}

no build(int l = 0, int r = n - 1, int id = 1){
    if (l == r)
        return Seg[id] = Vet[l];
    return Seg[id] = Modify(build(l, Mid, 2 * id), build(Mid + 1, r, 2 * id + 1));
}

no query(int i, int j, int l = 0, int r = n - 1, int id = 1){
    if (i > r || j < l) return 0;
    if (i <= l && j >= r) return Seg[id];
    return Modify(query(i, j, l, Mid, 2 * id), query(i, j, Mid + 1, r, 2 * id + 1));
}

void upd(int i, int x, int l = 0, int r = n - 1, int id = 1){
    if (l > r) return;
    if (l == r){ Seg[id] = x; return; }
    if (i <= Mid) upd(i, x, l, Mid, 2 * id);
    else upd(i, x, Mid + 1, r, 2 * id + 1);
    Seg[id] = Modify(Seg[2 * id], Seg[2 * id + 1]);
}

int main(){
	string g;
	bool podp;
	cin>>g;
	int r=0;
	int nn=0;
	for(int i=0;i<g.size();i++){
        if(g[i]==')'){
            nn--;
            if(nn>=0)
            Vet[i]=-1;
            else{
                nn=0;
                Vet[i]=1;
            }
        }
        if(g[i]=='('){
            nn++;
            Vet[i]=1;
        }
        //cout<<endl<<Vet[i]<<" "<<nn<<endl;
	}
	build();
	int k;
	cin>>k;
	for(int i=0;i<k;i++){
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        while(Vet[a]==-1 and a<b){
            a++;
        }
        int l=query(a,b);
        if(a!=b)
        cout<<b-a+1-abs(l)<<endl;
        else{
            cout<<"0"<<endl;
        }
	}
}
