#include <iostream>
#include <string>

using namespace std;

long c(int m,int n){
    long a=1;
    for (int i=1;i<=n;i++){
        a*=(m-i+1);
    }
    for (int i=1;i<=n;i++){
        a/=i;
    }
    return a;
}
int treenum(int m,const string& pre,const string& post,int pre_s,int pre_e,int post_s,int post_e){
    if (pre_s==pre_e) return 1;
    char root=pre[pre_s];
    int new_pre_s=pre_s+1;
    int new_pre_e=pre_e;
    int new_post_s=post_s;
    int new_post_e=post_e-1;
    int sub_tree=0;
    int total_tree=1;
    while (new_post_s<=new_post_e){
        int cnt=0;
        while (post[new_post_s]!=pre[new_pre_s]){
            cnt++;
            new_post_s++;
        }
        sub_tree++;
        total_tree*=treenum(m,pre,post,new_pre_s,new_pre_s+cnt,post_s,new_post_s);
        post_s=new_post_s+1;
        new_post_s++;
        new_pre_s=new_pre_s+cnt+1;
    }
    total_tree*=c(m,sub_tree);
    return total_tree;
}
int main(){
    string pre,post;
    int m;
    while (true){
        cin>>m;
        if (m==0) break;
        cin>>pre>>post;
        int l=pre.size();
        cout<<treenum(m,pre,post,0,l-1,0,l-1)<<endl;
    }
}