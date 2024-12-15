#include <iostream>
using namespace std;
int huanfang[45][45];
int main(){
    int n;
    int x=1;
    cin>>n;
    int y=n;
    int a=2*n-1;
    int s=a*a;
    for (int i=1;i<=s;i++){
        huanfang[x][y]=i;
        if (x==1&&y==2*n-1) x+=1;
        else if(huanfang[x-1][y+1]!=0) x+=1;
        else if(x==1){
            x=2*n-1;
            y+=1;
        }
        else if (y==2*n-1){
            x-=1;
            y=1;
        }
        else {
            x-=1;
            y+=1;
        }
    }
    for (int i=1;i<=a;i++){
        for (int j=1;j<=a;j++){
            cout<<huanfang[i][j];
            if (j!=a) cout<<' ';
        }
        if (i!=a) cout<<endl;
    }
}