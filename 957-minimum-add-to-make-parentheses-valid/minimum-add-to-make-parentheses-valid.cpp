class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0;
        int close = 0;
        int cnt = 0;
        // ()))((
        stack<char>st;

        for(auto ch:s){
            if(ch=='('){
                st.push(ch);
            }
            else{
                if(st.empty()){
                    cnt++;
                }
                else{
                    st.pop();
                }
            } 
        }

        return cnt+st.size();
    }
};