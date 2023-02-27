class Solution {
public:

/*
Algorithm : 
1) open wale parenthesis stack mai dalo
2 ) closed and open parenthesis valid hai kya dekho if closed parenthesis coming

*/

    unordered_map<char,int>um = {
        {'(',1},{'[',2},{'{',3},{')',-1},{']',-2},{'}',-3}
    };

    bool isValid(string s) {

        stack<char>st;
        
        for(int i=0;i<s.length();i++){
            char inComing = s[i];

            if(um[s[i]]>0){
                st.push(inComing);
            }
            else{
                if(st.empty()){
                    return false;
                }

                char top = st.top();

                if(um[top]+um[inComing]!=0){
                    return false;
                }
                st.pop();
            }
        }
        if(st.empty()){
            return true;
        }
        else{
            return false;
        }
    }
};
