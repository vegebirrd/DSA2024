//注意STL中unordered_set和unordered_map是哈希表存储的。注意插入和查找怎么做，特别是查找，要用迭代器。
//思路：把等式拆成两半
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;
int main(){
    int a1,a2,a3,a4,a5;
    int cnt=0;
    cin>>a1>>a2>>a3>>a4>>a5;
    unordered_map<int,int> hash_table;
    for (int i=-50;i<=50;i++){
        if (i==0) continue;
        for (int j=-50;j<=50;j++){
            if (j==0) continue;
            for (int k=-50;k<=50;k++){
                if (k==0) continue;
                int tmp=a1*i*i*i+a2*j*j*j+a3*k*k*k;
                hash_table[tmp]++;
            }
        }
    }
    for (int i=-50;i<=50;i++){
        if (i==0) continue;
        for (int j=-50;j<=50;j++){
            if (j==0) continue;
            int tmp=a4*i*i*i+a5*j*j*j;
            auto it=hash_table.find(-tmp);
            if (it!=hash_table.end()) cnt+=hash_table[-tmp];
        }
    }
    cout<<cnt<<endl;
}