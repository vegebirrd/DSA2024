#include <iostream>
#include <cstring>
using namespace std;
char str[1000005];
int nxt[1000000];
int f(string s){
    int l=s.length();
    nxt[0]=-1;
    nxt[1]=0;
    for (int i=2;i<=l;i++){
        int k=nxt[i-1];
        if (s[i-1]==s[k]) nxt[i]=k+1;
        else{
            while (s[i-1]!=s[k]&&k!=-1){
                k=nxt[k];
            }
            nxt[i]=k+1;
        }
    }
    return nxt[l];
}
int main(){
    while (true){
        scanf("%s",str);
        if (str[0]=='.'&&str[1]=='\0') break;
        string s(str);
        int x=f(s);
        int l=s.length();
        if (l%(l-x)==0) cout<<(l/(l-x))<<endl;
        else cout<<1<<endl;
    }
}