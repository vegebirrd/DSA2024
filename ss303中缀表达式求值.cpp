#include <iostream>
#include <cstring>
#include <stack>
using namespace std;
string midtobehind(string mid){
    stack<char> s;
    string back;
    for (size_t i=0;i<mid.length();i++){
        char current=mid[i];
        if (current>='0'&&current<='9') back+=current;
        else if (current=='(') s.push(current);
        else if (current==')'){
            while (current!='('){
                current=s.top();
                s.pop();
                if(current!='('){
                    back+=' ';
                    back+=current;
                }
            }
        }
        else {
            back+=' ';
            while (!s.empty()&&s.top()!='('&&!((current=='/'||current=='*')&&(s.top()=='+'||s.top()=='-'))){
                back=back+s.top();
                s.pop();
            }
            s.push(current);
        }
    }
    while (!s.empty()){
        if (s.top()!='('){
            back+=' ';
            back+=s.top();
        }
        s.pop();
    }
    return back;
}
int calculate(string back){
    stack<int> s;
    int result=0;
    bool isnum=false;
    string tmp;
    for (size_t i=0;i<back.length();i++){
        if (back[i]>='0'&&back[i]<='9'){
            isnum=true;
            tmp+=back[i];
        }
        else if (back[i]==' '&&isnum){
            int num=stoi(tmp);
            tmp.clear();
            s.push(num);
            isnum=false;
        }
        else if (back[i]==' ') continue;
        else{
            isnum=false;
            char op=back[i];
            int num1,num2;
            num1=s.top();
            s.pop();
            num2=s.top();
            s.pop();
            switch (op){
                case '+':
                    result=num2+num1;
                    s.push(result);
                    break;
                case '-':
                    result=num2-num1;
                    s.push(result);
                    break;
                case '*':
                    result=num2*num1;
                    s.push(result);
                    break;
                case '/':
                    result=num2/num1;
                    s.push(result);
                    break;
            }
        }
    }
    result=s.top();
    return result;
}
int main(){
    int n;
    cin>>n;
    string s;
    for (int i=0;i<n;i++){
        cin>>s;
        string b=midtobehind(s);
        int r=calculate(b);
        cout<<r<<endl;
    }
}