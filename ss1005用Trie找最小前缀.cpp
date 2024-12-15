#include<iostream>
#include<vector>
#include<map>
#include<string>
using namespace std;
struct TrieNode{
    int cnt;
    map<char,TrieNode*> children;
    TrieNode():cnt(0){}
}; /*注意TrieNode内部不存char，char在边上*/
class Trie{
    public:
    TrieNode* root;
    Trie():root(new TrieNode()){}
    void insert(const string& s){
        TrieNode* current=root;
        for (const char c:s){
            if ((current->children).find(c)!=(current->children).end()){
                current=(current->children)[c];
                current->cnt++; /*更新时机很重要*/
            }
            else{
                TrieNode* tmp=new TrieNode();
                current->children[c]=tmp;
                current=(current->children)[c];
                current->cnt++;
            }
        }
    }
    string findPrefix(const string& s){
        TrieNode* current=root;
        string pfx;
        for (const char c:s){
            pfx+=c;
            current=current->children[c];
            if (current->cnt==1) return pfx;
        }
        return pfx;
    }
};
int main(){
    vector<string> v;
    string s;
    Trie* trie=new Trie();
    while (cin>>s){
        v.push_back(s);
        trie->insert(s);
    }
    int si=v.size();
    if (si==1) cout<<v[0]<<' '<<v[0]<<endl;
    else{
        for (const string& a:v){
            cout<<a<<' '<<trie->findPrefix(a)<<endl;
        }
    }
    delete(trie);
}