#include <iostream>
using namespace std;
int currentlen[60000];
long long totallen[60000];
int main(){
    int l=1;
    int k=10;
    totallen[1]=1;
    currentlen[1]=1;
    for (int i=2;i<60000;i++){
        if (i%k==0){
            l+=1;
            k*=10;
        }
        currentlen[i]=currentlen[i-1]+l;
        totallen[i]=totallen[i-1]+currentlen[i];
    }
    int t;
    cin>>t;
    for (int j=0;j<t;j++){
        int pos;
        cin>>pos;
        if (pos==1) cout<<1;
        else{
        int s;
        for (int i=1;i<59999;i++){
            if (totallen[i]<pos&&totallen[i+1]>=pos){
                s=i;
                break;
            }
        }
        pos-=totallen[s];
        int num=1;
        int leng=1;
        int a=10;
        while (pos>0){
            if (num%a==0){
                a*=10;
                leng++;
            }
            pos-=leng;
            num++;
        }
        num-=1;
        pos+=leng;
        int p=leng-pos;
        int ret;
        for (int i=0;i<p;i++){
            num=num/10;
        }
        ret=num%10;
        cout<<ret;
        }
        if (j!=t-1) cout<<endl;
    }
}