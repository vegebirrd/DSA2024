#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
int main(){
    int k;
    cin>>k;
    for (int i=0;i<k;i++){
        int n;
        cin>>n;
        vector<int> b(n+1),e(n+1),change(n+1);
        for (int i=1;i<=n;i++){
            cin>>b[i];
        }
        for (int i=1;i<=n;i++){
            cin>>e[i];
        }
        for (int i=1;i<=n;i++){
            change[i]=(e[i]-b[i])%2;
        }
        int p1,p2;
        int conn[31][31]={0};
        while(cin>>p1>>p2){
            if (p1==0) break;
            else conn[p2][p1]=1;
        }
        for (int i=1;i<=n;i++){
            conn[i][i]=1;
            conn[i][n+1]=change[i];
        }
        int row=1,col=1;
        int free_variable=0;
        bool possible=true;
        while (row<=n&&col<=n){
            /*找主元*/
            int pivot=row;
            while(conn[pivot][col]==0&&pivot<=n) pivot++;
            if (pivot>n){
                free_variable++;
                col++;
                continue;
            }
            /*交换当前行与主元行*/
            for (int i=1;i<=n+1;i++){
                swap(conn[row][i],conn[pivot][i]);
            }
            /*消元*/
            for (int i=1;i<=n;i++){
                if (i!=row&&conn[i][col]==1){
                    for (int j=col;j<=n+1;j++){
                        conn[i][j]=(conn[row][j]+conn[i][j])%2;
                    }
                }
            }
            row++;
            col++;
        }
        /*遍历看可不可能实现*/
        for (int i=n;i>=1;i--){
            bool all_zero=true;
            for (int j=1;j<=n;j++){
                if (conn[i][j]!=0){
                    all_zero=false;
                    break;
                }
            }
            if (all_zero&&conn[i][n+1]==1) possible=false;
        }
        if (possible) cout<<(1<<free_variable)<<endl; /*这里注意不能用pow，因为pow返回的是浮点，精度有问题*/
        else cout<<"Oh,it's impossible~!!"<<endl;
    }
}