//{ Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to convert an infix expression to a postfix expression.
    
    int prec(char ch){
        
        if(ch=='^'){
            return 3;
        }
        else if(ch=='*'||ch=='/'){
            return 2;
        }else if(ch=='+'||ch=='-'){
            return 1;
        }else{
            return -1;
        }
    }
    
    string infixToPostfix(string str) {
        
        string res ="";
        stack<char>st;
    
        
        
        int n= str.size();
        
        for(int i=0;i<n;i++){
            
            if(str[i]>='a' && str[i]<='z' || str[i]>='A' && str[i]<='Z' || str[i]>='0' && str[i]<='9'){ // if any operand then print out that
                res+=str[i];
            }
            else if(str[i]=='('){ // if opening bracket then push into stack
                st.push(str[i]);
            }
            else if(str[i]==')' && !st.empty()){
                
                while(st.top()!='(' && !st.empty()){
                    res+=st.top();
                    st.pop();
                }
                
                    st.pop(); // open bracket delete kar do
            }
            else{
                
                while(!st.empty() && prec(str[i])<=prec(st.top())){
                    res+=st.top();
                    st.pop();
                }
                st.push(str[i]);
            }
        }
        
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        
        return res;
    }
};


//{ Driver Code Starts.
// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;
    }
    return 0;
}

// } Driver Code Ends
