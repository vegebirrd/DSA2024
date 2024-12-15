#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
bool match(char a,char b){
    if (a==b||(a>='a'&&a<='z'&&b>='A'&&b<='Z'&&a-b==32)||(a>='A'&&a<='Z'&&b>='a'&&b<='z'&&b-a==32)){
        return true;
    }
    else return false;
}
bool check(const string& s,const string& p){
    int ls=s.length();
    int lp=p.length();
    int ptr=0;
    for (int i=0;i<ls;i++){
        if (ptr>=lp) return false;
        if(p[ptr]=='['){
            bool mch=false;
            ptr++;
            while(p[ptr]!=']'){
                if (p[ptr]==s[i]) mch=true;
                ptr++;
            }
            ptr++;
        }
        else if(!match(s[i],p[ptr])) return false;
        else{
            ptr++;
        }
    }
    if (ptr<lp) return false;
    return true;
}
int main(){
    int n;
    cin>>n;
    vector<string> v;
    string s;
    for (int i=0;i<n;i++){
        cin>>s;
        v.push_back(s);
    }
    string p;
    cin>>p;
    for (int i=0;i<n;i++){
        bool mch=check(v[i],p);
        if (mch) cout<<i+1<<' '<<v[i]<<endl;
    }
}