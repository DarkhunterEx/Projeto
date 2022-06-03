#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string a,b;
    cin>>a>>b;
    while(a!="0" or b!="0"){
        int g=0;
        int k=0;
        int j=b.size()-1;
        for(int i=a.size()-1;i>=0 or j>=0;){
            if(j>=0 and i>=0 and a[i]-48+b[j]-48+k>=10){
                g++;
                k=a[i]-48+b[j]+k-48-9;
            }
            else if(j>=0 and i<0 and b[j]-48+k>=10){
                g++;
                k=b[j]-48+k-9;
            }
            else if(i>=0 and j<0 and a[i]-48+k>=10){
                k=a[i]-48+k-9;
                g++;
            }
            else{
            k=0;
            }
            j--;
            i--;
        }
        cout<<g<<endl;
        cin>>a>>b;
    }
}
