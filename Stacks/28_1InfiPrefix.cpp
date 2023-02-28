#include<bits/stdc++.h>


using namespace std;

int prec(char ch){
    if(ch=='+' || ch=='-'){
        return 1;
    }
    else if(ch=='*' || ch=='/'){
        return 2;
    }
    else if(ch=='^'){
        return 3;
    }
    else{
        return -1;
    }
}

void infixPrefix(string &str){
        string res ="";

        stack<char>st;

        for(int i=0;i<str.size();i++){
            char ch = str[i];

            if(ch>='a' && ch<='z' || ch>='A' && ch<='Z'){
                res+=ch;
            }
            else if(ch==')'){
                st.push(ch);
            }
            else if(ch=='('){
              while(!st.empty() && st.top()!=')'){
                res+=st.top();
                st.pop();
              }
              st.pop();
            }
            else{
                while(!st.empty() && prec(ch)<prec(st.top())){
                    res+=st.top();
                    st.pop();
                }
                st.push(ch);
            }

        }

        while(!st.empty()){
            res+=st.top();
            st.pop();
        }


        reverse(res.begin(),res.end());

        cout<<"\nPrefix String : "<<res<<endl;
}

int main(){

    string str;
    cout<<"\nEnter infix string : ";
    cin>>str;

    cout<<"\nGiven String : "<<str<<endl;

    reverse(str.begin(),str.end());

    infixPrefix(str);

return 0;
}
