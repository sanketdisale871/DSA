class Solution {
public:
    string makeGood(string s) {
       stack<char>st;

       for(auto ch:s){
            if(st.empty()){
                st.push(ch);
            }
            else if(isupper(ch)){
                if(!st.empty() && islower(st.top())){
                    char t = toupper(st.top());

                    if(t==ch){
                        st.pop();
                    }
                    else{
                        st.push(ch);
                    }
                }
                else{
                    st.push(ch);
                }
            }
            else{
                if(!st.empty() && isupper(st.top())){
                    char t = tolower(st.top());

                    if(t==ch){
                        st.pop();
                    }
                    else{
                        st.push(ch);
                    }
                }
                else{
                    st.push(ch);
                }
            }
       } 

       string str;

       while(!st.empty()){
        str.push_back(st.top());st.pop();
       }

       reverse(str.begin(),str.end());

       return str;
    }
};