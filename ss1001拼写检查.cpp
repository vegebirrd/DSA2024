//注意C++ string类没有strlen，要用length()函数
#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<string> dict;
bool delete_one(string a,string b){
    if (a.length()==b.length()-1){
        int l=b.length();
        for (int i=0;i<l;i++){
            string tmp=b.substr(0,i)+b.substr(i+1,l);
            if (tmp==a) return true;
        }
        return false;
    }
    else if (b.length()==a.length()-1){
        int l=a.length();
        for (int i=0;i<l;i++){
            string tmp=a.substr(0,i)+a.substr(i+1,l);
            if (tmp==b) return true;
        }
        return false;
    }
    return false;
}
bool replace_one(string a, string b){
    if (a.length()==b.length()){
        int diff=0;
        int l=a.length();
        for (int i=0;i<l;i++){
            if (a[i]!=b[i]) diff++;
            if (diff>1) return false;
        }
        if (diff==1) return true;
    }
    return false;
}
int main(){
    string s;
    while (cin>>s){
        if(s=="#") break;
        else{
            dict.push_back(s);
        }
    }
    while (cin>>s){
        if(s=="#") break;
        else{
            vector<string> similar;
            bool flag=false;
            for (string w:dict){
                if (s==w){
                    cout<<s<<" is correct"<<endl;
                    flag=true;
                    break;
                }
                else{
                    if(replace_one(s,w)||delete_one(s,w)){
                        similar.push_back(w);
                    }
                }
            }
            if(!flag){
                cout<<s<<":";
                for (string i:similar){
                    cout<<' '<<i;
                }
                cout<<endl;
            }
        }
    }
}