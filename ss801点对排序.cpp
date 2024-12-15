//复习本题，注重运算符重载怎么写，特别是<<，要声明友元
//注意冒泡排序的稳定性
//注意冒完一轮泡哪个点是已经排好序的
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;
double dist(int x1,int x2,int x3,int y1,int y2,int y3){
    return sqrt((x1-y1)*(x1-y1)+(x2-y2)*(x2-y2)+(x3-y3)*(x3-y3));
}
class dot{
    public:
    int x1,x2,x3;
    dot(int x1,int x2,int x3):x1(x1),x2(x2),x3(x3){}
};
class c{
    public:
    dot a,b;
    double d;
    c(const dot& a, const dot& b):a(a),b(b){
        d=dist(a.x1,a.x2,a.x3,b.x1,b.x2,b.x3);
    }
    friend std::ostream& operator<<(std::ostream& os, const c& obj){
        os<<'('<<obj.a.x1<<','<<obj.a.x2<<','<<obj.a.x3<<")-("<<obj.b.x1<<','<<obj.b.x2<<','<<obj.b.x3<<")=";
        return os;
    }
};
vector<dot> dots;
vector<c> dotpair;
int main(){
    int n,x1,x2,x3;
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>x1>>x2>>x3;
        dots.push_back(dot(x1,x2,x3));
    }
    for (int i=0;i<n;i++){
        for (int j=i+1;j<n;j++){
            dotpair.push_back(c(dots[i],dots[j]));
        }
    }
    int pairnum=n*(n-1)/2;
    for (int i=0;i<pairnum;i++){
        for (int j=0;j<pairnum-1-i;j++){
            if (dotpair[j].d<dotpair[j+1].d){
                c tmp=dotpair[j];
                dotpair[j]=dotpair[j+1];
                dotpair[j+1]=tmp;
            }
        }
    }
    for (int i=0;i<pairnum;i++){
        cout<<dotpair[i];
        cout<<fixed<<setprecision(2)<<dotpair[i].d;
        cout<<endl;
    }
}