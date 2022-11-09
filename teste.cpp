#include <bits/stdc++.h>

using namespace std;

pair<long long int,string> a[65][65];
string s;
string x;

pair<long long int,string> ma(pair<long long int,string> b,pair<long long int,string> c){
    if(b.first>c.first)
    return b;
    if(b.first<c.first)
    return c;
    if(b.second>c.second)
    return c;
    return b;
}

pair<long long int,string>p(int l,int r){
    if(l==r){
        return make_pair(1,x=s[l]);
    }
    if(l==r+1){
        if(s[l]==s[r]){
            return make_pair(2,x=s[l]);
        }
        return make_pair(1,"");
    }
    pair<long long int,string>&ans=a[l][r];
    if(ans.first!=-1)
    return ans;
    ans.first=0;
    if(s[l]==s[r]){
        pair<long long int,string> t=p(l+1,r-1);
        string fi=(x=s[r])+p(l+1,r-1).second+(x=s[r]);
        //cout<<fi<<endl;
        return ans=make_pair(2+t.first,fi);
    }
    return ans=ma(p(l+1,r),p(l,r-1));
}

int main(){
    //freopen("12.txt","w",stdout);
    while(cin>>s){
        for(int i=0;i<65;i++){
            for(int j=0;j<65;j++){
                a[i][j]=make_pair(-1,"");
            }
        }
        cout<<p(0,s.size()-1).second<<endl;
    }
}
