#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main(){
    int t;
    cin>>t;
    for (int i=0;i<t;i++){
        int n;
        cin>>n;
        int x;
        int wl=0;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int j=0;j<n;j++){
            cin>>x;
            pq.push(x);
        }
        int a,b;
        while(pq.size()>1){
            a=pq.top();
            pq.pop();
            b=pq.top();
            pq.pop();
            wl+=a;
            wl+=b;
            x=a+b;
            pq.push(x);
        }
        cout<<wl<<endl;
    }
}