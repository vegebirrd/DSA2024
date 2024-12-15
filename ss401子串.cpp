#include <iostream>
#include <cstring>
using namespace std;
bool check(string s,string t){
    int l1=s.length();
    int l2=t.length();
    int p=0;
    bool flag=true;
    for (int i=0;i<l1;i++){
        while (p<l2&&t[p]!=s[i]){
            p++;
        }
        if (p==l2) return false;
        p++;
    }
    return flag;
}
int main(){
    bool flag;
    string s,t;
    while (cin>>s>>t){
        flag=check(s,t);
        if (flag) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}