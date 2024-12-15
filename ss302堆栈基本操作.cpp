#include <iostream>
#include <stack>
#include <vector>
#include <cstring>
using namespace std;
int a[1000000];
int main(){
    int n;
    bool flag=true;
    cin>>n;
    stack<int> s;
    vector<string> ops;
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    int current=1;
    for (int i=0;i<n;i++){
        int tmp=a[i];
        if (tmp>n){
            cout<<"NO";
            flag=false;
            break;
        }
        while (tmp>=current){
            s.push(current);
            ops.push_back("PUSH "+to_string(current));
            current++;
        }
        if (s.empty()){
            cout<<"NO";
            flag=false;
            break;
        }
        if (tmp==s.top()){
            s.pop();
            ops.push_back("POP "+to_string(tmp));
        }
        else {
            cout<<"NO";
            flag=false;
            break;
        }
    }
    if (flag){
        for (size_t i=0;i<ops.size();i++){
            cout<<ops[i];
            if (i!=ops.size()-1) cout<<endl;
        }
    }
}