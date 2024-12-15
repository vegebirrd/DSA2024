#include <iostream>
using namespace std;
int a[1000006];
int q[1000006];  //一个deque，存下标
void getmin(int n,int k){
    int head=0,tail=-1;
    for (int i=0;i<n;i++){//维护一个head为最小值的deque
        if (head<=tail&&q[head]<=i-k) head++; //有元素并且head指向的元素出窗口了
        while (head<=tail&&a[i]<=a[q[tail]]) tail--; //如果尾端都更大，尾端元素移出队列
        q[++tail]=i; //放到队尾
        if (i==k-1) cout<<a[q[head]];
        else if (i>k-1) cout<<' '<<a[q[head]];
    }
    cout<<endl;
}
void getmax(int n,int k){
    int head=0,tail=-1;
    for (int i=0;i<n;i++){//维护一个head为最小值的deque
        if (head<=tail&&q[head]<=i-k) head++; //有元素并且head指向的元素出窗口了
        while (head<=tail&&a[i]>=a[q[tail]]) tail--; //如果尾端都更小，尾端元素移出队列
        q[++tail]=i;
        if (i==k-1) cout<<a[q[head]];
        else if (i>k-1) cout<<' '<<a[q[head]];
    }
}
int main(){
    int n,k;
    cin>>n>>k;
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    getmin(n,k);
    getmax(n,k);
}