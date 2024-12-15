#include <iostream>
#include <vector>
using namespace std;
class UnionFind {
public:
    vector<int> gang; //并查集，每个元素是其父亲结点
    vector<int> diff; //记录是不是不同
    UnionFind(int n) : gang(n + 1), diff(n + 1, -1){
        for (int i = 1; i <= n; i++) {
            gang[i] = i; // 初始化时每个节点的父节点为自身
        }
    }
    int find(int i){
        if(gang[i]!=i){
            gang[i]=find(gang[i]);
        }
        return gang[i];
    }
    void iunion(int i,int j){
        int rj=find(j);
        int ri=find(i);
        if (ri!=rj) gang[rj]=ri;
    }
    void setdiff(int i,int j){
        int rooti=find(i);
        int rootj=find(j);
        if (diff[rooti]==-1) diff[rooti]=rootj;
        else iunion(diff[rooti],rootj);
        if (diff[rootj]==-1) diff[rootj]=rooti;
        else iunion(diff[rootj],rooti);
    }
};
int main(){
    int t;
    cin>>t;
    char a;
    int n,m;
    int x,y;
    for (int k=0;k<t;k++){
        cin>>n>>m;
        UnionFind uf(n);
        for (int i=0;i<m;i++){
            cin>>a>>x>>y;
            if (a=='D'){
                uf.setdiff(x,y);
            }
            else{
                int rootx=uf.find(x);
                int rooty=uf.find(y);
                if ((uf.diff[rootx] != -1 && uf.find(uf.diff[rootx]) == rooty) ||
                    (uf.diff[rooty] != -1 && uf.find(uf.diff[rooty]) == rootx)) cout<<"In different gangs."<<endl;
                //注意这个判断！！！
                else if (rootx==rooty) cout<<"In the same gang."<<endl;
                else cout<<"Not sure yet."<<endl;
            }
        }
    }
}