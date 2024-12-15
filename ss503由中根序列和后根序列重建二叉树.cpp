#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct treenode{
    int val;
    treenode* left;
    treenode* right;
    treenode(int x): val(x),left(nullptr),right(nullptr){}
};

treenode* buildtree(vector<int> mid,vector<int> post){
    int s=post.size();
    if (s==0) return nullptr;
    treenode* root = new treenode(post[s-1]);
    int p;
    for (int i=0;i<s;i++){
        if (mid[i]==post[s-1]){
            p=i;
        }
    }
    vector<int> leftmid,leftpost,rightmid,rightpost;
    for (int i=0;i<p;i++){
        leftmid.push_back(mid[i]);
        leftpost.push_back(post[i]);
    }
    for (int i=p+1;i<s;i++){
        rightmid.push_back(mid[i]);
        rightpost.push_back(post[i-1]);
    }
    root->left=buildtree(leftmid,leftpost);
    root->right=buildtree(rightmid,rightpost);
    return root;
}

vector<int> result;

void pre_traversal(treenode* root){
    stack<treenode*> s;
    treenode* pointer=root;
    s.push(nullptr);
    while (pointer){
        result.push_back(pointer->val);
        if (pointer->right!=nullptr){
            s.push(pointer->right);
        }
        if (pointer->left!=nullptr){
            pointer=pointer->left;
        }
        else {
            pointer=s.top();
            s.pop();
        }
    }
}
int main(){
    int x;
    int l;
    vector<int> all,mid,post;
    while(cin>>x){
        all.push_back(x);
    }
    l=all.size();
    for (int i=0;i<l/2;i++){
        mid.push_back(all[i]);
    }
    for (int i=l/2;i<l;i++){
        post.push_back(all[i]);
    }
    treenode* t=buildtree(mid,post);
    pre_traversal(t);
    for (int i=0;i<l/2;i++){
        cout<<result[i];
        if (i!=l/2-1) cout<<' ';
    }
}