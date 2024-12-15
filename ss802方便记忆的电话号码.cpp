#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;
int record[10000000];
string transform(const string& s){
    string tel;
    for (const char& c:s){
        switch (c){
            case '0':
                tel=tel+'0';
                break;
            case '1':
                tel=tel+'1';
                break;
            case '2':
            case 'A':
            case 'B':
            case 'C':
            case 'a':
            case 'b':
            case 'c':
                tel=tel+'2';
                break;
            case '3':
            case 'D':
            case 'E':
            case 'F':
            case 'd':
            case 'e':
            case 'f':
                tel=tel+'3';
                break;
            case '4':
            case 'G':
            case 'H':
            case 'I':
            case 'g':
            case 'h':
            case 'i':
                tel=tel+'4';
                break;
            case '5':
            case 'J':
            case 'K':
            case 'L':
            case 'j':
            case 'k':
            case 'l':
                tel=tel+'5';
                break;
            case '6':
            case 'M':
            case 'N':
            case 'O':
            case 'm':
            case 'n':
            case 'o':
                tel=tel+'6';
                break;
            case '7':
            case 'P':
            case 'R':
            case 'S':
            case 'p':
            case 'r':
            case 's':
                tel=tel+'7';
                break;
            case '8':
            case 'T':
            case 'U':
            case 'V':
            case 't':
            case 'u':
            case 'v':
                tel=tel+'8';
                break;
            case '9':
            case 'W':
            case 'X':
            case 'Y':
            case 'w':
            case 'x':
            case 'y':
                tel=tel+'9';
                break;
        }
    }
    return tel;
}
string num_2_tel(int num){
    string tel;
    int msk=1000000;
    for (int i=0;i<7;i++){
        int tmp=num/msk;
        num-=tmp*msk;
        msk/=10;
        tel+=('0'+tmp);
        if (i==2) tel+='-';
    }
    return tel;
}
int main(){
    int n;
    cin>>n;
    string tel;
    for (int i=0;i<n;i++){
        cin>>tel;
        string standard_tel=transform(tel);
        int telnum=stoi(standard_tel);
        record[telnum]++;
    }
    bool dup=false;
    for (int i=0;i<10000000;i++){
        if (record[i]!=0){
            if (record[i]>1){
                dup=true;
                cout<<num_2_tel(i)<<' '<<record[i]<<endl;
            }
        }
    }
    if (!dup) cout<<"No duplicates."<<endl;
}