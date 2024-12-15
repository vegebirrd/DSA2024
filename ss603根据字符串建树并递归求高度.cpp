#include <iostream>
#include <vector>
#include <stack>
using namespace std;
//美观版见603.cpp
struct treeNode{
    vector<treeNode*> child;
    treeNode* rightSibling;
};
int treeHeight(treeNode* t){
    int maxH=0;
    if (t==nullptr) return 0; //空树
    for (treeNode* c: t->child){
        int subtreeHeight=treeHeight(c);
        if (subtreeHeight>maxH) maxH=subtreeHeight;
    }
    return 1+maxH;
}
int binaryHeight(treeNode* t){
    if (t==nullptr) return 0;
    int leftH=0,rightH=0;
    if (t->child.empty()) leftH=0; //没有孩子
    else {
        treeNode* leftMostChild=t->child[0];
        leftH=binaryHeight(leftMostChild); //左子树高度
    }
    rightH=binaryHeight(t->rightSibling); //右子树高度
    if (leftH>rightH) return 1+leftH;
    else return 1+rightH;
}
treeNode* buildtree(const string& s){
    treeNode* root=new treeNode();
    treeNode* lastone; //上一个从栈里面弹出的节点，设置右兄弟的时候用
    bool setrs=false; //标记位，设不设置右兄弟
    stack<treeNode*> stk;
    stk.push(root);
    for (char c: s){
        if (c=='d'){
            treeNode* r=new treeNode();
            stk.top()->child.push_back(r);
            if (lastone!=nullptr&&setrs) lastone->rightSibling=r;
            setrs=false;
            stk.push(r);
        }
        else{
            lastone=stk.top();
            stk.pop();
            setrs=true;
        }
    }
    return root;
}
void deletetree(treeNode* t) {
    if (t == nullptr) return;
    for (treeNode* c : t->child) {
        deletetree(c);
    }
    delete t;
}
int main(){
    string s;
    int c=0;
    while(cin>>s){
        c++;
        if (s=="#") break;
        else{
            treeNode* tree=buildtree(s);
            int h=treeHeight(tree);
            int bh=binaryHeight(tree);
            cout<<"Tree "<<c<<": "<<h-1<<" => "<<bh-1<<endl;
            deletetree(tree);
        }
    }
}