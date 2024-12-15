//复习本题的时候注意图的存储方式是邻接表存储。注意Vector的使用方法，特别是遍历。
#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <queue>
#include <string>
using namespace std;
int getindex(char a){
    return a-'A';
}
class Edge {
public:
    int v;
	int length;
    bool vst;
    bool operator<(const Edge& other) const {
        return length > other.length;
    }
    Edge(int a=0, int c=0, bool visit=false):v(a),length(c),vst(false){};
};
// 使用邻接表存储图
vector<vector<Edge>> adj;
int prim(int en,int vn){
    vector<bool> visited(vn, false); // 标记节点是否访问
    int cnt=1;
    int minlen=0;
    priority_queue<Edge> pq;
    for (const Edge& e : adj[0]){
        pq.push(e);
    }
    visited[0]=1;
    while (cnt!=vn){
        Edge tmp=pq.top();
        pq.pop();
        if (!visited[tmp.v]){
            visited[tmp.v]=true;
            cnt++;
            minlen+=tmp.length;
            for (const Edge& e : adj[tmp.v]) {
                if (!visited[e.v]) {
                    pq.push(e);
                }
            }
        }
    }
    return minlen;
}
int main(){
    int n;
    cin>>n;
    int m;
    int l;
    int edge_num=0;
    char a;
    adj.resize(n);
    for (int i=0;i<n-1;i++){
        cin>>a>>m;
        for (int j=0;j<m;j++){
            cin>>a>>l;
            int index=getindex(a);
            adj[i].push_back(Edge(index,l));
            adj[index].push_back(Edge(i,l));
            edge_num++;
        }
    }
    cout<<prim(edge_num,n)<<endl;
}