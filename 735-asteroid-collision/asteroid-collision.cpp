class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        vector<int>ans;

        stack<int>st;

        vector<int>temp;

        for(int i=ast.size()-1;i>=0;i--){
            if(ast[i]<0){
                st.push(abs(ast[i]));
            }
            else{
                if(!st.empty() && st.top()==ast[i]){
                    st.pop();
                    continue;
                }
                while(!st.empty() && st.top()<ast[i]){
                    st.pop();
                }
                if(!st.empty() && st.top()==ast[i]){
                    st.pop();
                    continue;
                }
                
                if(st.empty()){
                    temp.push_back(ast[i]);
                }
            }
        }

        while(!st.empty()){
            ans.push_back(-(st.top()));st.pop();
        }

        reverse(temp.begin(),temp.end());

        for(auto it:temp){
            ans.push_back(it);
        }

        return ans;
    }
};