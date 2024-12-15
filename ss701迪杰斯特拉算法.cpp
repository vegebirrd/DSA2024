//复习本题的时候要注意Dist类的用途以及各种数据结构的使用，比如priority_queue如何作为最小堆。图的表示：邻接矩阵。
#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <queue>
#include <string>
using namespace std;
unordered_map<string, int> location_map;
string locations[30]; //序号和地点字符串的映射
int d[30][30];
class Dist {
public:
    int index;   	// 顶点的索引值，仅Dijkstra算法用到
	int length; 	// 当前最短路径长度
	int pre;      	// 路径最后经过的顶点
    bool operator<(const Dist& other) const {
        return length > other.length;
    }
    Dist(int a=0,int b=0, int c=0):index(a),length(b),pre(c){};
};
void dijkstra(int stt, int end,int p){
    priority_queue<Dist> pq;
    Dist di[p];
    for (int i=0;i<p;i++){
        di[i].index=i;
        di[i].length=10000000;
        di[i].pre=stt;
    }
    di[stt].length=0;
    pq.push(di[stt]);
    while (!pq.empty()){
        Dist tmp=pq.top();
        pq.pop();
        int idx=tmp.index;
        if (idx==end) break;
        for (int i=0;i<p;i++){
            if (d[idx][i]!=-1){
                if (d[idx][i]+di[idx].length<di[i].length){
                    di[i].length=d[idx][i]+di[idx].length;
                    di[i].pre=idx;
                    pq.push(di[i]);
                }
            }
        }
    }
    int tmp=end;
    stack<int> path;
    while(tmp!=stt){
        path.push(tmp);
        tmp=di[tmp].pre;
    }
    path.push(stt);
    cout<<locations[stt];
    while (!path.empty()){
        int i=path.top();
        path.pop();
        if (path.empty()) break;
        int j=path.top();
        cout<<"->("<<d[i][j]<<")->"<<locations[j];
    }
    cout<<endl;
}
int main(){
    for (int i=0;i<30;i++){
        for (int j=0;j<30;j++){
            if (i==j) d[i][j]=0;
            else d[i][j]=-1;
        }
    }
    int p,q,r;
    cin>>p;
    string s;
    for (int i=0;i<p;i++){
        cin>>s;
        locations[i]=s;
        location_map[s]=i;
    }
    cin>>q;
    string s1,s2;
    int le;
    for (int i=0;i<q;i++){
        cin>>s1>>s2>>le;
        int j=location_map[s1];
        int k=location_map[s2];
        d[j][k]=le;
        d[k][j]=le;
    }
    cin>>r;
    for (int i=0;i<r;i++){
        cin>>s1>>s2;
        int stt=location_map[s1];
        int end=location_map[s2];
        dijkstra(stt,end,p);
    }
}