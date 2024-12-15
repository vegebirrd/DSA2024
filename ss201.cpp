#include <iostream>
using namespace std;
int ways(int apple,int plate){
    if (apple==0 || plate==1||apple==1){
        return 1;
    }
    else if (apple<plate){
        return ways(apple,apple);
    }
    else{
        return ways(apple-plate,plate)+ways(apple,plate-1);
    }
}
int main(){
    int m,n,t;
    cin>>t;
    for (int i=0;i<t;i++){
        cin>>m>>n;
        cout<<ways(m,n)<<endl;
    }
    return 0;
}