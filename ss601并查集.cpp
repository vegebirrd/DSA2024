#include <iostream>
using namespace std;
int reli[60000];
int find(int i){
    if(reli[i]==0){
        return i;
    }
    reli[i]=find(reli[i]);
    return reli[i];
}
int main(){
    int n,m;
    int num;
    int cnt=0;
    while (cin>>n>>m){
        cnt++;
        num=n;
        if (n==0 && m==0) break;
        int a,b;
        for (int i=0;i<=n;i++){
            reli[i]=0;
        }
        for (int i=0;i<m;i++){
            cin>>a>>b;
            int aa=find(a);
            int bb=find(b);
            if (aa!=bb){
                num--;
                reli[aa]=bb;
            }
        }
        cout<<"Case "<<cnt<<": "<<num<<endl;
    }
}